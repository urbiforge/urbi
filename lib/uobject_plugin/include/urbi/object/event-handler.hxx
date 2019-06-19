/*
 * Copyright (C) 2010-2012, Gostai S.A.S.
 *
 * This software is provided "as is" without warranty of any kind,
 * either expressed or implied, including but not limited to the
 * implied warranties of fitness for a particular purpose.
 *
 * See the LICENSE file for more information.
 */

namespace urbi
{
  namespace object
  {
    inline
    EventHandler&
    EventHandler::operator<<(const stop_job_type& j)
    {
      stop_jobs_ << j;
      return *this;
    }

    inline
    rList
    EventHandler::payload()
    {
      return payload_;
    }

    inline
    rEvent
    EventHandler::source()
    {
      return source_;
    }

  }
}
