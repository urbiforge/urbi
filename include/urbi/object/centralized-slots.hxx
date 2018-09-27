/*
 * Copyright (C) 2009-2012, Gostai S.A.S.
 *
 * This software is provided "as is" without warranty of any kind,
 * either expressed or implied, including but not limited to the
 * implied warranties of fitness for a particular purpose.
 *
 * See the LICENSE file for more information.
 */

#ifndef OBJECT_CENTRALIZED_SLOTS_HXX
# define OBJECT_CENTRALIZED_SLOTS_HXX

# include <libport/containers.hh>
# include <iostream>

# include <urbi/object/object.hh>

namespace urbi
{
  namespace object
  {

    inline
    CentralizedSlots::CentralizedSlots()
    : size_(0)
    {
    }

    inline CentralizedSlots::iterator
    CentralizedSlots::begin(Object* owner)
    {
      return obj_index_.equal_range(owner).first;
    }

    inline CentralizedSlots::const_iterator
    CentralizedSlots::begin(const Object* owner)
    {
      return obj_index_.equal_range(const_cast<Object*>(owner)).first;
    }

    inline void
    CentralizedSlots::finalize(Object* owner)
    {
#if BOOST_VERSION <= 105500
      if (owner->slots_.size_)
        obj_index_.erase(owner);
#else
      // boost::multi_index_container with boost > 1.55 does not seem to support reentrency into erase,
      // so we remove this reentrency by appending objects to finalize into delayed_finalize_.
      // delayed_finalize_ is immediately handled so this should not have any impact on the language semantic.
      if (owner->slots_.size_)
      {
        if (in_finalize_)
        {
          delayed_finalize_.push_back(owner);
          return;
        }
        {
          libport::Finally finally;
          finally << libport::scoped_set(in_finalize_, true);
          obj_index_.erase(owner);
        }
        while (!delayed_finalize_.empty())
        {
          std::vector<Object*> copy;
          std::swap(copy, delayed_finalize_);
          for (auto o: copy)
          {
            finalize(o);
          }
        }
      }
#endif
    }

    inline CentralizedSlots::iterator
    CentralizedSlots::end(Object* owner)
    {
      return obj_index_.equal_range(owner).second;
    }

    inline CentralizedSlots::const_iterator
    CentralizedSlots::end(const Object* owner)
    {
      return obj_index_.equal_range(const_cast<Object*>(owner)).second;
    }

    inline Object*
    CentralizedSlots::get_owner(const q_slot_type& slot)
    {
      return slot.first.first;
    }

    static inline CentralizedSlots::q_slot_type
    content(Object* owner, libport::Symbol key,
            CentralizedSlots::value_type& value)
    {
      return CentralizedSlots::q_slot_type(
        CentralizedSlots::location_type(owner, key),
        value);
    }

    inline bool
    CentralizedSlots::set(Object* owner,
			  const key_type& key, value_type v, bool overwrite)
    {
      q_slot_type c = content(owner, key, v);
      std::pair<content_type::iterator, bool> p = content_->insert(c);
      if (p.second)
      {
        ++owner->slots_.size_;
        return true;
      }
      else if (overwrite)
      {
        content_->replace(p.first, c);
        return true;
      }
      else
        return false;
    }

    inline CentralizedSlots::value_type
    CentralizedSlots::get(const Object* owner, const key_type& key)
    {
      loc_index_type::iterator it = where(owner, key);
      if (it == content_->end())
        return 0;
      return it->second;
    }

    inline bool
    CentralizedSlots::erase(Object* owner, const key_type& key)
    {
      loc_index_type::iterator it = where(owner, key);
      if (it == content_->end())
	return false;
      loc_index_.erase(it);
      --owner->slots_.size_;
      return true;
    }

    inline bool
    CentralizedSlots::has(Object* owner, const key_type& key)
    {
      loc_index_type::iterator it = where(owner, key);
      return it != content_->end();
    }

    inline CentralizedSlots::loc_index_type::iterator
    CentralizedSlots::where(const Object* owner, const key_type& key)
    {
      return loc_index_.find(location_type(const_cast<Object*>(owner), key));
    }

  }
}

#endif
