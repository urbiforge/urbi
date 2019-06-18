// A Bison parser, made by GNU Bison 3.1.

// Positions for Bison parsers in C++

// Copyright (C) 2002-2015, 2018 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

/**
 ** \file /alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/position.hh
 ** Define the yy::position class.
 */

#ifndef YY_YY_ALPHA_HOME_BEARCLAW_PROJECTS_URBIREBORD_URBIFORGE_URBI_BUILD_SYS_LINUX_X86_64_SRC_PARSER_POSITION_HH_INCLUDED
# define YY_YY_ALPHA_HOME_BEARCLAW_PROJECTS_URBIREBORD_URBIFORGE_URBI_BUILD_SYS_LINUX_X86_64_SRC_PARSER_POSITION_HH_INCLUDED

# include <algorithm> // std::max
# include <iostream>
# include <string>

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif


namespace yy {
#line 56 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/position.hh" // location.cc:290
  /// Abstract a position.
  class position
  {
  public:
    /// Construct a position.
    explicit position (libport::Symbol* f = YY_NULLPTR,
                       unsigned l = 1u,
                       unsigned c = 1u)
      : filename (f)
      , line (l)
      , column (c)
    {}


    /// Initialization.
    void initialize (libport::Symbol* fn = YY_NULLPTR,
                     unsigned l = 1u,
                     unsigned c = 1u)
    {
      filename = fn;
      line = l;
      column = c;
    }

    /** \name Line and Column related manipulators
     ** \{ */
    /// (line related) Advance to the COUNT next lines.
    void lines (int count = 1)
    {
      if (count)
        {
          column = 1u;
          line = add_ (line, count, 1);
        }
    }

    /// (column related) Advance to the COUNT next columns.
    void columns (int count = 1)
    {
      column = add_ (column, count, 1);
    }
    /** \} */

    /// File name to which this position refers.
    libport::Symbol* filename;
    /// Current line number.
    unsigned line;
    /// Current column number.
    unsigned column;

  private:
    /// Compute max(min, lhs+rhs).
    static unsigned add_ (unsigned lhs, int rhs, int min)
    {
      return static_cast<unsigned>(std::max(min, static_cast<int>(lhs) + rhs));
    }
  };

  /// Add \a width columns, in place.
  inline position&
  operator+= (position& res, int width)
  {
    res.columns (width);
    return res;
  }

  /// Add \a width columns.
  inline position
  operator+ (position res, int width)
  {
    return res += width;
  }

  /// Subtract \a width columns, in place.
  inline position&
  operator-= (position& res, int width)
  {
    return res += -width;
  }

  /// Subtract \a width columns.
  inline position
  operator- (position res, int width)
  {
    return res -= width;
  }

  /** \brief Intercept output stream redirection.
   ** \param ostr the destination output stream
   ** \param pos a reference to the position to redirect
   */
  template <typename YYChar>
  std::basic_ostream<YYChar>&
  operator<< (std::basic_ostream<YYChar>& ostr, const position& pos)
  {
    if (pos.filename)
      ostr << *pos.filename << ':';
    return ostr << pos.line << '.' << pos.column;
  }


} // yy
#line 159 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/position.hh" // location.cc:290
#endif // !YY_YY_ALPHA_HOME_BEARCLAW_PROJECTS_URBIREBORD_URBIFORGE_URBI_BUILD_SYS_LINUX_X86_64_SRC_PARSER_POSITION_HH_INCLUDED
