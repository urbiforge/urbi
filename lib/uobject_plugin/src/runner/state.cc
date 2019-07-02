/*
 * Copyright (C) 2011-2012, Gostai S.A.S.
 *
 * This software is provided "as is" without warranty of any kind,
 * either expressed or implied, including but not limited to the
 * implied warranties of fitness for a particular purpose.
 *
 * See the LICENSE file for more information.
 */

// FIXME: remove these (frozen_set)
#include <urbi/kernel/userver.hh>
#include <runner/job.hh>

#include <runner/state.hh>

// define CAPTURE_GLOBAL
#include <urbi/object/global.hh>
#include <urbi/object/lobby.hh>
#include <urbi/object/location.hh>

#include <runner/state.hxx>

namespace runner
{

  // The call stack is a circular buffer.  Keep only that many most
  // recent items.
  enum { call_stack_capacity = 256 };

  State::State(rLobby lobby)
    : frozen_tag_cache_step_(0)
    , frozen_tag_cache_(false)
    , priority_cache_valid_(false)
    , priority_cache_(sched::UPRIO_DEFAULT)
    , frozen_(false)
    , tag_stack_()
    , scope_tags_()
    , call_stack_(call_stack_capacity)
    , stacks_(lobby)
    , lobby_(lobby)
    , redefinition_mode_(false)
    , void_error_(true)
    , innermost_node_(0)
    , current_exception_()
    , has_import_stack(true)
      // When creating a new stack, "this" is the current lobby.
  {
    if (runner::Job* r = ::kernel::server().getCurrentRunnerOpt())
      call_stack_ = r->state.call_stack_get();
    // Push a dummy scope tag, in case we do have an "at" at the
    // toplevel.
    create_scope_tag();
    apply_tag(lobby->tag_get());
    if (has_import_stack)
    {
      CAPTURE_GLOBAL(uobjects);
      import_stack.push_back(std::vector<rObject>());
      import_stack.back().push_back(uobjects);
      // Only required if we execute code without entering a scope.
      // It seems to be possible.
      import_stack_size.push_back(1);
    }
  }

  State::State(const State& base)
    : frozen_tag_cache_step_(0)
    , frozen_tag_cache_(false)
    , priority_cache_valid_(base.priority_cache_valid_)
    , priority_cache_(base.priority_cache_)
    , frozen_(false)
    , tag_stack_(base.tag_stack_)
    , scope_tags_()
    , call_stack_(base.call_stack_)
    , stacks_(base.lobby_)
    , lobby_(base.lobby_)
    , redefinition_mode_(base.redefinition_mode_)
    , void_error_(true)
    , innermost_node_(base.innermost_node_)
    , current_exception_()
    , has_import_stack(base.has_import_stack)
  {
    // Push a dummy scope tag, in case we do have an "at" at the
    // toplevel.
    create_scope_tag();
    import_stack = base.import_stack;
    import_captured = base.import_captured;
    import_stack_size = base.import_stack_size;
  }

  // Handle tags.

  size_t
  State::has_tag(const sched::Tag& tag, size_t max_depth) const
  {
    max_depth = std::min(max_depth, tag_stack_.size());
    for (size_t i = 0; i < max_depth; i++)
      if (tag_stack_[i]->value_get() == &tag)
	return i+1;
    return 0;
  }

  bool
  State::frozen() const
  {
    unsigned long current_step = sched::Tag::get_step_number();
    if (current_step == frozen_tag_cache_step_)
      return frozen_tag_cache_ || frozen_;
    frozen_tag_cache_step_ = current_step;

    foreach (const object::rTag& tag, tag_stack_)
      if (tag->value_get()->frozen())
      {
        frozen_tag_cache_ = true;
        return true;
      }
    frozen_tag_cache_ = false;
    return frozen_;
  }

  sched::prio_type
  State::priority() const
  {
    if (priority_cache_valid_)
      return priority_cache_;

    if (!tag_stack_.empty())
    {
      sched::prio_type prio = sched::UPRIO_MIN;
      foreach(const object::rTag& tag, tag_stack_)
        prio = std::max(prio, tag->value_get()->prio_get());
      priority_cache_ = prio;
    }
    else
      priority_cache_ = sched::UPRIO_DEFAULT;
    priority_cache_valid_ = true;
    return priority_cache_;
  }

  State::tag_stack_type
  State::tag_stack_get() const
  {
    tag_stack_type res;
    foreach (const object::rTag& tag, tag_stack_)
      if (!tag->value_get()->flow_control_get())
	res << tag;
    return res;
  }




  /// Call Stack

  State::backtrace_type
  State::backtrace_get() const
  {
    CAPTURE_GLOBAL(StackFrame);
    backtrace_type res;
    // We need to create StackFrame objects while iterating, which
    // will modify the call stack, so make a copy.
    call_stack_type copy = call_stack_;
    foreach (call_type c, copy)
    {
      rObject loc = object::nil_class;
      if (c.second)
        loc = new object::Location(c.second.get());
      rObject frame =
        StackFrame->call("new", new object::String(c.first.name_get()), loc);
      res << call_frame_type(frame);
    }
    return res;
  }

  void
  State::cleanup()
  {
    tag_stack_.clear();
    scope_tags_.clear();
    call_stack_.clear();
    stacks_.cleanup();
  }

} // namespace runner
