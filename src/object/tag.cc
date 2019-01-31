/*
 * Copyright (C) 2008-2012, Gostai S.A.S.
 *
 * This software is provided "as is" without warranty of any kind,
 * either expressed or implied, including but not limited to the
 * implied warranties of fitness for a particular purpose.
 *
 * See the LICENSE file for more information.
 */

/**
 ** \file object/tag.cc
 ** \brief Creation of the Urbi object tag.
 */

#include <urbi/kernel/userver.hh>

#include <urbi/object/tag.hh>
#include <urbi/object/global.hh>
#include <urbi/object/object.hh>
#include <urbi/object/string.hh>
#include <urbi/object/symbols.hh>

#include <runner/job.hh>
#include <eval/call.hh>

#include <sched/tag.hh>

namespace urbi
{
  namespace object
  {
    Tag::Tag()
      : value_(new sched::Tag)
    {
      proto_add(proto ? rObject(proto) : Object::proto);
    }

    Tag::Tag(const value_type& value)
      : value_(value)
    {
      proto_add(proto);
    }

    Tag::Tag(rTag model)
      : value_(new sched::Tag)
    {
      proto_add(model);
      if (model.get() != proto.get())
        parent_ = model;
    }

    URBI_CXX_OBJECT_INIT(Tag)
      : value_(new sched::Tag)
    {
#define DECLARE(Name, Arg)                      \
      BIND(Name, Name, void, (Arg))

      DECLARE(init, );
      DECLARE(init,  const std::string&);
      DECLARE(stop, );
      DECLARE(stop,  rObject);
      DECLARE(block, );
      DECLARE(block, rObject);

#undef DECLARE

      BIND_VARIADIC(newFlowControl, new_flow_control);

      BINDG(blocked);
      BINDG(enter);
      BIND(freeze);
      BIND(frize, freeze);
      BINDG(frozen);
      BIND(getParent, parent_get);
      BINDG(leave);
      BIND(priority);
      BINDG(scope);
      BIND(setPriority, priority_set);
      BIND(unblock);
      BIND(unb, unblock);
      BIND(unfreeze);
    }

    Tag::value_type&
    Tag::value_get()
    {
      return value_;
    }

    const Tag::value_type&
    Tag::value_get() const
    {
      return value_;
    }

    void
    Tag::block()
    {
      block(void_class);
    }

    void
    Tag::block(rObject payload)
    {
      value_->block(::kernel::server().scheduler_get(), payload);
      // changed();
    }

    void
    Tag::freeze()
    {
      runner::Job& r = ::kernel::runner();

      value_->freeze(::kernel::server().scheduler_get());
      // changed();
      if (r.frozen())
        r.yield();
    }


    void Tag::name_set(const std::string& name)
    {
      if (!local_slot_get_value(SYMBOL(name)))
        slot_set_value(SYMBOL(name), object::to_urbi(name));
      else
        slot_update(SYMBOL(name), object::to_urbi(name));
    }

    const std::string
    Tag::name() const
    {
      if (rObject s = local_slot_get_value(SYMBOL(name)))
        return s->as<object::String>()->value_get();
      return "Tag";
    }

    void
    Tag::init()
    {
      init(libport::fresh_string("tag"));
    }

    void
    Tag::init(const std::string& name)
    {
      name_set(name);
    }

    rTag
    Tag::new_flow_control(const objects_type& args)
    {
      // FIXME: new is now called on self instead of on proto.
      rTag res = args[0]->call_with_this(SYMBOL(new), args)->as<Tag>();
      res->value_get()->flow_control_set();
      return res;
    }

    Tag::priority_type
    Tag::priority_set(priority_type prio)
    {
      return value_->prio_set(::kernel::server().scheduler_get(), prio);
    }

    void
    Tag::stop()
    {
      stop(void_class);
    }

    void
    Tag::stop(rObject payload)
    {
      value_->stop(::kernel::server().scheduler_get(), payload);
      // changed();
    }

    void
    Tag::unblock()
    {
      value_->unblock(::kernel::server().scheduler_get());
      // changed();
    }

    void
    Tag::unfreeze()
    {
      value_->unfreeze(::kernel::server().scheduler_get());
      // changed();
    }

    static inline rObject
    tag_event(Tag* owner, libport::Symbol field)
    {
      if (rObject res = owner->local_slot_get_value(field))
        return res;

      CAPTURE_GLOBAL(Event);
      rObject evt = Event->call(SYMBOL(new));
      owner->slot_set_value(field, evt);
      return evt;
    }

    rObject
    Tag::enter()
    {
      return tag_event(this, SYMBOL(enterEvent));
    }

    rObject
    Tag::leave()
    {
      return tag_event(this, SYMBOL(leaveEvent));
    }

    void
    Tag::triggerEnter()
    {
      if (rObject f = local_slot_get_value(SYMBOL(onEnter)))
      {
        objects_type args;
        args << this;
        eval::call_apply(::kernel::runner(),
                         f, SYMBOL(onEnter), args);
      }
      if (rObject ev = local_slot_get_value(SYMBOL(enterEvent)))
        ev->call(SYMBOL(syncEmit));
    }

    void
    Tag::triggerLeave()
    {
      if (rObject f = local_slot_get_value(SYMBOL(onLeave)))
      {
        objects_type args;
        args << this;
        eval::call_apply(::kernel::runner(),
                         f, SYMBOL(onLeave), args);
      }
      if (rObject o = local_slot_get_value(SYMBOL(leaveEvent)))
        o->call(SYMBOL(syncEmit));
    }

    rTag
    Tag::parent_get()
    {
      return parent_;
    }

    rTag
    Tag::scope()
    {
      runner::Job& r = ::kernel::runner();
      return new Tag(r.state.scope_tag(r.scheduler_get()));
    }

    bool
    Tag::frozen() const
    {
      return value_->frozen();
    }

    bool
    Tag::blocked() const
    {
      return value_->blocked();
    }
  } // namespace object
}
