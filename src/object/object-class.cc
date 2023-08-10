/*
 * Copyright (C) 2007-2012, Gostai S.A.S.
 *
 * This software is provided "as is" without warranty of any kind,
 * either expressed or implied, including but not limited to the
 * implied warranties of fitness for a particular purpose.
 *
 * See the LICENSE file for more information.
 */

/**
 ** \file urbi/object/object.class.cc
 ** \brief Creation of the Urbi object object.
 */

#include <libport/bind.hh>
#include <libport/format.hh>

#include <libport/compiler.hh>
#include <libport/containers.hh>
#include <libport/escape.hh>
#include <libport/foreach.hh>
#include <libport/tokenizer.hh>

#include <urbi/kernel/uconnection.hh>
#include <urbi/kernel/userver.hh>
#include <object/object-class.hh>
#include <urbi/object/symbols.hh>
#include <runner/job.hh>
#include <urbi/object/cxx-primitive.hh>
#include <urbi/object/dictionary.hh>
#include <urbi/object/event.hh>
#include <urbi/object/float.hh>
#include <urbi/object/global.hh>
#include <urbi/object/hash.hh>
#include <urbi/object/list.hh>
#include <urbi/object/object.hh>
#include <urbi/object/string.hh>
#include <urbi/runner/raise.hh>

#include <eval/send-message.hh>
#include <eval/call.hh>
#include <eval/ast.hh>


namespace urbi
{
  namespace object
  {
    /*--------------------.
    | Object primitives.  |
    `--------------------*/

    static rObject
    object_class_clone(const objects_type& args)
    {
      check_arg_count(args, 0);
      return args[0]->clone();
    }

    static rObject
    object_class_init(const objects_type& args)
    {
      check_arg_count(args, 0);
      return args[0];
    }

    /// Send dumped self on the connection.
    /// args[1], if present, can be the tag to use.
    static rObject
    object_class_dump(const objects_type& args)
    {
      runner::Job& r = ::kernel::runner();

      check_arg_count(args, 1, 2);

      // Second argument is max depth.
      int depth_max = 0;
      if (2 <= args.size())
      {
        const rFloat& arg1 = from_urbi<rFloat>(args[1], 1u);
        try
        {
          depth_max = libport::numeric_cast<int>(arg1->value_get());
        }
        catch (libport::bad_numeric_cast& ue)
        {
          runner::raise_bad_integer_error(arg1->value_get());
        }
      }

      // Third argument is the tag name.
      std::string tag;
      if (3 <= args.size())
      {
        const rString& arg2 = from_urbi<rString>(args[2], 2u);
        aver(arg2);
        tag = arg2->value_get();
      }

      // Do not use libport::lines on os.str().
      std::string dump;
      {
        std::ostringstream os;
        args[0]->dump(os, depth_max);
        dump = os.str();
      }
      // For now our best choice is to dump line by line in "system" messages.
      const std::string system_header("*** ");
      foreach (const std::string& line, libport::lines(dump))
        eval::send_message(r, tag, system_header + line);
      return void_class;
    }

    /// Structural equality
    static rObject
    object_class_EQ_EQ(const objects_type& args)
    {
      // Unless overridden, structural equality is physical equality.
      check_arg_count(args, 1);
      return args[0]->call(SYMBOL(EQ_EQ_EQ), args[1]);
    }

    /// Physical equality
    static rObject
    object_class_EQ_EQ_EQ(const objects_type& args)
    {
      check_arg_count(args, 1);
      return to_boolean(args[0] == args[1]);
    }

    static rObject
    object_class_apply(rObject self, const objects_type& args)
    {
      unsigned nargs = args.size();
      if (nargs != 1)
        runner::raise_arity_error(nargs, 1);
      return self;
    }

    static rObject
    object_class_callMessage (rObject target, rObject call_message)
    {
      DECLARE_LOCATION_FILE;
      runner::Job& r = ::kernel::runner();

      // We need to set the 'code' slot: make a copy of the call message.
      const rObject& message = call_message->slot_get_value(SYMBOL(message));
      const libport::Symbol msg(from_urbi<std::string>(message));
      // We have to try the import stack on msg.
      rObject code;
      object::Object::location_type loc =  target->slot_locate(msg);
      if (loc.first) // Refetch or we bypass dependency tracker.
        code = target->slot_get_value(msg);
      else
      {
        loc = eval::import_stack_lookup(r.state, msg, target);
        code = loc.second;
        if (object::rSlot sl = code->as<object::Slot>())
          code = sl->value(target);
      }

      call_message->slot_update(SYMBOL(code), code);
      call_message->slot_update(SYMBOL(target), target);
      // FIXME: Sanity checks on the call message are probably required
      return eval::call_msg(r, code, msg, call_message, LOCATION_HERE);
    }

    /*---------.
    | Protos.  |
    `---------*/

    /// Get protos' list.
    static rObject
    object_class_protos (const objects_type& args)
    {
      check_arg_count(args, 0);
      return args[0]->urbi_protos_get ();
    }

    /// Add a prototype
    static bool
    proto_add(List::value_type& protos, const rObject& proto)
    {
      protos.push_back(proto);
      return false;
    }

    /// Recursively get protos list
    static rObject
    object_class_allProtos(const objects_type& args)
    {
      check_arg_count(args, 0);
      List::value_type res;
      for_all_protos(args[0], boost::bind(&proto_add, boost::ref(res), _1));
      return new List(res);
    }


    /*--------.
    | Slots.  |
    `--------*/

    template <typename F>
    static inline void for_all_slot_names(const rObject& o, F f)
    {
      for (Object::slots_implem::iterator slot = o->slots_get().begin(o.get());
           slot != o->slots_get().end(o.get());
           ++slot)
        f(slot->first.second);
    }

    static void
    add_as_rString(List::value_type& l, libport::Symbol slot_name)
    {
      l.push_back(new String(slot_name));
    }

    /// List of slot names.
    static rObject
    object_class_localSlotNames(const objects_type& args)
    {
      check_arg_count(args, 0);
      const rObject& obj = args[0];

      List::value_type l;
      for_all_slot_names(obj, boost::bind(&add_as_rString, boost::ref(l), _1));
      return new List(l);
    }

    /// Recursive list of slot names.
    static void
    maybe_add(std::vector<libport::Symbol>& control, List::value_type& l,
              libport::Symbol slot_name)
    {
      if (!libport::has(control, slot_name))
      {
        control.push_back(slot_name);
        l.push_back(new String(slot_name));
      }
    }

    static rObject
    object_class_slotNames(const objects_type& args)
    {
      check_arg_count(args, 0);
      std::vector<libport::Symbol> slot_names;
      List::value_type res;
      objects_type protos =
        object_class_allProtos(args)->as<List>()->value_get();
      foreach (const rObject& proto, protos)
      {
        for_all_slot_names(proto, boost::bind(&maybe_add,
                                              boost::ref(slot_names),
                                              boost::ref(res),
                                              _1));
      }
      return new List(res);
    }

    static bool
    object_class_isA(rObject self, rObject proto)
    {
      return is_a(self, proto);
    }

#define OPERATOR(Name)                                          \
    static rObject                                              \
    object_class_ ## Name ## _EQ(rObject lhs, rObject rhs)      \
    {                                                           \
      return lhs->call(SYMBOL_(Name), rhs);                     \
    }

    OPERATOR(CARET)
    OPERATOR(MINUS)
    OPERATOR(PERCENT)
    OPERATOR(PLUS)
    OPERATOR(SLASH)
    OPERATOR(STAR)
#undef OPERATOR

    static rObject
    object_class_PLUS_PLUS(rObject lhs)
    {
      /*static*/ rObject one = to_urbi(1);
      return lhs->call(SYMBOL(PLUS_EQ), one);
    }

    static rObject
    object_class_MINUS_MINUS(rObject lhs)
    {
      /*static*/ rObject one = to_urbi(1);
      return lhs->call(SYMBOL(MINUS_EQ), one);
    }

    static rObject
    object_class_dollarGetSlot(rObject tgt, libport::Symbol name)
    {
      return tgt->slot_get(name);
    }

    static rObject
    object_class_dollarSetSlot(rObject tgt, libport::Symbol name, rSlot slot)
    {
      tgt->slot_set(name, slot.get());
      return slot;
    }

    void
    object_class_initialize()
    {
      Object::proto->slot_set_value(SYMBOL(isA),
                              primitive(object_class_isA));
      Object::proto->slot_set_value(SYMBOL(hasLocalSlot),
                              primitive(&Object::hasLocalSlot));

#define DECLARE(Name)                                                   \
      Object::proto->slot_set_value(SYMBOL_(Name),                      \
                              new Primitive(object_class_##Name),       \
                              true)

      DECLARE(EQ_EQ);
      DECLARE(EQ_EQ_EQ);
      DECLARE(allProtos);
      DECLARE(clone);
      DECLARE(dump);
      DECLARE(init);
      DECLARE(localSlotNames);
      DECLARE(protos);
      DECLARE(slotNames);
#undef DECLARE

#define DECLARE(Name, Code)                                             \
      Object::proto->slot_set_value(SYMBOL_(Name), primitive(Code))

      DECLARE(DOLLAR_getSlot     , object_class_dollarGetSlot);
      DECLARE(DOLLAR_setSlot     , object_class_dollarSetSlot);
      DECLARE(CARET_EQ           , object_class_CARET_EQ);
      DECLARE(MINUS_EQ           , object_class_MINUS_EQ);
      DECLARE(MINUS_MINUS        , object_class_MINUS_MINUS);
      DECLARE(PERCENT_EQ         , object_class_PERCENT_EQ);
      DECLARE(PLUS_EQ            , object_class_PLUS_EQ);
      DECLARE(PLUS_PLUS          , object_class_PLUS_PLUS);
      DECLARE(SLASH_EQ           , object_class_SLASH_EQ);
      DECLARE(STAR_EQ            , object_class_STAR_EQ);
      DECLARE(apply              , object_class_apply);
      DECLARE(asBool             , &Object::as_bool);
      DECLARE(asPrintable        , &Object::asPrintable);
      DECLARE(asTopLevelPrintable, &Object::asTopLevelPrintable);
      DECLARE(callMessage        , object_class_callMessage);
      // DECLARE(changed            , &Object::changed_get);
      DECLARE(createSlot         , &Object::urbi_createSlot);
      DECLARE(findSlot           , &Object::findSlot);
      DECLARE(getLocalSlot       , &Object::getLocalSlot);
      DECLARE(getLocalSlotValue  , &Object::getLocalSlotValue);
      DECLARE(getProperty        , &Object::property_get);
      typedef rObject (Object::*get_slot_type)(Object::key_type);
      DECLARE(getSlot            ,
              static_cast<get_slot_type>(&Object::getSlot));
      DECLARE(hasProperty        , &Object::property_has);
      DECLARE(hasSlot            , &Object::hasSlot);
      DECLARE(locateSlot         , &Object::urbi_locateSlot);
      DECLARE(properties         , &Object::urbi_properties);
      DECLARE(removeProperty     , &Object::property_remove);
      DECLARE(removeLocalSlot    , &Object::urbi_removeLocalSlot);
      DECLARE(removeSlot         , &Object::urbi_removeSlot);
      DECLARE(setConstSlotValue  , &Object::urbi_setConstSlotValue);
      DECLARE(setProperty        , &Object::property_set);
      typedef rObject (Object::*set_slot_type)(Object::key_type,
                                               const rObject&);
      DECLARE(setSlot            ,
              static_cast<set_slot_type>(&Object::setSlot));
      DECLARE(updateSlot         , &Object::urbi_updateSlot);
      DECLARE(setSlotValue       , &Object::setSlotValue);
      DECLARE(getSlotValue       , &Object::getSlotValue);
#undef DECLARE

      Object::proto->bind(SYMBOL(uid),          &Object::uid);
      Object::proto->bind(SYMBOL(slotAdded),    &Object::slotAdded_get);
      Object::proto->bind(SYMBOL(slotRemoved),  &Object::slotRemoved_get);
      Object::proto->bind(SYMBOL(refCount),     &Object::counter_get);
      Object::proto->bind(SYMBOL(addProto),     &Object::addProto);
      Object::proto->bind(SYMBOL(hash),         &Object::hash);
      Object::proto->bind(SYMBOL(removeProto),  &Object::removeProto);
      Object::proto->bind_variadic(SYMBOL(new), &Object::new_);
    }
  }; // namespace object
}
