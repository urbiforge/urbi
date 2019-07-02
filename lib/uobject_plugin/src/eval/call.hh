/*
 * Copyright (C) 2011-2012, Gostai S.A.S.
 *
 * This software is provided "as is" without warranty of any kind,
 * either expressed or implied, including but not limited to the
 * implied warranties of fitness for a particular purpose.
 *
 * See the LICENSE file for more information.
 */

/**
 ** \file runner/eval/call.hh
 ** \brief Definition of eval::call.
 */

#ifndef EVAL_CALL_HH
# define EVAL_CALL_HH

# include <eval/action.hh>
# include <eval/fwd.hh>

# include <ast/fwd.hh>
# include <ast/loc.hh>
# include <ast/exps-type.hh>

namespace eval
{

  Action  call(object::rObject function,
               const object::objects_type& args = object::objects_type());

  rObject call(Job& job,
               object::rObject function,
               const object::objects_type& args);

  /*
  Action  call(rObject this_,
               libport::Symbol msg,
               rObject code,
               const object::objects_type& args,
               boost::optional< ::ast::loc> loc);

  rObject call(Job& job,
               rObject target,
               libport::Symbol msg,
               rObject code,
               const object::objects_type& args,
               boost::optional< ::ast::loc> loc);
  */

  /*-----------------------------------------------------------------.
  | Apply with evaluated arguments, and potentially a call message.  |
  `-----------------------------------------------------------------*/

  Action  call_apply(object::rObject target,
                     object::rObject routine,
                     libport::Symbol message,
                     const object::objects_type& args = object::objects_type());

  rObject call_apply(Job& job,
                     object::rObject target,
                     object::rObject routine,
                     libport::Symbol message,
                     const object::objects_type& args);

  Action  call_apply(object::rObject function,
                     libport::Symbol msg,
                     const object::objects_type& args,
                     object::rObject call_message = 0);

  rObject call_apply(Job& job,
                     object::rObject function,
                     libport::Symbol msg,
                     const object::objects_type& args,
                     object::rObject call_message = 0);

  rObject call_apply(Job& job,
                     object::Object* function,
                     libport::Symbol msg,
                     const object::objects_type& args,
                     object::Object* call_message,
                     boost::optional< ::ast::loc> loc,
                     unsigned call_flags = 0);


  /*----------------------------.
  | Apply with a call message.  |
  `----------------------------*/

  rObject call_msg(Job& job,
                   object::Object* function,
                   libport::Symbol msg,
                   object::Object* call_message,
                   boost::optional< ::ast::loc> loc
                     = boost::optional< ::ast::loc>());

  /*-------------------------------------------------.
  | Apply an urbi function (i.e., not a primitive).  |
  `-------------------------------------------------*/

  rObject call_apply_urbi(Job& job,
                          object::Code* function,
                          libport::Symbol msg,
                          const object::objects_type& args,
                          object::Object* call_message_,
                          unsigned call_flags);

  rObject call_funargs(Job& job,
                       object::Code* function,
                       libport::Symbol msg,
                       const object::objects_type& args);

  /*-------------------------------------.
  | Apply with arguments as ast chunks.  |
  `-------------------------------------*/

  rObject call_msg(Job& job,
                   rObject target,
                   libport::Symbol message,
                   const ::ast::exps_type* arguments,
                   boost::optional< ::ast::loc> loc);

  rObject call_msg(Job& job,
                   object::Object* target,
                   object::Object* routine,
                   libport::Symbol message,
                   const ::ast::exps_type* input_ast_args,
                   boost::optional< ::ast::loc> loc);

  void
  strict_args(Job& job,
              object::objects_type& args,
              const ::ast::exps_type& exp_args);

  /** Lookup a symbol on the import stack, throw if not found.
  @param target will be set to the correct target if found.
  */
  std::pair<object::Object*, object::rObject>
  import_stack_lookup(const runner::State& state,
    libport::Symbol s, rObject& target, bool throwOnError = true);
} // namespace eval

#endif // ! EVAL_CALL_HH
