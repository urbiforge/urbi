/*
 * Copyright (C) 2010-2012, Gostai S.A.S.
 *
 * This software is provided "as is" without warranty of any kind,
 * either expressed or implied, including but not limited to the
 * implied warranties of fitness for a particular purpose.
 *
 * See the LICENSE file for more information.
 */

#ifndef OBJECT_POSITION_HH
# define OBJECT_POSITION_HH

# include <urbi/object/cxx-object.hh>
# include <parser/position.hh>

namespace urbi
{
  namespace object
  {

    class URBI_SDK_API Position: public CxxObject
    {
      URBI_CXX_OBJECT(Position, CxxObject);

    /*---------------.
    | Construction.  |
    `---------------*/

    public:
      typedef ::yy::position value_type;
      Position();
      Position(const value_type& pos);
      Position(libport::Symbol* f, unsigned int l, unsigned int c);
      Position(rPosition model);
      void init();
      void init(const value_type& pos);
      void init(unsigned from, unsigned to);
      void init(rObject file, unsigned from, unsigned to);

    /*--------------.
    | Comparisons.  |
    `--------------*/

    public:
      using Object::operator <;
      bool operator ==(rPosition rhs) const;
      bool operator <(rPosition rhs) const;

    /*-------------.
    | Operations.  |
    `-------------*/

    public:
      rPosition operator - (int rhs) const;
      rPosition operator + (int rhs) const;

      rPosition lines(int c);
      rPosition columns(int c);

    /*--------------.
    | Conversions.  |
    `--------------*/

    public:
      virtual std::string as_string() const;
      value_type& value_get();

    /*-----------.
    | Accessor.  |
    `-----------*/

    private:
      boost::optional<libport::path> file_get() const;
      void file_set(rObject o);

    /*----------.
    | Details.  |
    `----------*/

    private:
      value_type pos_;
    };

    bool
    operator ==(const Position::value_type& lhs,
                const Position::value_type& rhs);

    bool
    operator <(const Position::value_type& lhs,
               const Position::value_type& rhs);

    CONVERT_VALUE_TYPE(Position);

  } // namespace object
} // namespace urbi

#include <urbi/object/position.hxx>

#endif
