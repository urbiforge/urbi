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
 ** \file runner/job.hh
 ** \brief Definition of runner::Job.
 */

#include <urbi/object/slot.hh>
#ifndef RUNNER_JOB_HH
# define RUNNER_JOB_HH

// declare sched::Job
# include <sched/job.hh>

// declare runner::State
# include <runner/state.hh>

// declare object::*
# include <urbi/object/fwd.hh>
# include <object/profile.hh>

// declare evalution interface eval::Action
# include <eval/action.hh>

// Avoid post-declaration of runner::Job
# include <urbi/runner/fwd.hh>

// Register events used to watch for future changes of the evaluation
// result.  \a Name corresponds to an attribute which of the object
// accessible through an accessor Name_get().
#define URBI_AT_HOOK(Name)                                              \
  URBI_AT_HOOK_(Name##_get)
#define URBI_AT_HOOK_(accessor)                                         \
  do                                                                    \
  {                                                                     \
    if (runner::Job* r =                                                \
        ::kernel::urbiserver->getCurrentRunnerOpt())                    \
      if (r->dependencies_log_get())                                    \
      {                                                                 \
        try                                                             \
        {                                                               \
          r->dependencies_log_set(false);                               \
          GD_CATEGORY(Urbi.At);                                         \
          GD_FPUSH_TRACE("Register %s for at monitoring on %s", #accessor, \
                         this);                                         \
          rEvent e = accessor()->as<Event>();                           \
          r->dependencies_log_set(true);                                \
          r->dependency_add(e);                                         \
        }                                                               \
        catch (...)                                                     \
        {                                                               \
          r->dependencies_log_set(true);                                \
          throw;                                                        \
        }                                                               \
      }                                                                 \
  }                                                                     \
  while (false)

// Deactivate dependency tracking for the current scope
#define URBI_SCOPE_DISABLE_DEPENDENCY_TRACKER                          \
  runner::Job* usddt_j = ::kernel::urbiserver->getCurrentRunnerOpt();  \
  bool usddt_d = false;                                                \
  if (usddt_j)                                                         \
  {                                                                    \
    usddt_d = usddt_j->dependencies_log_get();                         \
    usddt_j->dependencies_log_set(false);                              \
  }                                                                    \
  FINALLY(((runner::Job*, usddt_j))((bool, usddt_d)),                  \
          if (usddt_j)                                                 \
           usddt_j->dependencies_log_set(usddt_d))

namespace runner
{
  using urbi::object::Profile;
  using urbi::object::FunctionProfile;

  /// Job is holding a common stack representation for all method of
  /// evaluations.  Method of evaluation could be Text evaluation, AST
  /// evaluation, or Byte code evaluation.
  class Job
    : public sched::Job
  {
  public:
    typedef sched::Job super_type;

    typedef object::Object Object;
    typedef object::rObject rObject;
    typedef object::rLobby rLobby;

    /// Create a job from another one.
    ///
    /// \param model The parent job. The scheduler and tags will be inherited
    //         from it.
    Job(const Job& model,
        size_t stack_size = 0);

    /// Create a new job.
    ///
    /// \param lobby The lobby attached to the current job.
    ///  If null, used the main Lobby.
    ///
    /// \param scheduler The scheduler to which this job will be attached.
    Job(rLobby lobby,
        sched::Scheduler& scheduler);

    /// Destroy a job and the action bound to it.
    virtual ~Job();

  public:

    /// urbiscript evaluation
    /// \{

    /// Urbiscript is evaluated in this function, whatever the
    /// representation used to store urbiscript sources.
    virtual void work();

    /// Return the result of the latest evaluation.
    /// FIXME: is that used ?!
    virtual rObject result_get();

    /// Get the current runner as an Urbi Job or nil if the job is
    /// terminated.
    object::rJob as_job();

    /// Signal a scheduling error exception.
    /// Implementation for abstract class sched::Job.
    ///
    /// \param msg The explanation of the scheduling error.
    virtual void scheduling_error(const std::string& msg);

    // Avoid cycle dependencies with cached objects.
    virtual void terminate_cleanup();

    /// \}


    /// Job status defined by Tags
    /// \{

    /// Inherited from sched::job.
    /// Bounce on the state to know if one tag is frozen.
    virtual bool frozen() const;

    /// Freeze the current job, without using any tag.
    void frozen_set(bool);
    bool frozen_get();

    /// Inherited from sched::job.
    /// Bounce on the state to know if the job has a specific tag.
    virtual size_t has_tag(const sched::Tag& tag,
			   size_t max_depth = (size_t)-1) const;
    bool has_tag(const object::rTag& tag) const;

    /// Inherited from sched::job.
    /// Bounce on the state to know the higest tag priority.
    virtual sched::prio_type prio_get() const;

    /// \}

    Job* name_set(const std::string& name);
    const std::string name_get() const;

    /// Job processing
    /// \{

    /// Create a new Job that inherits the current lobby and clone
    /// necessary stacks parts.  Define an action which would be
    /// executed by the child, and if a collector is specified, then
    /// the child is registered in the collector.
    ///
    /// This command return a child job which has to be started with
    /// 'start_job()' to execute the action asynchronously.
    Job* spawn_child(eval::Action action,
                     Job::Collector& collector,
                     size_t stack_size = 0);
    Job* spawn_child(eval::Action action,
                     size_t stack_size = 0);

    void set_action(eval::Action action);

    /// \}

    /// \name Profiling
    /// \{

    /// Start profiling into \a profile.
    /// profile_start should be used with profile_stop.
    void profile_start(Profile* profile, libport::Symbol name,
                       Object* current, bool count = false);
    /// Stop profiling.
    /// profile_stop should be used with profile_start.
    void profile_stop();

    /// Fork the profiling content of the parent
    /// profile_fork should be used with profile_join.
    void profile_fork(Job& parent);
    /// Append profiling content of a child.
    /// profile_join should be used with profile_fork.
    void profile_join(Job& child);

    ///
    Object* profile_enter(Object* function, libport::Symbol msg);
    ///
    void profile_leave(Object* idx);

    /// Wheter there is a profiling in run.
    bool is_profiling() const;

    /// The current profile to fill - if any.
    ATTRIBUTE_R(Profile*, profile);
  private:
    mutable Profile::Info profile_info_;

  protected:
    virtual void hook_preempted() const;
    virtual void hook_resumed() const;

    /// \}

    /// \name Dependencies tarcker
    /// \{

  public:
    typedef boost::unordered_set<object::rEvent> dependencies_type;
    dependencies_type& dependencies();
    bool dependencies_log_get() const;
    void dependencies_log_set(bool val);
    void dependency_add(object::rEvent evt);
    void dependency_add(object::rObject evt);
    void dependencies_clear();
  protected:
    bool dependencies_log_;
    dependencies_type dependencies_;

    /// \}

    /// \name sched::Job accessors
    /// \{
  public:
    // FIXME: should ensure that one job release the non-interruptible flag.
    bool non_interruptible_get() const;
    void non_interruptible_set(bool);

    /// \}

  public:
    State state;

  private:
    eval::Action worker_;
    rObject result_cache_;
    object::rJob job_cache_;
  };

} // namespace runner

#endif // ! RUNNER_JOB_HH
