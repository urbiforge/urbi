// A Bison parser, made by GNU Bison 3.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

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


// First part of user declarations.

#line 37 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:407

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "ugrammar.hh"

// User implementation prologue.

#line 51 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:415
// Unqualified %code blocks.
#line 62 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:416

#include <string>
#include <iostream>

#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>

#include <libport/cassert>
#include <libport/finally.hh>
#include <libport/format.hh>
#include <libport/separate.hh>

#include <ast/all.hh>
#include <ast/new-clone.hh>
#include <ast/parametric-ast.hh>
#include <ast/print.hh>

#include <parser/parse.hh>
#include <parser/parser-impl.hh>
#include <parser/utoken.hh>

#if defined __GNUC__ && __GNUC__ == 4 && __GNUC_MINOR__ == 4
# pragma GCC diagnostic ignored "-Wuninitialized"
#endif

#define MAKE(Kind, ...)                         \
  up.factory().make_ ## Kind(__VA_ARGS__)

  namespace
  {

    static void
    modifiers_add(parser::ParserImpl& up, const ast::loc& loc,
                  ast::modifiers_type& mods,
                  const ::ast::Factory::modifier_type& mod)
    {
      if (libport::has(mods, mod.first))
        up.warn(loc,
                libport::format("modifier redefined: %s", mod.first));
      mods[mod.first] = mod.second;
    }

    static void
    assocs_add(parser::ParserImpl& /*up*/, const ast::loc& /*loc*/,
               ast::dictionary_elts_type& mods,
               const ast::dictionary_elt_type& mod)
    {
      // FIXME: check for duplicate literal keys?
      // if (libport::has(mods, mod.first))
      //   up.warn(loc,
      //           libport::format("key redefined: %s", mod.first));
      mods.push_back(mod);
    }

    /// Use the scanner in the right parser::ParserImpl.
    static
    inline
    yy::parser::symbol_type
    yylex(parser::ParserImpl& up)
    {
      boost::optional< ::yy::parser::token_type>&
        initial_token(up.initial_token_get());
      if (initial_token)
      {
        ::yy::parser::token_type res = initial_token.get();
        initial_token = boost::optional< ::yy::parser::token_type>();
        return yy::parser::symbol_type(res, yy::location());
      }
      return up.scanner_.yylex();
    }

  } // anon namespace

# define REQUIRE_IDENTIFIER(Loc, Effective, Expected)                   \
  do {                                                                  \
    if (Effective != libport::Symbol(Expected))                         \
      up.error(Loc,                                                     \
               libport::format("unexpected `%s', expecting `%s'",       \
                               Effective, Expected));                   \
  } while (false)


#line 136 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:416


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 231 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:491

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (::parser::ParserImpl& up_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      up (up_yyarg)
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state ()
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (const stack_symbol_type& that)
    : super_type (that.state, that.location)
  {
    switch (that.type_get ())
    {
      case 168: // event_match
        value.copy< ast::EventMatch > (that.value);
        break;

      case 143: // case
        value.copy< ast::Factory::case_type > (that.value);
        break;

      case 142: // cases
        value.copy< ast::Factory::cases_type > (that.value);
        break;

      case 136: // modifier
        value.copy< ast::Factory::modifier_type > (that.value);
        break;

      case 174: // rel-ops
        value.copy< ast::Factory::relations_type > (that.value);
        break;

      case 187: // formal
        value.copy< ast::Formal > (that.value);
        break;

      case 188: // formals.1
      case 189: // formals.0
      case 190: // formals
        value.copy< ast::Formals* > (that.value);
        break;

      case 144: // catches.1
        value.copy< ast::catches_type > (that.value);
        break;

      case 158: // assoc
        value.copy< ast::dictionary_elt_type > (that.value);
        break;

      case 159: // assocs.1
      case 160: // assocs
        value.copy< ast::dictionary_elts_type > (that.value);
        break;

      case 127: // protos.1
      case 128: // protos
      case 162: // tuple.exps
      case 163: // tuple
      case 164: // bitor-exps
      case 165: // bitor-exps.1
      case 177: // claims
      case 178: // claims.1
      case 179: // exps
      case 180: // exps.1
      case 181: // exps.2
      case 182: // args
      case 183: // args.opt
        value.copy< ast::exps_type* > (that.value);
        break;

      case 41: // ","
      case 42: // ";"
      case 43: // "&"
      case 44: // "|"
      case 45: // "every"
      case 46: // "for"
      case 47: // "loop"
      case 48: // "while"
      case 49: // "at"
        value.copy< ast::flavor_type > (that.value);
        break;

      case 137: // modifiers
        value.copy< ast::modifiers_type > (that.value);
        break;

      case 135: // k1_id
        value.copy< ast::rCall > (that.value);
        break;

      case 147: // catch
        value.copy< ast::rCatch > (that.value);
        break;

      case 161: // dictionary
        value.copy< ast::rDictionary > (that.value);
        break;

      case 116: // root
      case 117: // root_exp
      case 118: // root_exps
      case 120: // cstmt.opt
      case 121: // cstmt
      case 122: // stmt.opt
      case 123: // stmt
      case 124: // block
      case 126: // proto
      case 129: // exp
      case 138: // primary-exp
      case 140: // else.opt
      case 141: // onleave.opt
      case 148: // catch.opt
      case 149: // finally.opt
      case 154: // bitor-exp
      case 155: // new
      case 156: // float-exp
      case 166: // literal-exp
      case 169: // guard.opt
      case 170: // tilda.opt
      case 171: // unary-exp
      case 173: // rel-exp
      case 175: // exp.opt
      case 185: // typespec
      case 186: // typespec.opt
        value.copy< ast::rExp > (that.value);
        break;

      case 152: // lvalue
        value.copy< ast::rLValue > (that.value);
        break;

      case 145: // match
      case 146: // match.opt
        value.copy< ast::rMatch > (that.value);
        break;

      case 119: // stmts
      case 139: // default.opt
        value.copy< ast::rNary > (that.value);
        break;

      case 130: // id.0
      case 131: // id.1
      case 184: // identifiers
        value.copy< ast::symbols_type > (that.value);
        break;

      case 134: // routine
      case 151: // detach
        value.copy< bool > (that.value);
        break;

      case 50: // "identifier"
      case 62: // "^="
      case 63: // "-="
      case 64: // "%="
      case 65: // "+="
      case 66: // "/="
      case 67: // "*="
      case 75: // "new"
      case 84: // "!"
      case 85: // "bitand"
      case 86: // "bitor"
      case 87: // "^"
      case 88: // "compl"
      case 89: // ">>"
      case 90: // "<<"
      case 91: // "-"
      case 92: // "%"
      case 93: // "+"
      case 94: // "/"
      case 95: // "*"
      case 96: // "**"
      case 97: // "=~="
      case 98: // "=="
      case 99: // "==="
      case 100: // ">="
      case 101: // ">"
      case 102: // "<="
      case 103: // "<"
      case 104: // "!="
      case 105: // "!=="
      case 106: // "~="
      case 107: // "&&"
      case 108: // "||"
      case 133: // event_or_function
      case 153: // id
      case 172: // rel-op
        value.copy< libport::Symbol > (that.value);
        break;

      case 76: // "angle"
      case 77: // "duration"
      case 78: // "float"
      case 157: // duration
        value.copy< libport::ufloat > (that.value);
        break;

      case 80: // "string"
      case 167: // string
        value.copy< std::string > (that.value);
        break;

      case 176: // unsigned
        value.copy< unsigned > (that.value);
        break;

      default:
        break;
    }

  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    switch (that.type_get ())
    {
      case 168: // event_match
        value.move< ast::EventMatch > (that.value);
        break;

      case 143: // case
        value.move< ast::Factory::case_type > (that.value);
        break;

      case 142: // cases
        value.move< ast::Factory::cases_type > (that.value);
        break;

      case 136: // modifier
        value.move< ast::Factory::modifier_type > (that.value);
        break;

      case 174: // rel-ops
        value.move< ast::Factory::relations_type > (that.value);
        break;

      case 187: // formal
        value.move< ast::Formal > (that.value);
        break;

      case 188: // formals.1
      case 189: // formals.0
      case 190: // formals
        value.move< ast::Formals* > (that.value);
        break;

      case 144: // catches.1
        value.move< ast::catches_type > (that.value);
        break;

      case 158: // assoc
        value.move< ast::dictionary_elt_type > (that.value);
        break;

      case 159: // assocs.1
      case 160: // assocs
        value.move< ast::dictionary_elts_type > (that.value);
        break;

      case 127: // protos.1
      case 128: // protos
      case 162: // tuple.exps
      case 163: // tuple
      case 164: // bitor-exps
      case 165: // bitor-exps.1
      case 177: // claims
      case 178: // claims.1
      case 179: // exps
      case 180: // exps.1
      case 181: // exps.2
      case 182: // args
      case 183: // args.opt
        value.move< ast::exps_type* > (that.value);
        break;

      case 41: // ","
      case 42: // ";"
      case 43: // "&"
      case 44: // "|"
      case 45: // "every"
      case 46: // "for"
      case 47: // "loop"
      case 48: // "while"
      case 49: // "at"
        value.move< ast::flavor_type > (that.value);
        break;

      case 137: // modifiers
        value.move< ast::modifiers_type > (that.value);
        break;

      case 135: // k1_id
        value.move< ast::rCall > (that.value);
        break;

      case 147: // catch
        value.move< ast::rCatch > (that.value);
        break;

      case 161: // dictionary
        value.move< ast::rDictionary > (that.value);
        break;

      case 116: // root
      case 117: // root_exp
      case 118: // root_exps
      case 120: // cstmt.opt
      case 121: // cstmt
      case 122: // stmt.opt
      case 123: // stmt
      case 124: // block
      case 126: // proto
      case 129: // exp
      case 138: // primary-exp
      case 140: // else.opt
      case 141: // onleave.opt
      case 148: // catch.opt
      case 149: // finally.opt
      case 154: // bitor-exp
      case 155: // new
      case 156: // float-exp
      case 166: // literal-exp
      case 169: // guard.opt
      case 170: // tilda.opt
      case 171: // unary-exp
      case 173: // rel-exp
      case 175: // exp.opt
      case 185: // typespec
      case 186: // typespec.opt
        value.move< ast::rExp > (that.value);
        break;

      case 152: // lvalue
        value.move< ast::rLValue > (that.value);
        break;

      case 145: // match
      case 146: // match.opt
        value.move< ast::rMatch > (that.value);
        break;

      case 119: // stmts
      case 139: // default.opt
        value.move< ast::rNary > (that.value);
        break;

      case 130: // id.0
      case 131: // id.1
      case 184: // identifiers
        value.move< ast::symbols_type > (that.value);
        break;

      case 134: // routine
      case 151: // detach
        value.move< bool > (that.value);
        break;

      case 50: // "identifier"
      case 62: // "^="
      case 63: // "-="
      case 64: // "%="
      case 65: // "+="
      case 66: // "/="
      case 67: // "*="
      case 75: // "new"
      case 84: // "!"
      case 85: // "bitand"
      case 86: // "bitor"
      case 87: // "^"
      case 88: // "compl"
      case 89: // ">>"
      case 90: // "<<"
      case 91: // "-"
      case 92: // "%"
      case 93: // "+"
      case 94: // "/"
      case 95: // "*"
      case 96: // "**"
      case 97: // "=~="
      case 98: // "=="
      case 99: // "==="
      case 100: // ">="
      case 101: // ">"
      case 102: // "<="
      case 103: // "<"
      case 104: // "!="
      case 105: // "!=="
      case 106: // "~="
      case 107: // "&&"
      case 108: // "||"
      case 133: // event_or_function
      case 153: // id
      case 172: // rel-op
        value.move< libport::Symbol > (that.value);
        break;

      case 76: // "angle"
      case 77: // "duration"
      case 78: // "float"
      case 157: // duration
        value.move< libport::ufloat > (that.value);
        break;

      case 80: // "string"
      case 167: // string
        value.move< std::string > (that.value);
        break;

      case 176: // unsigned
        value.move< unsigned > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 168: // event_match
        value.copy< ast::EventMatch > (that.value);
        break;

      case 143: // case
        value.copy< ast::Factory::case_type > (that.value);
        break;

      case 142: // cases
        value.copy< ast::Factory::cases_type > (that.value);
        break;

      case 136: // modifier
        value.copy< ast::Factory::modifier_type > (that.value);
        break;

      case 174: // rel-ops
        value.copy< ast::Factory::relations_type > (that.value);
        break;

      case 187: // formal
        value.copy< ast::Formal > (that.value);
        break;

      case 188: // formals.1
      case 189: // formals.0
      case 190: // formals
        value.copy< ast::Formals* > (that.value);
        break;

      case 144: // catches.1
        value.copy< ast::catches_type > (that.value);
        break;

      case 158: // assoc
        value.copy< ast::dictionary_elt_type > (that.value);
        break;

      case 159: // assocs.1
      case 160: // assocs
        value.copy< ast::dictionary_elts_type > (that.value);
        break;

      case 127: // protos.1
      case 128: // protos
      case 162: // tuple.exps
      case 163: // tuple
      case 164: // bitor-exps
      case 165: // bitor-exps.1
      case 177: // claims
      case 178: // claims.1
      case 179: // exps
      case 180: // exps.1
      case 181: // exps.2
      case 182: // args
      case 183: // args.opt
        value.copy< ast::exps_type* > (that.value);
        break;

      case 41: // ","
      case 42: // ";"
      case 43: // "&"
      case 44: // "|"
      case 45: // "every"
      case 46: // "for"
      case 47: // "loop"
      case 48: // "while"
      case 49: // "at"
        value.copy< ast::flavor_type > (that.value);
        break;

      case 137: // modifiers
        value.copy< ast::modifiers_type > (that.value);
        break;

      case 135: // k1_id
        value.copy< ast::rCall > (that.value);
        break;

      case 147: // catch
        value.copy< ast::rCatch > (that.value);
        break;

      case 161: // dictionary
        value.copy< ast::rDictionary > (that.value);
        break;

      case 116: // root
      case 117: // root_exp
      case 118: // root_exps
      case 120: // cstmt.opt
      case 121: // cstmt
      case 122: // stmt.opt
      case 123: // stmt
      case 124: // block
      case 126: // proto
      case 129: // exp
      case 138: // primary-exp
      case 140: // else.opt
      case 141: // onleave.opt
      case 148: // catch.opt
      case 149: // finally.opt
      case 154: // bitor-exp
      case 155: // new
      case 156: // float-exp
      case 166: // literal-exp
      case 169: // guard.opt
      case 170: // tilda.opt
      case 171: // unary-exp
      case 173: // rel-exp
      case 175: // exp.opt
      case 185: // typespec
      case 186: // typespec.opt
        value.copy< ast::rExp > (that.value);
        break;

      case 152: // lvalue
        value.copy< ast::rLValue > (that.value);
        break;

      case 145: // match
      case 146: // match.opt
        value.copy< ast::rMatch > (that.value);
        break;

      case 119: // stmts
      case 139: // default.opt
        value.copy< ast::rNary > (that.value);
        break;

      case 130: // id.0
      case 131: // id.1
      case 184: // identifiers
        value.copy< ast::symbols_type > (that.value);
        break;

      case 134: // routine
      case 151: // detach
        value.copy< bool > (that.value);
        break;

      case 50: // "identifier"
      case 62: // "^="
      case 63: // "-="
      case 64: // "%="
      case 65: // "+="
      case 66: // "/="
      case 67: // "*="
      case 75: // "new"
      case 84: // "!"
      case 85: // "bitand"
      case 86: // "bitor"
      case 87: // "^"
      case 88: // "compl"
      case 89: // ">>"
      case 90: // "<<"
      case 91: // "-"
      case 92: // "%"
      case 93: // "+"
      case 94: // "/"
      case 95: // "*"
      case 96: // "**"
      case 97: // "=~="
      case 98: // "=="
      case 99: // "==="
      case 100: // ">="
      case 101: // ">"
      case 102: // "<="
      case 103: // "<"
      case 104: // "!="
      case 105: // "!=="
      case 106: // "~="
      case 107: // "&&"
      case 108: // "||"
      case 133: // event_or_function
      case 153: // id
      case 172: // rel-op
        value.copy< libport::Symbol > (that.value);
        break;

      case 76: // "angle"
      case 77: // "duration"
      case 78: // "float"
      case 157: // duration
        value.copy< libport::ufloat > (that.value);
        break;

      case 80: // "string"
      case 167: // string
        value.copy< std::string > (that.value);
        break;

      case 176: // unsigned
        value.copy< unsigned > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
            case 41: // ","

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::flavor_type > (); }
#line 986 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 42: // ";"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::flavor_type > (); }
#line 993 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 43: // "&"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::flavor_type > (); }
#line 1000 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 44: // "|"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::flavor_type > (); }
#line 1007 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 45: // "every"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::flavor_type > (); }
#line 1014 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 46: // "for"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::flavor_type > (); }
#line 1021 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 47: // "loop"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::flavor_type > (); }
#line 1028 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 48: // "while"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::flavor_type > (); }
#line 1035 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 49: // "at"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::flavor_type > (); }
#line 1042 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 50: // "identifier"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1049 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 62: // "^="

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1056 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 63: // "-="

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1063 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 64: // "%="

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1070 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 65: // "+="

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1077 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 66: // "/="

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1084 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 67: // "*="

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1091 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 75: // "new"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1098 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 76: // "angle"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::ufloat > (); }
#line 1105 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 77: // "duration"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::ufloat > (); }
#line 1112 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 78: // "float"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::ufloat > (); }
#line 1119 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 80: // "string"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< std::string > (); }
#line 1126 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 84: // "!"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1133 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 85: // "bitand"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1140 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 86: // "bitor"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1147 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 87: // "^"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1154 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 88: // "compl"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1161 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 89: // ">>"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1168 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 90: // "<<"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1175 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 91: // "-"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1182 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 92: // "%"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1189 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 93: // "+"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1196 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 94: // "/"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1203 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 95: // "*"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1210 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 96: // "**"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1217 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 97: // "=~="

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1224 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 98: // "=="

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1231 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 99: // "==="

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1238 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 100: // ">="

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1245 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 101: // ">"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1252 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 102: // "<="

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1259 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 103: // "<"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1266 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 104: // "!="

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1273 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 105: // "!=="

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1280 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 106: // "~="

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1287 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 107: // "&&"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1294 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 108: // "||"

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1301 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 116: // root

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1308 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 117: // root_exp

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1315 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 118: // root_exps

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1322 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 119: // stmts

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rNary > (); }
#line 1329 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 120: // cstmt.opt

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1336 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 121: // cstmt

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1343 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 122: // stmt.opt

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1350 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 123: // stmt

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1357 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 124: // block

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1364 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 126: // proto

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1371 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 127: // protos.1

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::exps_type* > (); }
#line 1378 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 128: // protos

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::exps_type* > (); }
#line 1385 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 129: // exp

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1392 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 130: // id.0

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::symbols_type > (); }
#line 1399 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 131: // id.1

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::symbols_type > (); }
#line 1406 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 133: // event_or_function

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1413 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 134: // routine

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< bool > (); }
#line 1420 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 135: // k1_id

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rCall > (); }
#line 1427 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 136: // modifier

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::Factory::modifier_type > (); }
#line 1434 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 137: // modifiers

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::modifiers_type > (); }
#line 1441 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 138: // primary-exp

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1448 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 139: // default.opt

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rNary > (); }
#line 1455 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 140: // else.opt

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1462 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 141: // onleave.opt

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1469 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 142: // cases

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::Factory::cases_type > (); }
#line 1476 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 143: // case

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::Factory::case_type > (); }
#line 1483 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 144: // catches.1

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::catches_type > (); }
#line 1490 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 145: // match

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rMatch > (); }
#line 1497 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 146: // match.opt

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rMatch > (); }
#line 1504 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 147: // catch

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rCatch > (); }
#line 1511 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 148: // catch.opt

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1518 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 149: // finally.opt

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1525 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 151: // detach

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< bool > (); }
#line 1532 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 152: // lvalue

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rLValue > (); }
#line 1539 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 153: // id

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1546 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 154: // bitor-exp

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1553 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 155: // new

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1560 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 156: // float-exp

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1567 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 157: // duration

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::ufloat > (); }
#line 1574 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 158: // assoc

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::dictionary_elt_type > (); }
#line 1581 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 159: // assocs.1

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::dictionary_elts_type > (); }
#line 1588 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 160: // assocs

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::dictionary_elts_type > (); }
#line 1595 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 161: // dictionary

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rDictionary > (); }
#line 1602 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 162: // tuple.exps

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::exps_type* > (); }
#line 1609 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 163: // tuple

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::exps_type* > (); }
#line 1616 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 164: // bitor-exps

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::exps_type* > (); }
#line 1623 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 165: // bitor-exps.1

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::exps_type* > (); }
#line 1630 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 166: // literal-exp

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1637 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 167: // string

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< std::string > (); }
#line 1644 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 168: // event_match

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::EventMatch > (); }
#line 1651 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 169: // guard.opt

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1658 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 170: // tilda.opt

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1665 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 171: // unary-exp

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1672 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 172: // rel-op

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< libport::Symbol > (); }
#line 1679 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 173: // rel-exp

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1686 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 174: // rel-ops

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::Factory::relations_type > (); }
#line 1693 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 175: // exp.opt

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1700 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 176: // unsigned

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< unsigned > (); }
#line 1707 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 177: // claims

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::exps_type* > (); }
#line 1714 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 178: // claims.1

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::exps_type* > (); }
#line 1721 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 179: // exps

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::exps_type* > (); }
#line 1728 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 180: // exps.1

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::exps_type* > (); }
#line 1735 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 181: // exps.2

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::exps_type* > (); }
#line 1742 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 182: // args

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::exps_type* > (); }
#line 1749 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 183: // args.opt

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::exps_type* > (); }
#line 1756 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 184: // identifiers

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::symbols_type > (); }
#line 1763 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 185: // typespec

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1770 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 186: // typespec.opt

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::rExp > (); }
#line 1777 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 187: // formal

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::Formal > (); }
#line 1784 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 188: // formals.1

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::Formals* > (); }
#line 1791 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 189: // formals.0

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::Formals* > (); }
#line 1798 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;

      case 190: // formals

#line 205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:644
        { debug_stream() << libport::deref << yysym.value.template as< ast::Formals* > (); }
#line 1805 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:644
        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  void
  parser::yypop_ (unsigned n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    // User initialization code.
    #line 55 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:746
{
  // Saved when exiting the start symbol.
  up.scanner_.loc = up.loc_;
}

#line 1921 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:746

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (up));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 168: // event_match
        yylhs.value.build< ast::EventMatch > ();
        break;

      case 143: // case
        yylhs.value.build< ast::Factory::case_type > ();
        break;

      case 142: // cases
        yylhs.value.build< ast::Factory::cases_type > ();
        break;

      case 136: // modifier
        yylhs.value.build< ast::Factory::modifier_type > ();
        break;

      case 174: // rel-ops
        yylhs.value.build< ast::Factory::relations_type > ();
        break;

      case 187: // formal
        yylhs.value.build< ast::Formal > ();
        break;

      case 188: // formals.1
      case 189: // formals.0
      case 190: // formals
        yylhs.value.build< ast::Formals* > ();
        break;

      case 144: // catches.1
        yylhs.value.build< ast::catches_type > ();
        break;

      case 158: // assoc
        yylhs.value.build< ast::dictionary_elt_type > ();
        break;

      case 159: // assocs.1
      case 160: // assocs
        yylhs.value.build< ast::dictionary_elts_type > ();
        break;

      case 127: // protos.1
      case 128: // protos
      case 162: // tuple.exps
      case 163: // tuple
      case 164: // bitor-exps
      case 165: // bitor-exps.1
      case 177: // claims
      case 178: // claims.1
      case 179: // exps
      case 180: // exps.1
      case 181: // exps.2
      case 182: // args
      case 183: // args.opt
        yylhs.value.build< ast::exps_type* > ();
        break;

      case 41: // ","
      case 42: // ";"
      case 43: // "&"
      case 44: // "|"
      case 45: // "every"
      case 46: // "for"
      case 47: // "loop"
      case 48: // "while"
      case 49: // "at"
        yylhs.value.build< ast::flavor_type > ();
        break;

      case 137: // modifiers
        yylhs.value.build< ast::modifiers_type > ();
        break;

      case 135: // k1_id
        yylhs.value.build< ast::rCall > ();
        break;

      case 147: // catch
        yylhs.value.build< ast::rCatch > ();
        break;

      case 161: // dictionary
        yylhs.value.build< ast::rDictionary > ();
        break;

      case 116: // root
      case 117: // root_exp
      case 118: // root_exps
      case 120: // cstmt.opt
      case 121: // cstmt
      case 122: // stmt.opt
      case 123: // stmt
      case 124: // block
      case 126: // proto
      case 129: // exp
      case 138: // primary-exp
      case 140: // else.opt
      case 141: // onleave.opt
      case 148: // catch.opt
      case 149: // finally.opt
      case 154: // bitor-exp
      case 155: // new
      case 156: // float-exp
      case 166: // literal-exp
      case 169: // guard.opt
      case 170: // tilda.opt
      case 171: // unary-exp
      case 173: // rel-exp
      case 175: // exp.opt
      case 185: // typespec
      case 186: // typespec.opt
        yylhs.value.build< ast::rExp > ();
        break;

      case 152: // lvalue
        yylhs.value.build< ast::rLValue > ();
        break;

      case 145: // match
      case 146: // match.opt
        yylhs.value.build< ast::rMatch > ();
        break;

      case 119: // stmts
      case 139: // default.opt
        yylhs.value.build< ast::rNary > ();
        break;

      case 130: // id.0
      case 131: // id.1
      case 184: // identifiers
        yylhs.value.build< ast::symbols_type > ();
        break;

      case 134: // routine
      case 151: // detach
        yylhs.value.build< bool > ();
        break;

      case 50: // "identifier"
      case 62: // "^="
      case 63: // "-="
      case 64: // "%="
      case 65: // "+="
      case 66: // "/="
      case 67: // "*="
      case 75: // "new"
      case 84: // "!"
      case 85: // "bitand"
      case 86: // "bitor"
      case 87: // "^"
      case 88: // "compl"
      case 89: // ">>"
      case 90: // "<<"
      case 91: // "-"
      case 92: // "%"
      case 93: // "+"
      case 94: // "/"
      case 95: // "*"
      case 96: // "**"
      case 97: // "=~="
      case 98: // "=="
      case 99: // "==="
      case 100: // ">="
      case 101: // ">"
      case 102: // "<="
      case 103: // "<"
      case 104: // "!="
      case 105: // "!=="
      case 106: // "~="
      case 107: // "&&"
      case 108: // "||"
      case 133: // event_or_function
      case 153: // id
      case 172: // rel-op
        yylhs.value.build< libport::Symbol > ();
        break;

      case 76: // "angle"
      case 77: // "duration"
      case 78: // "float"
      case 157: // duration
        yylhs.value.build< libport::ufloat > ();
        break;

      case 80: // "string"
      case 167: // string
        yylhs.value.build< std::string > ();
        break;

      case 176: // unsigned
        yylhs.value.build< unsigned > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 314 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    // Remove the reference from yystack by swaping with a 0 intrusive
    // pointer.
    aver(up.result_.get() == 0);
    std::swap(up.result_, yystack_[0].value.as< ast::rExp > ());
    up.loc_ = yylhs.location;
    YYACCEPT;
  }
#line 2240 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 3:
#line 328 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = 0; }
#line 2246 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 4:
#line 329 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 2252 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 5:
#line 330 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 2258 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 6:
#line 336 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = new ast::Stmt(yylhs.location, yystack_[0].value.as< ast::flavor_type > (), yystack_[1].value.as< ast::rExp > ()); }
#line 2264 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 7:
#line 337 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = new ast::Stmt(yylhs.location, yystack_[0].value.as< ast::flavor_type > (), yystack_[1].value.as< ast::rExp > ()); }
#line 2270 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 8:
#line 338 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = new ast::Stmt(yylhs.location, ast::flavor_none, yystack_[1].value.as< ast::rExp > ()); }
#line 2276 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 9:
#line 339 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = 0; }
#line 2282 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 10:
#line 340 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = 0; }
#line 2288 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 11:
#line 341 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = 0; }
#line 2294 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 12:
#line 346 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = yystack_[0].value.as< ast::rNary > (); }
#line 2300 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 13:
#line 358 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rNary > () = MAKE(nary, yylhs.location, yystack_[0].value.as< ast::rExp > ()); }
#line 2306 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 14:
#line 359 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rNary > () = MAKE(nary, yylhs.location, yystack_[2].value.as< ast::rNary > (), yystack_[1].location, yystack_[1].value.as< ast::flavor_type > (), yystack_[0].value.as< ast::rExp > ()); }
#line 2312 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 15:
#line 360 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rNary > () = MAKE(nary, yylhs.location, yystack_[2].value.as< ast::rNary > (), yystack_[1].location, yystack_[1].value.as< ast::flavor_type > (), yystack_[0].value.as< ast::rExp > ()); }
#line 2318 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 16:
#line 368 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(noop, yylhs.location); }
#line 2324 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 17:
#line 369 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 2330 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 18:
#line 370 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(bin, yylhs.location, yystack_[0].value.as< ast::flavor_type > (), yystack_[1].value.as< ast::rExp > (), MAKE(noop, yystack_[0].location)); }
#line 2336 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 19:
#line 375 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { assert(yystack_[0].value.as< ast::rExp > ()); std::swap(yylhs.value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 2342 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 20:
#line 376 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(bin, yylhs.location, yystack_[1].value.as< ast::flavor_type > (), yystack_[2].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 2348 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 21:
#line 377 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(bin, yylhs.location, yystack_[1].value.as< ast::flavor_type > (), yystack_[2].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 2354 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 22:
#line 387 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(noop, yylhs.location); }
#line 2360 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 23:
#line 388 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 2366 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 24:
#line 394 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::rExp > () = new ast::TaggedStmt(yylhs.location, yystack_[2].value.as< ast::rExp > (), MAKE(scope, yylhs.location, yystack_[0].value.as< ast::rExp > ()));
  }
#line 2374 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 25:
#line 404 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 2380 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 26:
#line 408 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(strip, yystack_[1].value.as< ast::rNary > ()); }
#line 2386 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 27:
#line 409 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(noop, yylhs.location); }
#line 2392 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 28:
#line 413 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(noop, yylhs.location); }
#line 2398 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 33:
#line 435 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 2404 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 34:
#line 441 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::exps_type* > () = new ast::exps_type(1, yystack_[0].value.as< ast::rExp > ()); }
#line 2410 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 35:
#line 442 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::exps_type* > (), yystack_[2].value.as< ast::exps_type* > ()); *yylhs.value.as< ast::exps_type* > () << yystack_[0].value.as< ast::rExp > (); }
#line 2416 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 36:
#line 447 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::exps_type* > () = 0; }
#line 2422 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 37:
#line 448 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::exps_type* > (), yystack_[0].value.as< ast::exps_type* > ()); }
#line 2428 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 38:
#line 454 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      yylhs.value.as< ast::rExp > () = MAKE(class, yylhs.location, yystack_[2].value.as< ast::rLValue > (), yystack_[1].value.as< ast::exps_type* > (), yystack_[0].value.as< ast::rExp > (), false);
    }
#line 2436 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 39:
#line 463 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      ast::rClass c = MAKE(class, yylhs.location, yystack_[2].value.as< ast::rLValue > (), yystack_[1].value.as< ast::exps_type* > (), yystack_[0].value.as< ast::rExp > (), true).unsafe_cast<ast::Class>();
      c->is_package_set(true);
      yylhs.value.as< ast::rExp > () = c;
    }
#line 2446 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 40:
#line 478 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {}
#line 2452 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 41:
#line 479 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::symbols_type > (), yystack_[1].value.as< ast::symbols_type > ()); }
#line 2458 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 42:
#line 483 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::symbols_type > () << yystack_[0].value.as< libport::Symbol > (); }
#line 2464 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 43:
#line 484 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::symbols_type > (), yystack_[2].value.as< ast::symbols_type > ()); yylhs.value.as< ast::symbols_type > () << yystack_[0].value.as< libport::Symbol > (); }
#line 2470 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 44:
#line 490 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::rExp > () = MAKE(enum, yylhs.location, yystack_[3].value.as< libport::Symbol > (), yystack_[1].value.as< ast::symbols_type > ());
  }
#line 2478 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 45:
#line 501 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    REQUIRE_IDENTIFIER(yystack_[0].location, yystack_[0].value.as< libport::Symbol > (), "from");
  }
#line 2486 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 46:
#line 510 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< libport::Symbol > () = SYMBOL(function);
  }
#line 2494 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 47:
#line 514 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    REQUIRE_IDENTIFIER(yystack_[0].location, yystack_[0].value.as< libport::Symbol > (), "event");
    yylhs.value.as< libport::Symbol > () = SYMBOL(event);
  }
#line 2503 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 48:
#line 524 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    REQUIRE_IDENTIFIER(yystack_[1].location, yystack_[1].value.as< libport::Symbol > (), "object");
    yylhs.value.as< ast::rExp > () = MAKE(external_object, yylhs.location, yystack_[0].value.as< libport::Symbol > ());
  }
#line 2512 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 49:
#line 530 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::rExp > () = MAKE(external_var, yylhs.location, yystack_[4].value.as< libport::Symbol > (), yystack_[2].value.as< libport::Symbol > (), yystack_[0].value.as< libport::Symbol > ());
  }
#line 2520 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 50:
#line 536 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::rExp > () = MAKE(external_event_or_function,
              yylhs.location, yystack_[8].value.as< libport::Symbol > (), yystack_[6].value.as< unsigned > (), yystack_[4].value.as< libport::Symbol > (), yystack_[2].value.as< libport::Symbol > (), yystack_[0].value.as< libport::Symbol > ());
  }
#line 2529 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 51:
#line 547 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    ast::rExp e = yystack_[0].value.as< ast::rLValue > ();
    ast::rCall c = yystack_[0].value.as< ast::rLValue > ().unsafe_cast<ast::Call>();
    libport::Symbol s = c->name_get();
    bool isStar = (s==SYMBOL(STAR));
    if (isStar)
    {
      e = c->target_get();
      // s is irrelevant in that case
    }
    else
    { // We must replace last call with a getslot
      ast::rExp tgt = c->target_get();
      if (c->target_implicit())
        e = MAKE(call, yylhs.location, c->target_get(), SYMBOL(findSlot),
          MAKE(string, yylhs.location, s));
      else
        e = MAKE(get_slot, yylhs.location, tgt, s);
    }
    ast::LocalDeclaration* ae
      = new ast::LocalDeclaration(yylhs.location, s, e);
    ae->is_star_set(isStar);
    ae->is_import_set(true);
    yylhs.value.as< ast::rExp > () = ae;
  }
#line 2559 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 52:
#line 588 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::rExp > () = new ast::Emit(yylhs.location, yystack_[3].value.as< ast::rExp > (), yystack_[1].value.as< ast::exps_type* > (), yystack_[0].value.as< ast::rExp > ());
  }
#line 2567 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 53:
#line 600 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< bool > () = true; }
#line 2573 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 54:
#line 601 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< bool > () = false; }
#line 2579 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 55:
#line 608 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      // Compiled as "var name = function args stmt".
      yylhs.value.as< ast::rExp > () = new ast::Declaration(yylhs.location, yystack_[2].value.as< ast::rCall > (),
                                MAKE(routine, yylhs.location, yystack_[3].value.as< bool > (), yystack_[1].location, yystack_[1].value.as< ast::Formals* > (), yystack_[0].value.as< ast::rExp > ()));
    }
#line 2589 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 56:
#line 614 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      if (yystack_[3].value.as< libport::Symbol > () == SYMBOL(get) || yystack_[3].value.as< libport::Symbol > () == SYMBOL(set))
      {
        yylhs.value.as< ast::rExp > () = MAKE(define_setter_getter, yylhs.location,
          libport::Symbol("o" + std::string(yystack_[3].value.as< libport::Symbol > ())), yystack_[2].value.as< libport::Symbol > (),
          MAKE(routine, yylhs.location, false, yystack_[1].location, yystack_[1].value.as< ast::Formals* > (), yystack_[0].value.as< ast::rExp > ()));
      }
      else
      {
        REQUIRE_IDENTIFIER(yylhs.location, yystack_[3].value.as< libport::Symbol > (), "get or set");
        yylhs.value.as< ast::rExp > () = MAKE(nil);
      }
    }
#line 2607 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 57:
#line 660 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rCall > () = MAKE(call, yylhs.location, yystack_[0].value.as< libport::Symbol > ()); }
#line 2613 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 58:
#line 661 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rCall > () = MAKE(call, yylhs.location, new ast::This(yystack_[2].location), yystack_[0].value.as< libport::Symbol > ()); }
#line 2619 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 59:
#line 662 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rCall > () = MAKE(call, yylhs.location, ast::rExp(yystack_[2].value.as< ast::rCall > ()), yystack_[0].value.as< libport::Symbol > ()); }
#line 2625 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 60:
#line 674 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::Factory::modifier_type > ().first = yystack_[2].value.as< libport::Symbol > ();
    yylhs.value.as< ast::Factory::modifier_type > ().second = yystack_[0].value.as< ast::rExp > ();
  }
#line 2634 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 61:
#line 683 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    modifiers_add(up, yystack_[0].location, yylhs.value.as< ast::modifiers_type > (), yystack_[0].value.as< ast::Factory::modifier_type > ());
  }
#line 2642 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 62:
#line 687 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    std::swap(yylhs.value.as< ast::modifiers_type > (), yystack_[1].value.as< ast::modifiers_type > ());
    modifiers_add(up, yystack_[0].location, yylhs.value.as< ast::modifiers_type > (), yystack_[0].value.as< ast::Factory::modifier_type > ());
  }
#line 2651 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 63:
#line 704 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::rExp > () = MAKE(assign, yylhs.location, yystack_[2].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ());
  }
#line 2659 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 64:
#line 708 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::rExp > () = MAKE(assign, yylhs.location, yystack_[3].value.as< ast::rExp > (), yystack_[1].value.as< ast::rExp > (), yystack_[0].value.as< ast::modifiers_type > ());
  }
#line 2667 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 65:
#line 723 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = new ast::OpAssignment(yystack_[1].location, yystack_[2].value.as< ast::rLValue > (), yystack_[0].value.as< ast::rExp > (), yystack_[1].value.as< libport::Symbol > ()); }
#line 2673 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 66:
#line 724 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = new ast::OpAssignment(yystack_[1].location, yystack_[2].value.as< ast::rLValue > (), yystack_[0].value.as< ast::rExp > (), yystack_[1].value.as< libport::Symbol > ()); }
#line 2679 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 67:
#line 725 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = new ast::OpAssignment(yystack_[1].location, yystack_[2].value.as< ast::rLValue > (), yystack_[0].value.as< ast::rExp > (), yystack_[1].value.as< libport::Symbol > ()); }
#line 2685 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 68:
#line 726 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = new ast::OpAssignment(yystack_[1].location, yystack_[2].value.as< ast::rLValue > (), yystack_[0].value.as< ast::rExp > (), yystack_[1].value.as< libport::Symbol > ()); }
#line 2691 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 69:
#line 727 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = new ast::OpAssignment(yystack_[1].location, yystack_[2].value.as< ast::rLValue > (), yystack_[0].value.as< ast::rExp > (), yystack_[1].value.as< libport::Symbol > ()); }
#line 2697 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 70:
#line 728 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = new ast::OpAssignment(yystack_[1].location, yystack_[2].value.as< ast::rLValue > (), yystack_[0].value.as< ast::rExp > (), yystack_[1].value.as< libport::Symbol > ()); }
#line 2703 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 71:
#line 736 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = new ast::Decrementation(yylhs.location, yystack_[1].value.as< ast::rLValue > (), true); }
#line 2709 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 72:
#line 737 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = new ast::Incrementation(yylhs.location, yystack_[1].value.as< ast::rLValue > (), true); }
#line 2715 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 73:
#line 749 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::rExp > () = new ast::Property(yylhs.location, yystack_[2].value.as< ast::rLValue > ()->call(), yystack_[0].value.as< libport::Symbol > ());
  }
#line 2723 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 74:
#line 760 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      yylhs.value.as< ast::rExp > () = MAKE(at, yylhs.location, yystack_[7].location, yystack_[7].value.as< ast::flavor_type > (), yystack_[6].value.as< ast::symbols_type > (), yystack_[4].value.as< ast::rExp > (), yystack_[1].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > (), yystack_[3].value.as< ast::rExp > ());
    }
#line 2731 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 75:
#line 764 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      yylhs.value.as< ast::rExp > () = MAKE(at_event, yylhs.location, yystack_[6].location, yystack_[6].value.as< ast::flavor_type > (), yystack_[5].value.as< ast::symbols_type > (), yystack_[3].value.as< ast::EventMatch > (), yystack_[1].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ());
    }
#line 2739 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 76:
#line 768 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      yylhs.value.as< ast::rExp > () = MAKE(every, yylhs.location, yystack_[4].location, yystack_[4].value.as< ast::flavor_type > (), yystack_[2].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ());
    }
#line 2747 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 77:
#line 772 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      yylhs.value.as< ast::rExp > () = MAKE(if, yylhs.location, yystack_[3].value.as< ast::rNary > (), yystack_[1].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ());
    }
#line 2755 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 78:
#line 776 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      yylhs.value.as< ast::rExp > () = MAKE(freezeif, yylhs.location, yystack_[3].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > (), yystack_[2].value.as< ast::rExp > ());
    }
#line 2763 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 79:
#line 780 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      yylhs.value.as< ast::rExp > () = MAKE(freezeif_event, yylhs.location, yystack_[2].value.as< ast::EventMatch > (), yystack_[0].value.as< ast::rExp > ());
    }
#line 2771 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 80:
#line 784 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      yylhs.value.as< ast::rExp > () = MAKE(stopif, yylhs.location, yystack_[3].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > (), yystack_[2].value.as< ast::rExp > ());
    }
#line 2779 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 81:
#line 788 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      yylhs.value.as< ast::rExp > () = MAKE(stopif_event, yylhs.location, yystack_[2].value.as< ast::EventMatch > (), yystack_[0].value.as< ast::rExp > ());
    }
#line 2787 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 82:
#line 792 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      yylhs.value.as< ast::rExp > () = MAKE(switch, yystack_[5].location, yystack_[5].value.as< ast::rExp > (), yystack_[2].value.as< ast::Factory::cases_type > (), yystack_[1].value.as< ast::rNary > ());
    }
#line 2795 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 83:
#line 796 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      yylhs.value.as< ast::rExp > () = MAKE(timeout, yylhs.location,
                yystack_[5].value.as< ast::rExp > (), yystack_[3].value.as< ast::rExp > (), yystack_[2].value.as< ast::rExp > (), yystack_[1].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ());
    }
#line 2804 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 84:
#line 801 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      yylhs.value.as< ast::rExp > () = new ast::Return(yylhs.location, yystack_[0].value.as< ast::rExp > ());
    }
#line 2812 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 85:
#line 805 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      yylhs.value.as< ast::rExp > () = new ast::Break(yylhs.location);
    }
#line 2820 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 86:
#line 809 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      yylhs.value.as< ast::rExp > () = new ast::Continue(yylhs.location);
    }
#line 2828 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 87:
#line 813 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      yylhs.value.as< ast::rExp > () = MAKE(waituntil, yylhs.location, yystack_[2].value.as< ast::rExp > (), yystack_[1].value.as< ast::rExp > ());
    }
#line 2836 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 88:
#line 817 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      yylhs.value.as< ast::rExp > () = MAKE(waituntil_event, yylhs.location, yystack_[1].value.as< ast::EventMatch > ());
    }
#line 2844 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 89:
#line 821 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      yylhs.value.as< ast::rExp > () = MAKE(whenever, yylhs.location, yystack_[4].value.as< ast::rExp > (), yystack_[1].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > (), yystack_[3].value.as< ast::rExp > ());
    }
#line 2852 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 90:
#line 825 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      yylhs.value.as< ast::rExp > () = MAKE(whenever_event, yylhs.location, yystack_[3].value.as< ast::EventMatch > (), yystack_[1].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ());
    }
#line 2860 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 91:
#line 841 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rNary > () = 0;            }
#line 2866 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 92:
#line 842 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::rNary > (), yystack_[0].value.as< ast::rNary > ()); }
#line 2872 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 93:
#line 847 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = 0;            }
#line 2878 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 94:
#line 848 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 2884 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 95:
#line 854 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = 0;            }
#line 2890 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 96:
#line 855 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 2896 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 97:
#line 865 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {}
#line 2902 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 98:
#line 866 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::Factory::cases_type > (), yystack_[1].value.as< ast::Factory::cases_type > ()); yylhs.value.as< ast::Factory::cases_type > () << yystack_[0].value.as< ast::Factory::case_type > (); }
#line 2908 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 99:
#line 872 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::Factory::case_type > () = ::ast::Factory::case_type(yystack_[2].value.as< ast::rMatch > (), yystack_[0].value.as< ast::rNary > ()); }
#line 2914 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 100:
#line 881 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::catches_type > () = ast::catches_type(); yylhs.value.as< ast::catches_type > () << yystack_[0].value.as< ast::rCatch > (); }
#line 2920 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 101:
#line 882 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::catches_type > (), yystack_[1].value.as< ast::catches_type > ());        yylhs.value.as< ast::catches_type > () << yystack_[0].value.as< ast::rCatch > (); }
#line 2926 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 102:
#line 887 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rMatch > () = new ast::Match(yylhs.location, yystack_[0].value.as< ast::rExp > (), 0);  }
#line 2932 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 103:
#line 888 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rMatch > () = new ast::Match(yylhs.location, yystack_[2].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 2938 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 104:
#line 891 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rMatch > () = 0; }
#line 2944 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 105:
#line 892 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::rMatch > (), yystack_[1].value.as< ast::rMatch > ()); }
#line 2950 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 106:
#line 896 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rCatch > () = MAKE(catch, yylhs.location, yystack_[1].value.as< ast::rMatch > (), yystack_[0].value.as< ast::rExp > ()); }
#line 2956 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 107:
#line 903 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = 0; }
#line 2962 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 108:
#line 904 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = yystack_[0].value.as< ast::rExp > (); }
#line 2968 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 109:
#line 910 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = 0;  }
#line 2974 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 110:
#line 911 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = yystack_[0].value.as< ast::rExp > (); }
#line 2980 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 111:
#line 916 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::rExp > () = MAKE(try, yylhs.location, yystack_[3].value.as< ast::rExp > (), yystack_[2].value.as< ast::catches_type > (), yystack_[1].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ());
  }
#line 2988 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 112:
#line 920 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::rExp > () = MAKE(finally, yylhs.location, yystack_[2].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ());
  }
#line 2996 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 113:
#line 924 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::rExp > () = MAKE(throw, yylhs.location, yystack_[0].value.as< ast::rExp > ());
  }
#line 3004 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 114:
#line 953 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      yylhs.value.as< ast::rExp > () = MAKE(loop, yylhs.location, yystack_[1].location, yystack_[1].value.as< ast::flavor_type > (), yystack_[0].value.as< ast::rExp > ());
    }
#line 3012 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 115:
#line 957 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      yylhs.value.as< ast::rExp > () = MAKE(for, yylhs.location, yystack_[4].location, yystack_[4].value.as< ast::flavor_type > (), yystack_[2].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ());
    }
#line 3020 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 116:
#line 961 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      yylhs.value.as< ast::rExp > () = MAKE(for, yylhs.location, yystack_[8].location, yystack_[8].value.as< ast::flavor_type > (), yystack_[6].value.as< ast::rExp > (), yystack_[4].value.as< ast::rExp > (), yystack_[2].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ());
    }
#line 3028 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 117:
#line 965 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      yylhs.value.as< ast::rExp > () = MAKE(for, yylhs.location, yystack_[7].location, yystack_[7].value.as< ast::flavor_type > (), yystack_[4].location, yystack_[4].value.as< libport::Symbol > (), yystack_[2].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ());
    }
#line 3036 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 118:
#line 969 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
      yylhs.value.as< ast::rExp > () = MAKE(while, yylhs.location, yystack_[4].location, yystack_[4].value.as< ast::flavor_type > (), yystack_[2].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ());
    }
#line 3044 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 121:
#line 984 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(scope, yylhs.location, 0, yystack_[0].value.as< ast::rExp > ());  }
#line 3050 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 122:
#line 985 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(scope, yylhs.location, yystack_[2].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3056 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 123:
#line 997 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< bool > () = true; }
#line 3062 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 124:
#line 998 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< bool > () = false; }
#line 3068 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 125:
#line 1002 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(assert, yylhs.location, yystack_[1].value.as< ast::rExp > ()); }
#line 3074 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 126:
#line 1003 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(assert, yylhs.location, yystack_[1].value.as< ast::exps_type* > ()); }
#line 3080 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 127:
#line 1004 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(detach, yylhs.location, yystack_[3].value.as< bool > (), yystack_[1].value.as< ast::rExp > ()); }
#line 3086 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 128:
#line 1005 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(detach, yylhs.location, yystack_[1].value.as< bool > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3092 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 129:
#line 1006 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(isdef, yylhs.location, yystack_[1].value.as< ast::rCall > ()); }
#line 3098 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 130:
#line 1007 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(watch, yylhs.location, yystack_[1].value.as< ast::rExp > ()); }
#line 3104 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 131:
#line 1017 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rLValue > () = MAKE(call, yylhs.location, yystack_[0].value.as< libport::Symbol > ()); }
#line 3110 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 132:
#line 1018 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rLValue > () = MAKE(call, yylhs.location, yystack_[2].value.as< ast::rExp > (), yystack_[0].value.as< libport::Symbol > ()); }
#line 3116 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 133:
#line 1019 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rLValue > () = MAKE(call, yylhs.location, yystack_[2].value.as< ast::rExp > (), yystack_[0].value.as< libport::Symbol > ()); }
#line 3122 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 134:
#line 1023 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(get_slot, yylhs.location, yystack_[0].value.as< libport::Symbol > ()); }
#line 3128 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 135:
#line 1024 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(get_slot, yylhs.location, yystack_[3].value.as< ast::rExp > (), yystack_[0].value.as< libport::Symbol > ()); }
#line 3134 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 136:
#line 1028 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< libport::Symbol > (), yystack_[0].value.as< libport::Symbol > ()); }
#line 3140 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 137:
#line 1033 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::rExp > () = MAKE(binding, yylhs.location, false, yystack_[0].location, yystack_[0].value.as< ast::rExp > ());
  }
#line 3148 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 138:
#line 1037 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::rExp > () = MAKE(binding, yylhs.location, true, yystack_[0].location, yystack_[0].value.as< ast::rExp > ());
  }
#line 3156 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 139:
#line 1044 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::rExp > () = yystack_[0].value.as< ast::rLValue > ();
  }
#line 3164 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 140:
#line 1048 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::rExp > () = yystack_[1].value.as< ast::rLValue > ();
    yylhs.value.as< ast::rExp > ().unchecked_cast<ast::LValueArgs>()->arguments_set(yystack_[0].value.as< ast::exps_type* > ());
    yylhs.value.as< ast::rExp > ()->location_set(yylhs.location);
  }
#line 3174 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 141:
#line 1061 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    // Compiled as "id . new (args)".
    ast::exps_type* args = yystack_[0].value.as< ast::exps_type* > ();
    if (!args)
      args = new ast::exps_type();
    yylhs.value.as< ast::rExp > () = MAKE(call, yylhs.location, MAKE(call, yylhs.location, yystack_[1].value.as< libport::Symbol > ()), SYMBOL(new), args);
    up.deprecated(yylhs.location, "new Obj(x)", "Obj.new(x)");
  }
#line 3187 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 142:
#line 1072 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3193 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 143:
#line 1077 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< libport::Symbol > (), yystack_[0].value.as< libport::Symbol > ()); }
#line 3199 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 144:
#line 1088 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::rExp > () = MAKE(routine, yylhs.location, yystack_[2].value.as< bool > (), yystack_[1].location, yystack_[1].value.as< ast::Formals* > (), yystack_[0].value.as< ast::rExp > ());
  }
#line 3207 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 145:
#line 1104 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(float, yylhs.location, yystack_[0].value.as< libport::ufloat > ()); }
#line 3213 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 146:
#line 1114 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< libport::ufloat > () = yystack_[0].value.as< libport::ufloat > ();      }
#line 3219 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 147:
#line 1115 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< libport::ufloat > () = yystack_[1].value.as< libport::ufloat > () + yystack_[0].value.as< libport::ufloat > (); }
#line 3225 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 148:
#line 1129 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::dictionary_elt_type > ().first = yystack_[2].value.as< ast::rExp > ();
    yylhs.value.as< ast::dictionary_elt_type > ().second = yystack_[0].value.as< ast::rExp > ();
  }
#line 3234 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 149:
#line 1137 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    assocs_add(up, yystack_[0].location, yylhs.value.as< ast::dictionary_elts_type > (), yystack_[0].value.as< ast::dictionary_elt_type > ());
  }
#line 3242 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 150:
#line 1141 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    std::swap(yylhs.value.as< ast::dictionary_elts_type > (), yystack_[2].value.as< ast::dictionary_elts_type > ());
    assocs_add(up, yystack_[0].location, yylhs.value.as< ast::dictionary_elts_type > (), yystack_[0].value.as< ast::dictionary_elt_type > ());
  }
#line 3251 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 151:
#line 1148 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { /* nothing */ }
#line 3257 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 152:
#line 1149 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::dictionary_elts_type > (), yystack_[1].value.as< ast::dictionary_elts_type > ()); }
#line 3263 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 153:
#line 1154 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rDictionary > () = new ast::Dictionary(yylhs.location, yystack_[1].value.as< ast::dictionary_elts_type > ()); }
#line 3269 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 154:
#line 1165 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::exps_type* > () = new ast::exps_type; }
#line 3275 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 155:
#line 1166 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::exps_type* > (), yystack_[1].value.as< ast::exps_type* > ()); }
#line 3281 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 156:
#line 1167 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::exps_type* > (), yystack_[0].value.as< ast::exps_type* > ()); }
#line 3287 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 157:
#line 1171 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::exps_type* > () = yystack_[1].value.as< ast::exps_type* > (); }
#line 3293 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 158:
#line 1185 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::exps_type* > () = new ast::exps_type; }
#line 3299 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 159:
#line 1186 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::exps_type* > (), yystack_[1].value.as< ast::exps_type* > ()); }
#line 3305 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 160:
#line 1190 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::exps_type* > () = new ast::exps_type(1, yystack_[0].value.as< ast::rExp > ()); }
#line 3311 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 161:
#line 1191 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::exps_type* > (), yystack_[2].value.as< ast::exps_type* > ()); *yylhs.value.as< ast::exps_type* > () << yystack_[0].value.as< ast::rExp > ();}
#line 3317 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 162:
#line 1199 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ());  }
#line 3323 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 163:
#line 1200 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(float, yylhs.location, yystack_[0].value.as< libport::ufloat > ());  }
#line 3329 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 164:
#line 1201 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(float, yylhs.location, yystack_[0].value.as< libport::ufloat > ());  }
#line 3335 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 165:
#line 1202 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(string, yylhs.location, yystack_[0].value.as< std::string > ()); }
#line 3341 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 166:
#line 1203 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(list, yylhs.location, yystack_[1].value.as< ast::exps_type* > ()); }
#line 3347 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 167:
#line 1204 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(vector, yylhs.location, yystack_[1].value.as< ast::exps_type* > ()); }
#line 3353 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 168:
#line 1205 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = yystack_[0].value.as< ast::rDictionary > (); }
#line 3359 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 169:
#line 1206 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(tuple, yylhs.location, yystack_[0].value.as< ast::exps_type* > ()); }
#line 3365 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 170:
#line 1212 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< std::string > (), yystack_[0].value.as< std::string > ());  }
#line 3371 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 171:
#line 1213 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< std::string > (), yystack_[1].value.as< std::string > ()); yylhs.value.as< std::string > () += yystack_[0].value.as< std::string > (); }
#line 3377 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 172:
#line 1221 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(position, yylhs.location); }
#line 3383 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 173:
#line 1232 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::EventMatch > () = MAKE(event_match, yylhs.location, yystack_[4].value.as< ast::rExp > (), yystack_[2].value.as< ast::exps_type* > (), yystack_[1].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ());
  }
#line 3391 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 174:
#line 1239 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = 0; }
#line 3397 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 175:
#line 1240 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3403 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 176:
#line 1245 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = 0; }
#line 3409 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 177:
#line 1246 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3415 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 178:
#line 1256 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::rLValue > () = new ast::Subscript(yylhs.location, yystack_[1].value.as< ast::exps_type* > (), yystack_[3].value.as< ast::rExp > ());
  }
#line 3423 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 179:
#line 1271 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = new ast::This(yylhs.location); }
#line 3429 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 180:
#line 1272 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = new ast::CallMsg(yylhs.location); }
#line 3435 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 181:
#line 1276 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3441 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 182:
#line 1277 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::rExp > (), yystack_[1].value.as< ast::rExp > ()); }
#line 3447 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 183:
#line 1278 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(noop, yylhs.location); }
#line 3453 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 184:
#line 1279 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(call, yylhs.location, yystack_[2].value.as< ast::rExp > (), yystack_[1].value.as< libport::Symbol > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3459 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 185:
#line 1284 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3465 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 186:
#line 1285 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = new ast::Decrementation(yylhs.location, yystack_[0].value.as< ast::rLValue > (), false); }
#line 3471 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 187:
#line 1286 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = new ast::Incrementation(yylhs.location, yystack_[0].value.as< ast::rLValue > (), false); }
#line 3477 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 188:
#line 1287 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(call, yylhs.location, yystack_[0].value.as< ast::rExp > (), yystack_[1].value.as< libport::Symbol > (), new ast::exps_type()); }
#line 3483 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 189:
#line 1288 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(call, yylhs.location, yystack_[0].value.as< ast::rExp > (), yystack_[1].value.as< libport::Symbol > (), new ast::exps_type()); }
#line 3489 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 190:
#line 1289 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(call, yylhs.location, yystack_[0].value.as< ast::rExp > (), yystack_[1].value.as< libport::Symbol > (), new ast::exps_type()); }
#line 3495 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 191:
#line 1290 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(call, yylhs.location, yystack_[0].value.as< ast::rExp > (), yystack_[1].value.as< libport::Symbol > (), new ast::exps_type()); }
#line 3501 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 192:
#line 1315 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3507 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 193:
#line 1316 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(call, yylhs.location, yystack_[2].value.as< ast::rExp > (), yystack_[1].value.as< libport::Symbol > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3513 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 194:
#line 1317 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(call, yylhs.location, yystack_[2].value.as< ast::rExp > (), yystack_[1].value.as< libport::Symbol > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3519 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 195:
#line 1318 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(call, yylhs.location, yystack_[2].value.as< ast::rExp > (), yystack_[1].value.as< libport::Symbol > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3525 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 196:
#line 1319 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(call, yylhs.location, yystack_[2].value.as< ast::rExp > (), yystack_[1].value.as< libport::Symbol > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3531 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 197:
#line 1320 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(call, yylhs.location, yystack_[2].value.as< ast::rExp > (), yystack_[1].value.as< libport::Symbol > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3537 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 198:
#line 1321 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(call, yylhs.location, yystack_[2].value.as< ast::rExp > (), yystack_[1].value.as< libport::Symbol > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3543 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 199:
#line 1322 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(call, yylhs.location, yystack_[2].value.as< ast::rExp > (), yystack_[1].value.as< libport::Symbol > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3549 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 200:
#line 1323 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(call, yylhs.location, yystack_[2].value.as< ast::rExp > (), yystack_[1].value.as< libport::Symbol > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3555 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 201:
#line 1324 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(call, yylhs.location, yystack_[2].value.as< ast::rExp > (), yystack_[1].value.as< libport::Symbol > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3561 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 202:
#line 1325 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(call, yylhs.location, yystack_[2].value.as< ast::rExp > (), yystack_[1].value.as< libport::Symbol > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3567 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 203:
#line 1351 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< libport::Symbol > (), yystack_[0].value.as< libport::Symbol > ()); }
#line 3573 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 204:
#line 1352 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< libport::Symbol > (), yystack_[0].value.as< libport::Symbol > ()); }
#line 3579 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 205:
#line 1353 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< libport::Symbol > (), yystack_[0].value.as< libport::Symbol > ()); }
#line 3585 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 206:
#line 1354 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< libport::Symbol > (), yystack_[0].value.as< libport::Symbol > ()); }
#line 3591 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 207:
#line 1355 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< libport::Symbol > (), yystack_[0].value.as< libport::Symbol > ()); }
#line 3597 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 208:
#line 1356 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< libport::Symbol > (), yystack_[0].value.as< libport::Symbol > ()); }
#line 3603 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 209:
#line 1357 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< libport::Symbol > (), yystack_[0].value.as< libport::Symbol > ()); }
#line 3609 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 210:
#line 1358 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< libport::Symbol > (), yystack_[0].value.as< libport::Symbol > ()); }
#line 3615 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 211:
#line 1359 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< libport::Symbol > (), yystack_[0].value.as< libport::Symbol > ()); }
#line 3621 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 212:
#line 1360 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< libport::Symbol > (), yystack_[0].value.as< libport::Symbol > ()); }
#line 3627 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 213:
#line 1364 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(relation, yylhs.location, yystack_[1].value.as< ast::rExp > (), yystack_[0].value.as< ast::Factory::relations_type > ()); }
#line 3633 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 214:
#line 1369 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { /* empty */ }
#line 3639 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 215:
#line 1370 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::Factory::relations_type > (), MAKE(relation, yystack_[2].value.as< ast::Factory::relations_type > (), yystack_[1].value.as< libport::Symbol > (), yystack_[0].value.as< ast::rExp > ())); }
#line 3645 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 216:
#line 1384 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3651 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 217:
#line 1385 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(and, yylhs.location, yystack_[2].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3657 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 218:
#line 1386 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(or,  yylhs.location, yystack_[2].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3663 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 219:
#line 1391 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(call, yylhs.location, yystack_[0].value.as< ast::rExp > (), SYMBOL(has),    yystack_[2].value.as< ast::rExp > ()); }
#line 3669 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 220:
#line 1392 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = MAKE(call, yylhs.location, yystack_[0].value.as< ast::rExp > (), SYMBOL(hasNot), yystack_[3].value.as< ast::rExp > ()); }
#line 3675 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 221:
#line 1396 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = 0; }
#line 3681 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 222:
#line 1397 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3687 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 223:
#line 1408 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< unsigned > () = static_cast<unsigned int>(yystack_[0].value.as< libport::ufloat > ()); }
#line 3693 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 224:
#line 1417 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::rExp > () = new ast::Unscope(yylhs.location, yystack_[0].value.as< unsigned > ());
  }
#line 3701 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 225:
#line 1429 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::rExp > () = new ast::MetaExp(yylhs.location, yystack_[0].value.as< unsigned > ());
  }
#line 3709 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 226:
#line 1437 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::rLValue > () = new ast::MetaLValue(yylhs.location, new ast::exps_type(), yystack_[0].value.as< unsigned > ());
  }
#line 3717 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 227:
#line 1445 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::rLValue > () = new ast::MetaId(yylhs.location, 0, yystack_[0].value.as< unsigned > ());
  }
#line 3725 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 228:
#line 1449 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    yylhs.value.as< ast::rLValue > () = new ast::MetaCall(yylhs.location, 0, yystack_[3].value.as< ast::rExp > (), yystack_[0].value.as< unsigned > ());
  }
#line 3733 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 229:
#line 1457 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    {
    assert(yystack_[4].value.as< ast::rLValue > ().unsafe_cast<ast::LValueArgs>());
    assert(!yystack_[4].value.as< ast::rLValue > ().unsafe_cast<ast::LValueArgs>()->arguments_get());
    yylhs.value.as< ast::rExp > () = new ast::MetaArgs(yylhs.location, yystack_[4].value.as< ast::rLValue > (), yystack_[1].value.as< unsigned > ());
  }
#line 3743 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 230:
#line 1473 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::exps_type* > () = new ast::exps_type; }
#line 3749 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 231:
#line 1474 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::exps_type* > (), yystack_[1].value.as< ast::exps_type* > ()); }
#line 3755 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 232:
#line 1478 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::exps_type* > () = new ast::exps_type(1, yystack_[0].value.as< ast::rExp > ()); }
#line 3761 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 233:
#line 1479 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::exps_type* > (), yystack_[2].value.as< ast::exps_type* > ()); *yylhs.value.as< ast::exps_type* > () << yystack_[0].value.as< ast::rExp > (); }
#line 3767 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 234:
#line 1485 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::exps_type* > () = new ast::exps_type; }
#line 3773 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 235:
#line 1486 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::exps_type* > (), yystack_[1].value.as< ast::exps_type* > ()); }
#line 3779 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 236:
#line 1490 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::exps_type* > () = new ast::exps_type(1, yystack_[0].value.as< ast::rExp > ()); }
#line 3785 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 237:
#line 1491 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::exps_type* > (), yystack_[2].value.as< ast::exps_type* > ()); *yylhs.value.as< ast::exps_type* > () << yystack_[0].value.as< ast::rExp > (); }
#line 3791 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 238:
#line 1495 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::exps_type* > (), yystack_[2].value.as< ast::exps_type* > ()); *yylhs.value.as< ast::exps_type* > () << yystack_[0].value.as< ast::rExp > (); }
#line 3797 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 239:
#line 1500 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::exps_type* > (), yystack_[1].value.as< ast::exps_type* > ()); }
#line 3803 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 240:
#line 1504 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::exps_type* > () = 0; }
#line 3809 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 241:
#line 1505 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::exps_type* > (), yystack_[0].value.as< ast::exps_type* > ()); }
#line 3815 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 242:
#line 1515 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { /* empty */ }
#line 3821 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 243:
#line 1516 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::symbols_type > (), yystack_[1].value.as< ast::symbols_type > ()); yylhs.value.as< ast::symbols_type > ().push_back(yystack_[0].value.as< libport::Symbol > ()); }
#line 3827 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 244:
#line 1521 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > () = yystack_[0].value.as< ast::rExp > ();}
#line 3833 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 245:
#line 1526 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::rExp > ()=0;}
#line 3839 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 246:
#line 1527 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ());}
#line 3845 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 247:
#line 1532 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::Formal > () = ast::Formal(yystack_[1].value.as< libport::Symbol > (), 0, yystack_[0].value.as< ast::rExp > ());  }
#line 3851 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 248:
#line 1533 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::Formal > () = ast::Formal(yystack_[3].value.as< libport::Symbol > (), yystack_[1].value.as< ast::rExp > (), yystack_[0].value.as< ast::rExp > ()); }
#line 3857 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 249:
#line 1534 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::Formal > () = ast::Formal(yystack_[2].value.as< libport::Symbol > (), true); }
#line 3863 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 250:
#line 1540 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::Formals* > () = new ast::Formals(1, yystack_[0].value.as< ast::Formal > ()); }
#line 3869 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 251:
#line 1541 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::Formals* > (), yystack_[2].value.as< ast::Formals* > ()); *yylhs.value.as< ast::Formals* > () << yystack_[0].value.as< ast::Formal > (); }
#line 3875 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 252:
#line 1546 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::Formals* > () = new ast::Formals; }
#line 3881 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 253:
#line 1547 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::Formals* > (), yystack_[1].value.as< ast::Formals* > ()); }
#line 3887 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 254:
#line 1552 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { yylhs.value.as< ast::Formals* > () = 0; }
#line 3893 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;

  case 255:
#line 1553 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:870
    { std::swap(yylhs.value.as< ast::Formals* > (), yystack_[1].value.as< ast::Formals* > ()); }
#line 3899 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
    break;


#line 3903 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:870
            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short parser::yypact_ninf_ = -267;

  const short parser::yytable_ninf_ = -261;

  const short
  parser::yypact_[] =
  {
     336,  -267,   690,  1162,    51,  -267,    32,  -267,  -267,  -267,
      30,  -267,    46,  -267,    54,    72,   893,  1346,   977,  1498,
      82,    89,  1498,   108,   113,   766,   141,   146,   157,   -10,
     165,   176,  1162,   182,  -267,  -267,  1692,  1692,   -10,    94,
    1692,  1692,  1692,   203,   -11,  -267,  -267,   180,  -267,  -267,
    -267,  -267,  -267,  -267,  1650,  1650,  1650,  1650,   766,   170,
     170,   170,   170,  -267,    79,   132,  -267,  -267,   342,    22,
      18,   196,   538,   -10,   558,  -267,  -267,   160,  -267,  -267,
    -267,   164,  -267,  -267,  -267,   173,  -267,  -267,  -267,  -267,
    -267,   766,  1422,  1162,   -38,   213,   101,    59,  -267,    15,
     227,    11,  -267,  -267,   225,   224,   239,   236,   238,    55,
     248,   250,  -267,   357,  -267,  1422,  1422,  -267,  1422,    68,
     212,   558,  1422,  1422,  1422,  -267,  -267,  1422,  1270,  -267,
    1422,    -8,    11,   521,   521,   270,  -267,   257,   261,   276,
     462,   462,   462,  1422,  1422,  1422,   285,  -267,  -267,  -267,
    -267,   558,   193,   282,  -267,  -267,  -267,  -267,  -267,  -267,
    -267,  -267,  1162,  1162,  1422,  1422,   162,  1422,  1422,   103,
    -267,   298,   219,   113,  1162,  1422,    13,  1692,  1422,  -267,
    1053,  1422,  1422,  1422,  1422,  1422,  1422,  -267,  -267,   -10,
    -267,   227,   766,   766,   766,   766,   766,   766,   766,   766,
     766,   766,  1441,  -267,  -267,  1162,  1162,   558,    49,   299,
     117,   166,  -267,  -267,   -10,  1422,   311,  1422,  -267,  -267,
    -267,  1422,  -267,  -267,  -267,  -267,  1422,    49,   305,    70,
     121,   320,   113,   140,  -267,    49,   326,   163,    49,   329,
     189,  1574,   318,  -267,   191,   244,  1422,  -267,   249,   113,
     113,   -10,   349,  -267,   170,   263,   357,   351,   337,   300,
    1422,  -267,  -267,  -267,   766,  -267,  -267,   346,   226,     3,
    1422,   360,     8,    -3,  -267,  -267,   344,   367,   340,   350,
     353,   113,  -267,  -267,   357,   371,   -10,  -267,   170,  -267,
      11,   302,   170,   374,   357,   357,   357,   357,   357,   357,
    -267,   113,   565,   594,   728,   222,   222,   301,  -267,   301,
    -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,  -267,
    -267,  -267,   766,  -267,  -267,  1422,   285,   375,  1162,  1162,
    -267,   379,   357,    15,  -267,   357,   395,   381,  1162,   394,
    1162,  1422,   113,  -267,  1162,   402,  -267,   390,  -267,  -267,
     392,  1162,  1162,    69,  1422,  1162,  1162,    49,   398,  -267,
    -267,  -267,  1422,  -267,   383,  -267,  -267,   403,   388,  -267,
     384,   401,   113,  -267,  1422,  -267,  -267,   558,   422,  -267,
     387,     3,  -267,   103,  -267,  -267,    37,  -267,  -267,  -267,
    -267,  -267,  -267,  -267,   408,  -267,  -267,   558,   357,   360,
    1162,  -267,   424,  -267,  1162,  -267,  -267,   435,   118,   415,
    -267,  -267,   113,  -267,  -267,  1162,   424,  -267,  -267,  -267,
    1422,   259,  -267,  -267,   416,  1162,   357,   249,  -267,   -10,
    -267,   404,   407,  -267,   357,  1422,  -267,  -267,  1422,  1422,
     420,  -267,  -267,  -267,   434,  -267,  -267,  -267,   159,   113,
     424,  1422,  -267,  -267,   424,  -267,   413,  1162,  1162,   433,
    -267,  -267,  -267,   409,   436,   357,   211,   357,  -267,  1422,
    -267,  1422,   447,   439,  -267,  -267,   402,   357,  -267,  1162,
     440,   433,  1162,  -267,  -267,   421,  -267,   357,   460,  1162,
    -267,  -267,  -267,  1162,  -267,  -267,   404,  1162,   173,  -267,
     428,   173,  -267
  };

  const unsigned short
  parser::yydefact_[] =
  {
       0,     3,     0,    16,     0,     2,     0,   172,    85,    53,
       0,    86,     0,    54,     0,     0,     0,   234,     0,   221,
       0,     0,   221,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   242,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   123,   124,   143,   163,   146,
     145,   170,   180,   179,     0,     0,     0,     0,   158,     0,
       0,     0,     0,     4,     0,    17,    19,   121,    25,   254,
     185,     0,   139,   131,   214,   142,   162,   164,   168,   169,
     181,   165,   192,   216,     5,    12,    13,     1,    11,    10,
       9,     0,     0,    16,     0,     0,     0,   131,   151,   236,
     254,   185,   131,   149,   256,     0,     0,   256,     0,   236,
       0,     0,   156,   222,    84,     0,     0,   113,     0,     0,
     139,   137,     0,     0,     0,   143,   134,     0,    22,   114,
       0,     0,     0,   139,   139,     0,    46,     0,    47,     0,
      51,   186,   187,     0,   230,     0,   240,   190,   191,   189,
     188,   160,     0,   256,   223,   224,   225,   226,   227,     8,
       7,     6,     0,    18,     0,     0,   240,     0,     0,   252,
      57,     0,   254,     0,     0,   234,     0,     0,     0,   128,
     234,     0,     0,     0,     0,     0,     0,    71,    72,     0,
     140,   254,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   213,   147,   171,    16,    16,   138,   176,     0,
       0,     0,    27,    26,     0,     0,     0,   257,   152,   153,
     166,   257,   235,   183,   182,   157,   155,   176,     0,     0,
       0,   104,     0,    93,   100,   176,     0,     0,   176,     0,
       0,     0,     0,    23,    25,     0,     0,   243,    29,     0,
       0,    40,     0,    48,     0,     0,   232,     0,   258,     0,
     234,   241,   141,   167,   257,   159,    21,    20,    63,   219,
       0,   176,   217,   218,   261,   250,   256,     0,     0,     0,
       0,     0,   144,    24,   236,     0,     0,   133,     0,   132,
     184,     0,     0,     0,    69,    66,    70,    65,    68,    67,
      73,     0,   200,   201,   198,   202,   199,   194,   197,   193,
     196,   195,   209,   207,   208,   211,   210,   206,   205,   203,
     204,   212,     0,    15,    14,     0,   240,     0,     0,     0,
     129,     0,   148,     0,   150,   237,   237,     0,     0,     0,
       0,     0,     0,   112,     0,   109,   101,     0,    88,   130,
       0,     0,     0,   136,     0,     0,     0,   176,     0,    30,
      31,    32,     0,    34,    37,    38,    39,     0,   256,    42,
       0,     0,     0,   126,   259,   231,   125,   161,     0,    61,
      64,   220,    52,   257,   253,   255,   245,    58,    59,    55,
     178,   135,   228,   127,     0,   239,    56,   215,   177,   176,
       0,    79,    93,    28,     0,    81,    97,   107,   102,     0,
     106,    94,     0,   111,    87,     0,    93,    76,   120,   119,
       0,     0,   115,   118,     0,     0,    33,    29,    44,   257,
      41,     0,     0,   122,   233,     0,    62,   251,     0,     0,
       0,   246,   247,   229,   174,    78,    77,    80,    91,     0,
      93,     0,   105,   110,    93,    90,     0,    22,     0,    95,
      35,    43,    45,     0,     0,    60,   245,   244,   249,     0,
     173,     0,     0,     0,    98,   108,   109,   103,    89,     0,
       0,    95,     0,    75,    49,     0,   248,   175,     0,    16,
      82,    83,   117,     0,    74,    96,     0,    16,    92,   116,
       0,    99,    50
  };

  const short
  parser::yypgoto_[] =
  {
    -267,  -267,  -267,  -267,  -267,   -13,     2,    71,     6,   184,
      40,  -267,    56,  -267,   347,   450,  -267,  -267,   -14,  -267,
      36,   396,   112,  -267,    17,  -267,  -266,    19,  -267,  -267,
    -267,    27,  -267,   268,  -267,    28,  -267,  -267,    61,    -2,
     356,  -267,  -267,  -267,   288,  -267,  -267,  -267,  -267,  -267,
    -267,  -267,  -267,  -267,  -100,  -267,  -209,   231,  -267,  -267,
    -267,   485,   -53,  -267,  -267,    -7,   490,  -267,  -141,  -160,
    -267,  -267,    43,   128,  -267,  -267,  -125,  -105,  -267,  -267
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     4,     5,    63,    84,    85,    86,    65,   242,    66,
      67,   362,   363,   364,   249,    68,   367,   368,   463,   139,
     100,   172,   379,   380,   101,   473,   345,   483,   448,   474,
     233,   409,   342,   234,   450,   413,   420,    71,    72,   102,
      74,    75,    76,    77,   103,   104,   105,    78,   110,    79,
     152,   153,    80,    81,   209,   470,   327,    82,   322,    83,
     202,   114,   155,   257,   258,   293,   107,   112,   190,   262,
     131,   441,   442,   275,   276,   277,   173,   218,   375,   278
  };

  const short
  parser::yytable_[] =
  {
      73,    73,   222,    96,    64,   261,   271,   156,   157,   158,
     106,   144,   170,   145,    97,   228,   246,   165,   337,    70,
      70,   164,   236,  -261,   239,   261,   347,   126,   165,   350,
      73,   174,    88,    70,   175,   165,   135,   176,    69,    69,
      35,   175,   247,   438,   176,   171,   169,   281,   265,    70,
     439,    87,    69,   132,   132,   164,   286,   132,   132,   132,
     440,   164,   382,    35,   119,   125,   301,    91,    69,   165,
      92,   191,   170,    89,    90,   165,   164,   231,    93,   159,
     210,   216,   418,   325,   232,   224,   120,   216,   125,   419,
     165,    73,   216,   214,   215,   191,    94,   133,   134,   216,
     339,   140,   141,   142,   167,   171,   115,   177,   287,    35,
      70,   179,   136,   116,   177,   120,   120,   120,   120,   120,
     160,   161,   167,   168,   164,   288,    73,   164,   213,    69,
     326,   137,   118,   216,   125,    16,   446,   451,   165,   216,
     274,   165,   205,   206,   138,    70,   358,   329,   424,   231,
     455,   340,   120,  -260,   216,   344,   167,   168,   205,   206,
      73,    73,   167,   168,    69,   122,   399,   471,   285,   164,
     123,   384,    73,   472,   289,   162,   163,   167,   168,    70,
      70,   124,   270,   165,   476,   261,   260,   300,   478,   127,
     444,    70,   280,   349,   290,   164,   330,   164,    69,    69,
     128,   371,   216,    73,    73,   216,   130,   323,   324,   165,
      69,   165,   331,   282,   205,   206,   129,   164,    16,   352,
     178,   355,    70,    70,   439,   167,   168,   143,   167,   168,
     146,   165,   164,   266,   267,   392,   180,   203,   120,   394,
     212,    69,    69,   169,   204,   280,   165,   216,   154,   369,
     164,   169,   219,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   430,   165,   164,   217,   220,   223,   164,
     167,   168,   343,   216,   356,   166,   378,   221,   225,   165,
     187,   188,   189,   165,   391,   147,   148,   149,   150,   365,
     366,   226,   251,   372,   263,   216,   167,   168,   167,   168,
     254,   457,   120,   359,   360,   361,   164,   252,   164,   260,
     216,   253,   243,   197,   198,   199,   200,   201,   167,   168,
     165,   389,   165,   264,   279,   120,    73,    73,   216,   328,
     376,   270,   393,   167,   168,   338,    73,     1,    73,     2,
       3,   396,    73,   216,   341,    70,    70,   216,   164,    73,
      73,   167,   168,    73,    73,    70,   348,    70,   283,   351,
     354,    70,   165,   164,    69,    69,   167,   168,    70,    70,
     167,   168,    70,    70,    69,   370,    69,   165,   373,   374,
      69,   121,   410,   120,   216,   383,   216,    69,    69,   162,
     386,    69,    69,   198,   325,   200,   201,   385,    73,   390,
     387,   164,    73,   388,   395,   400,   403,   167,   168,   167,
     168,   404,   433,    73,   151,   165,   406,    70,   412,   164,
     414,    70,   415,    73,   427,  -238,   166,   461,   425,   429,
     428,   432,    70,   165,   431,   435,    69,   378,   443,   344,
      69,   216,    70,   479,   449,   452,   458,   207,   468,   167,
     168,    69,   453,   469,   462,    73,    73,   464,   482,   484,
     489,    69,   485,   480,   167,   168,   490,    99,   109,   113,
     493,   496,   113,   497,    70,    70,   498,    73,   502,   216,
      73,   250,   500,   460,   501,  -139,   180,    73,  -139,   475,
     211,    73,   436,    69,    69,    73,    70,   216,   488,    70,
     494,   346,   167,   168,   491,   334,    70,   117,   111,   486,
      70,   437,   401,   402,    70,    69,     0,     0,    69,     0,
     167,   168,   405,     0,   407,    69,     0,     0,   411,    69,
     187,   188,   189,    69,   248,   416,   417,     0,     0,   422,
     423,     0,   208,   -36,     0,   180,     0,     0,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,  -139,     0,
       0,     0,   180,     0,     0,   227,   229,     0,   230,     0,
       0,     0,   235,   237,   238,     0,     0,   240,   244,     0,
     245,     0,     0,     0,   445,     0,     0,     0,   447,   187,
     188,   189,     0,   255,   256,   259,     0,   121,     0,   454,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   459,
       0,     0,     0,     0,   268,   269,     0,   272,   273,     0,
     377,     0,     0,     0,     0,   284,     0,     0,   291,     0,
     284,   294,   295,   296,   297,   298,   299,     0,     0,     0,
       0,   243,   481,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   195,   196,   197,   198,   199,   200,
     201,     0,     0,   492,     0,   332,   495,   333,     0,     0,
       0,   335,     0,     0,     0,     0,   336,   499,   397,   192,
       0,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     -16,     6,     0,     0,     0,     7,   357,     8,     0,     0,
       9,    10,    11,     0,     0,     0,     0,    12,    13,    14,
     284,    15,    16,    17,    18,     0,     0,     0,     0,    19,
     381,    20,    21,    22,     0,    23,    24,    25,    26,    27,
      28,   -16,   -16,    29,     0,    30,    31,    32,    33,    34,
      35,     0,     0,     0,     0,     0,     0,    36,    37,    38,
      39,    40,     0,     0,     0,     0,     0,     0,    41,    42,
       0,    43,    44,    45,    46,    47,    48,    49,    50,     0,
      51,     7,    52,    53,    54,   398,     9,    10,    55,     0,
       0,    56,     0,    57,    13,     0,     0,    15,    16,    17,
      18,   408,     0,    58,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    25,   421,    27,     0,     0,     0,    29,
       0,     0,   426,   192,     0,     0,    35,   195,   196,   197,
     198,   199,   200,   201,   434,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,    42,     0,    43,    44,    45,
      46,    47,    48,    49,    50,     0,    51,     0,    52,    53,
      54,     0,     0,     0,    55,     0,     0,    56,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
     456,     0,     0,     0,     0,     0,    60,    61,    62,     0,
       0,     0,     0,     0,     0,   465,     0,     0,   466,   467,
       0,     0,     0,     0,    95,     0,     0,     0,     7,     0,
       8,   477,     0,     9,    10,    11,     0,     0,     0,     0,
      12,    13,    14,     0,    15,    16,    17,    18,     0,   487,
     -16,   408,    19,     0,    20,    21,    22,     0,    23,    24,
      25,    26,    27,    28,   -16,   -16,    29,     0,    30,    31,
      32,    33,    34,    35,     0,     0,     0,     0,     0,     0,
      36,    37,    38,    39,    40,     0,     0,     0,     0,     0,
       0,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,     0,    51,     0,    52,    53,    54,   108,     0,
       0,    55,     7,     0,    56,     0,    57,     9,    10,     0,
       0,     0,     0,     0,     0,    13,    58,     0,    15,    16,
      17,    18,    59,    60,    61,    62,     0,  -154,     0,     0,
       0,     0,     0,     0,    25,     0,    27,     0,     0,     0,
      29,     0,     0,     0,     0,     0,     0,    35,     0,     0,
       0,     0,     0,     0,    36,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,    42,     0,    43,    44,
      45,    46,    47,    48,    49,    50,     0,    51,     7,    52,
      53,    54,     0,     9,    10,    55,     0,     0,    56,     0,
      57,    13,     0,     0,    15,    16,    17,    18,     0,     0,
      58,     0,     0,     0,     0,     0,    59,    60,    61,    62,
      25,     0,    27,     0,     0,     0,    29,     0,     0,     0,
       0,     0,     0,    35,     0,     0,     0,     0,     0,     0,
      36,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,    42,     0,    43,    44,    45,    46,    47,    48,
      49,    50,     0,    51,     0,    52,    53,    54,     0,     0,
       0,    55,     0,     0,    56,     0,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,     0,     0,     0,
       0,     0,    59,    60,    61,    62,   292,     7,     0,     8,
       0,     0,     9,    10,    11,     0,     0,     0,     0,    12,
      13,    14,     0,    15,    16,    17,    18,     0,     0,     0,
       0,    19,     0,    20,    21,    22,     0,    23,    24,    25,
      26,    27,    28,     0,     0,    29,     0,    30,    31,    32,
      33,    34,    35,     0,     0,     0,     0,     0,     0,    36,
      37,    38,    39,    40,     0,     0,     0,     0,     0,     0,
      41,    42,     0,    43,    44,    45,    46,    47,    48,    49,
      50,     0,    51,     0,    52,    53,    54,     0,     0,     0,
      55,     0,     0,    56,     0,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,    59,    60,    61,    62,     7,     0,     8,     0,     0,
       9,    10,    11,     0,     0,     0,     0,    12,    13,    14,
       0,    15,    16,    17,    18,     0,     0,     0,     0,    19,
       0,    20,    21,    22,     0,    23,    24,   241,    26,    27,
      28,     0,     0,    29,     0,    30,    31,    32,    33,    34,
      35,     0,     0,     0,     0,     0,     0,    36,    37,    38,
      39,    40,     0,     0,     0,     0,     0,     0,    41,    42,
       0,    43,    44,    45,    46,    47,    48,    49,    50,     0,
      51,     7,    52,    53,    54,     0,     9,    10,    55,     0,
       0,    56,     0,    57,    13,     0,     0,    15,    16,    17,
      18,     0,     0,    58,     0,     0,     0,     0,     0,    59,
      60,    61,    62,    25,     0,    27,     0,     0,     0,    29,
       0,     0,     0,     0,     0,     0,    35,     0,     0,     0,
       0,     0,     0,    36,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,    42,     0,    43,    44,    45,
      46,    47,    48,    49,    50,    98,    51,     7,    52,    53,
      54,     0,     9,    10,    55,     0,     0,    56,     0,    57,
      13,     0,     0,    15,    16,    17,    18,     0,     0,    58,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    25,
       0,    27,     0,     0,     0,    29,     0,     0,     0,     0,
       0,     0,    35,     0,     0,     0,     0,     0,     0,    36,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      41,    42,     0,    43,    44,    45,    46,    47,    48,    49,
      50,     0,    51,     7,    52,    53,    54,     0,     9,    10,
      55,     0,     0,    56,     0,    57,    13,     0,     0,    15,
      16,    17,    18,     0,     0,    58,     0,     0,     0,     0,
       0,    59,    60,    61,    62,    25,     0,    27,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,    35,     0,
       0,     0,     0,     0,     0,    36,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,    42,     0,    43,
      44,    45,    46,    47,    48,    49,    50,     0,    51,     7,
      52,    53,    54,     0,     9,    10,    55,     0,     0,    56,
       0,    57,    13,     0,     0,    15,    16,    17,    18,     0,
       0,    58,     0,     0,     0,     0,     0,    59,    60,    61,
      62,    25,     0,    27,     0,     0,     0,    29,     0,     0,
       0,     0,     0,     0,   353,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    41,    42,     0,    43,    44,    45,    46,    47,
      48,    49,    50,     0,    51,     7,    52,    53,    54,     0,
       9,     0,    55,     0,     0,    56,     0,    57,    13,     0,
       0,    15,    16,    17,    18,     0,     0,    58,     0,     0,
       0,     0,     0,     0,    60,    61,    62,     0,     0,    27,
       0,     0,     0,    29,     0,     0,     0,     7,     0,     0,
      35,     0,     9,     0,     0,     0,     0,     0,     0,     0,
      13,     0,     0,    15,    16,    17,    18,     0,    41,    42,
       0,    43,    44,    45,    46,   125,    48,    49,    50,     0,
      51,    27,    52,    53,    54,    29,     0,     0,    55,     0,
       0,    56,    35,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,     0,     0,     0,     0,     0,     0,
      60,    61,    62,    43,    44,    45,    46,   125,    48,    49,
      50,     0,    51,     0,    52,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    58,     0,     0,     0,     0,
       0,     0,    60,    61,    62
  };

  const short
  parser::yycheck_[] =
  {
       2,     3,   107,    16,     2,   146,   166,    60,    61,    62,
      17,    22,    50,    24,    16,   115,    24,    20,   227,     2,
       3,     6,   122,    20,   124,   166,   235,    29,    20,   238,
      32,    13,     0,    16,    23,    20,    38,    26,     2,     3,
      50,    23,    50,     6,    26,    83,    24,   172,   153,    32,
      13,     0,    16,    36,    37,     6,    43,    40,    41,    42,
      23,     6,   271,    50,    24,    75,   191,    37,    32,    20,
      24,    73,    50,    41,    42,    20,     6,     9,    24,     0,
      93,    84,    13,    34,    16,    30,    25,    84,    75,    20,
      20,    93,    84,    34,    79,    97,    24,    36,    37,    84,
      30,    40,    41,    42,   107,    83,    24,    96,    95,    50,
      93,    71,    18,    24,    96,    54,    55,    56,    57,    58,
      41,    42,   107,   108,     6,   112,   128,     6,    27,    93,
      81,    37,    24,    84,    75,    22,   402,    19,    20,    84,
      37,    20,    41,    42,    50,   128,   246,    30,   357,     9,
     416,    30,    91,    50,    84,    15,   107,   108,    41,    42,
     162,   163,   107,   108,   128,    24,   326,     8,   175,     6,
      24,   276,   174,    14,   176,    43,    44,   107,   108,   162,
     163,    24,    20,    20,   450,   326,    24,   189,   454,    24,
     399,   174,    26,    30,   177,     6,    30,     6,   162,   163,
      24,   254,    84,   205,   206,    84,    24,   205,   206,    20,
     174,    20,   214,   173,    41,    42,    32,     6,    22,    30,
      24,    30,   205,   206,    13,   107,   108,    24,   107,   108,
      50,    20,     6,   162,   163,   288,    24,    77,   177,   292,
      27,   205,   206,    24,    80,    26,    20,    84,    78,   251,
       6,    24,    28,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   368,    20,     6,    41,    28,    30,     6,
     107,   108,   232,    84,    30,    84,    50,    41,    30,    20,
      68,    69,    70,    20,   286,    54,    55,    56,    57,   249,
     250,    41,    22,    30,   101,    84,   107,   108,   107,   108,
      24,    42,   241,    54,    55,    56,     6,    50,     6,    24,
      84,    50,   128,    91,    92,    93,    94,    95,   107,   108,
      20,   281,    20,    41,    26,   264,   328,   329,    84,    30,
      30,    20,    30,   107,   108,    30,   338,     1,   340,     3,
       4,   301,   344,    84,    24,   328,   329,    84,     6,   351,
     352,   107,   108,   355,   356,   338,    30,   340,   174,    30,
      42,   344,    20,     6,   328,   329,   107,   108,   351,   352,
     107,   108,   355,   356,   338,    26,   340,    20,    27,    42,
     344,    25,   342,   322,    84,    41,    84,   351,   352,    43,
      50,   355,   356,    92,    34,    94,    95,    30,   400,    28,
      50,     6,   404,    50,    30,    30,    27,   107,   108,   107,
     108,    30,   372,   415,    58,    20,    22,   400,    16,     6,
      30,   404,    30,   425,    41,    30,    84,   429,    30,    41,
      27,    30,   415,    20,    50,    13,   400,    50,    30,    15,
     404,    84,   425,    30,     9,    30,    30,    91,    28,   107,
     108,   415,   412,    19,    50,   457,   458,    50,    25,    50,
      13,   425,    26,   457,   107,   108,    27,    17,    18,    19,
      30,    50,    22,    13,   457,   458,   489,   479,    50,    84,
     482,   134,   496,   427,   497,    23,    24,   489,    26,   449,
      94,   493,   380,   457,   458,   497,   479,    84,   471,   482,
     481,   233,   107,   108,   476,   217,   489,    22,    18,   466,
     493,   383,   328,   329,   497,   479,    -1,    -1,   482,    -1,
     107,   108,   338,    -1,   340,   489,    -1,    -1,   344,   493,
      68,    69,    70,   497,    13,   351,   352,    -1,    -1,   355,
     356,    -1,    92,    22,    -1,    24,    -1,    -1,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,    96,    -1,
      -1,    -1,    24,    -1,    -1,   115,   116,    -1,   118,    -1,
      -1,    -1,   122,   123,   124,    -1,    -1,   127,   128,    -1,
     130,    -1,    -1,    -1,   400,    -1,    -1,    -1,   404,    68,
      69,    70,    -1,   143,   144,   145,    -1,   241,    -1,   415,
      62,    63,    64,    65,    66,    67,    68,    69,    70,   425,
      -1,    -1,    -1,    -1,   164,   165,    -1,   167,   168,    -1,
     264,    -1,    -1,    -1,    -1,   175,    -1,    -1,   178,    -1,
     180,   181,   182,   183,   184,   185,   186,    -1,    -1,    -1,
      -1,   457,   458,    85,    86,    87,    -1,    89,    90,    91,
      92,    93,    94,    95,    89,    90,    91,    92,    93,    94,
      95,    -1,    -1,   479,    -1,   215,   482,   217,    -1,    -1,
      -1,   221,    -1,    -1,    -1,    -1,   226,   493,   322,    85,
      -1,    87,    -1,    89,    90,    91,    92,    93,    94,    95,
       0,     1,    -1,    -1,    -1,     5,   246,     7,    -1,    -1,
      10,    11,    12,    -1,    -1,    -1,    -1,    17,    18,    19,
     260,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    29,
     270,    31,    32,    33,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    45,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    -1,
      80,     5,    82,    83,    84,   325,    10,    11,    88,    -1,
      -1,    91,    -1,    93,    18,    -1,    -1,    21,    22,    23,
      24,   341,    -1,   103,    -1,    -1,    -1,    -1,    -1,   109,
     110,   111,   112,    37,   354,    39,    -1,    -1,    -1,    43,
      -1,    -1,   362,    85,    -1,    -1,    50,    89,    90,    91,
      92,    93,    94,    95,   374,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    -1,    80,    -1,    82,    83,
      84,    -1,    -1,    -1,    88,    -1,    -1,    91,    -1,    93,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   103,
     420,    -1,    -1,    -1,    -1,    -1,   110,   111,   112,    -1,
      -1,    -1,    -1,    -1,    -1,   435,    -1,    -1,   438,   439,
      -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,     5,    -1,
       7,   451,    -1,    10,    11,    12,    -1,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    23,    24,    -1,   469,
      27,   471,    29,    -1,    31,    32,    33,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    45,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    -1,    82,    83,    84,     1,    -1,
      -1,    88,     5,    -1,    91,    -1,    93,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    18,   103,    -1,    21,    22,
      23,    24,   109,   110,   111,   112,    -1,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    39,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    -1,    80,     5,    82,
      83,    84,    -1,    10,    11,    88,    -1,    -1,    91,    -1,
      93,    18,    -1,    -1,    21,    22,    23,    24,    -1,    -1,
     103,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,   112,
      37,    -1,    39,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    -1,    82,    83,    84,    -1,    -1,
      -1,    88,    -1,    -1,    91,    -1,    93,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,   113,     5,    -1,     7,
      -1,    -1,    10,    11,    12,    -1,    -1,    -1,    -1,    17,
      18,    19,    -1,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    29,    -1,    31,    32,    33,    -1,    35,    36,    37,
      38,    39,    40,    -1,    -1,    43,    -1,    45,    46,    47,
      48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    80,    -1,    82,    83,    84,    -1,    -1,    -1,
      88,    -1,    -1,    91,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,
      -1,   109,   110,   111,   112,     5,    -1,     7,    -1,    -1,
      10,    11,    12,    -1,    -1,    -1,    -1,    17,    18,    19,
      -1,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    29,
      -1,    31,    32,    33,    -1,    35,    36,    37,    38,    39,
      40,    -1,    -1,    43,    -1,    45,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    -1,
      80,     5,    82,    83,    84,    -1,    10,    11,    88,    -1,
      -1,    91,    -1,    93,    18,    -1,    -1,    21,    22,    23,
      24,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,   109,
     110,   111,   112,    37,    -1,    39,    -1,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    58,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,     5,    82,    83,
      84,    -1,    10,    11,    88,    -1,    -1,    91,    -1,    93,
      18,    -1,    -1,    21,    22,    23,    24,    -1,    -1,   103,
      -1,    -1,    -1,    -1,    -1,   109,   110,   111,   112,    37,
      -1,    39,    -1,    -1,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    80,     5,    82,    83,    84,    -1,    10,    11,
      88,    -1,    -1,    91,    -1,    93,    18,    -1,    -1,    21,
      22,    23,    24,    -1,    -1,   103,    -1,    -1,    -1,    -1,
      -1,   109,   110,   111,   112,    37,    -1,    39,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    58,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    -1,    80,     5,
      82,    83,    84,    -1,    10,    11,    88,    -1,    -1,    91,
      -1,    93,    18,    -1,    -1,    21,    22,    23,    24,    -1,
      -1,   103,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,
     112,    37,    -1,    39,    -1,    -1,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    -1,    80,     5,    82,    83,    84,    -1,
      10,    -1,    88,    -1,    -1,    91,    -1,    93,    18,    -1,
      -1,    21,    22,    23,    24,    -1,    -1,   103,    -1,    -1,
      -1,    -1,    -1,    -1,   110,   111,   112,    -1,    -1,    39,
      -1,    -1,    -1,    43,    -1,    -1,    -1,     5,    -1,    -1,
      50,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    -1,    -1,    21,    22,    23,    24,    -1,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    -1,
      80,    39,    82,    83,    84,    43,    -1,    -1,    88,    -1,
      -1,    91,    50,    93,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
     110,   111,   112,    71,    72,    73,    74,    75,    76,    77,
      78,    -1,    80,    -1,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,   112
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     1,     3,     4,   115,   116,     1,     5,     7,    10,
      11,    12,    17,    18,    19,    21,    22,    23,    24,    29,
      31,    32,    33,    35,    36,    37,    38,    39,    40,    43,
      45,    46,    47,    48,    49,    50,    57,    58,    59,    60,
      61,    68,    69,    71,    72,    73,    74,    75,    76,    77,
      78,    80,    82,    83,    84,    88,    91,    93,   103,   109,
     110,   111,   112,   117,   120,   121,   123,   124,   129,   134,
     138,   151,   152,   153,   154,   155,   156,   157,   161,   163,
     166,   167,   171,   173,   118,   119,   120,     0,     0,    41,
      42,    37,    24,    24,    24,     1,   119,   153,    79,   129,
     134,   138,   153,   158,   159,   160,   179,   180,     1,   129,
     162,   180,   181,   129,   175,    24,    24,   175,    24,   124,
     152,   154,    24,    24,    24,    75,   153,    24,    24,   123,
      24,   184,   138,   152,   152,   153,    18,    37,    50,   133,
     152,   152,   152,    24,    22,    24,    50,   171,   171,   171,
     171,   154,   164,   165,    78,   176,   176,   176,   176,     0,
      41,    42,    43,    44,     6,    20,    84,   107,   108,    24,
      50,    83,   135,   190,    13,    23,    26,    96,    24,   124,
      24,    62,    63,    64,    65,    66,    67,    68,    69,    70,
     182,   153,    85,    86,    87,    89,    90,    91,    92,    93,
      94,    95,   174,    77,    80,    41,    42,   154,   129,   168,
     119,   135,    27,    27,    34,    79,    84,    41,   191,    28,
      28,    41,   191,    30,    30,    30,    41,   129,   168,   129,
     129,     9,    16,   144,   147,   129,   168,   129,   129,   168,
     129,    37,   122,   123,   129,   129,    24,    50,    13,   128,
     128,    22,    50,    50,    24,   129,   129,   177,   178,   129,
      24,   182,   183,   101,    41,   191,   121,   121,   129,   129,
      20,   183,   129,   129,    37,   187,   188,   189,   193,    26,
      26,   190,   124,   123,   129,   179,    43,    95,   112,   153,
     138,   129,   113,   179,   129,   129,   129,   129,   129,   129,
     153,   190,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   172,   120,   120,    34,    81,   170,    30,    30,
      30,   153,   129,   129,   158,   129,   129,   170,    30,    30,
      30,    24,   146,   124,    15,   140,   147,   170,    30,    30,
     170,    30,    30,    50,    42,    30,    30,   129,   168,    54,
      55,    56,   125,   126,   127,   124,   124,   130,   131,   153,
      26,   176,    30,    27,    42,   192,    30,   154,    50,   136,
     137,   129,   170,    41,   191,    30,    50,    50,    50,   124,
      28,   153,   176,    30,   176,    30,   124,   154,   129,   183,
      30,   123,   123,    27,    30,   123,    22,   123,   129,   145,
     124,   123,    16,   149,    30,    30,   123,   123,    13,    20,
     150,   129,   123,   123,   170,    30,   129,    41,    27,    41,
     191,    50,    30,   124,   129,    13,   136,   187,     6,    13,
      23,   185,   186,    30,   170,   123,   140,   123,   142,     9,
     148,    19,    30,   124,   123,   140,   129,    42,    30,   123,
     126,   153,    50,   132,    50,   129,   129,   129,    28,    19,
     169,     8,    14,   139,   143,   124,   140,   129,   140,    30,
     122,   123,    25,   141,    50,    26,   186,   129,   145,    13,
      27,   149,   123,    30,   141,   123,    50,    13,   119,   123,
     132,   119,    50
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,   114,   115,   116,   116,   116,   117,   117,   117,   117,
     117,   117,   118,   119,   119,   119,   120,   120,   120,   121,
     121,   121,   122,   122,   123,   123,   124,   124,   124,   125,
     125,   125,   125,   126,   127,   127,   128,   128,   129,   129,
     130,   130,   131,   131,   123,   132,   133,   133,   123,   123,
     123,   123,   123,   134,   134,   123,   123,   135,   135,   135,
     136,   137,   137,   129,   129,   129,   129,   129,   129,   129,
     129,   138,   138,   138,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   139,   139,   140,   140,   141,   141,   142,   142,   143,
     144,   144,   145,   145,   146,   146,   147,   148,   148,   149,
     149,   123,   123,   123,   123,   123,   123,   123,   123,   150,
     150,   138,   138,   151,   151,   138,   138,   138,   138,   138,
     138,   152,   152,   152,   138,   138,   153,   154,   154,   138,
     138,   155,   154,   153,   138,   156,   157,   157,   158,   159,
     159,   160,   160,   161,   162,   162,   162,   163,   164,   164,
     165,   165,   166,   166,   166,   166,   166,   166,   166,   166,
     167,   167,   166,   168,   169,   169,   170,   170,   152,   166,
     166,   138,   138,   138,   138,   171,   171,   171,   171,   171,
     171,   171,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   173,   174,   174,   129,   129,   129,   129,
     129,   175,   175,   176,   129,   138,   152,   152,   152,   138,
     177,   177,   178,   178,   179,   179,   180,   180,   181,   182,
     183,   183,   184,   184,   185,   186,   186,   187,   187,   187,
     188,   188,   189,   189,   190,   190,   191,   191,   192,   192,
     193,   193
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     3,     3,     0,     1,     2,     1,
       3,     3,     0,     1,     3,     1,     3,     3,     5,     0,
       1,     1,     1,     2,     1,     3,     0,     2,     4,     4,
       0,     2,     1,     3,     5,     1,     1,     1,     3,     7,
      10,     2,     4,     1,     1,     4,     4,     1,     3,     3,
       3,     1,     2,     3,     4,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     8,     7,     5,     6,     6,     5,
       6,     5,     8,     8,     2,     1,     1,     5,     4,     7,
       6,     0,     3,     0,     2,     0,     2,     0,     2,     4,
       1,     2,     1,     3,     0,     3,     3,     0,     2,     0,
       2,     5,     4,     2,     2,     5,     9,     8,     5,     1,
       1,     1,     5,     1,     1,     4,     4,     4,     2,     4,
       4,     1,     3,     3,     2,     4,     1,     2,     3,     1,
       2,     3,     1,     1,     3,     1,     1,     2,     3,     1,
       3,     1,     2,     3,     0,     2,     1,     3,     0,     2,
       1,     3,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     2,     1,     5,     0,     2,     0,     2,     4,     1,
       1,     1,     3,     3,     3,     1,     2,     2,     2,     2,
       2,     2,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     3,     1,     3,     3,     3,
       4,     0,     1,     1,     2,     2,     2,     2,     4,     5,
       0,     2,     1,     3,     0,     2,     1,     3,     3,     3,
       0,     1,     0,     2,     2,     0,     1,     3,     5,     4,
       1,     3,     0,     2,     0,     3,     0,     1,     0,     1,
       0,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of command\"", "error", "$undefined", "MODE_EXP", "MODE_EXPS",
  "\"__HERE__\"", "\"=\"", "\"break\"", "\"case\"", "\"catch\"",
  "\"closure\"", "\"const\"", "\"continue\"", "\":\"", "\"default\"",
  "\"else\"", "\"finally\"", "\"freezeif\"", "\"function\"", "\"if\"",
  "\"in\"", "\"isdef\"", "\"{\"", "\"[\"", "\"(\"", "\"onleave\"", "\".\"",
  "\"}\"", "\"]\"", "\"return\"", "\")\"", "\"stopif\"", "\"switch\"",
  "\"throw\"", "\"~\"", "\"timeout\"", "\"try\"", "\"var\"",
  "\"waituntil\"", "\"watch\"", "\"whenever\"", "\",\"", "\";\"", "\"&\"",
  "\"|\"", "\"every\"", "\"for\"", "\"loop\"", "\"while\"", "\"at\"",
  "\"identifier\"", "ASSIGN", "EMPTY", "UNARY", "\"private\"",
  "\"protected\"", "\"public\"", "\"class\"", "\"package\"", "\"enum\"",
  "\"external\"", "\"import\"", "\"^=\"", "\"-=\"", "\"%=\"", "\"+=\"",
  "\"/=\"", "\"*=\"", "\"--\"", "\"++\"", "\"->\"", "\"do\"", "\"assert\"",
  "\"detach\"", "\"disown\"", "\"new\"", "\"angle\"", "\"duration\"",
  "\"float\"", "\"=>\"", "\"string\"", "\"?\"", "\"call\"", "\"this\"",
  "\"!\"", "\"bitand\"", "\"bitor\"", "\"^\"", "\"compl\"", "\">>\"",
  "\"<<\"", "\"-\"", "\"%\"", "\"+\"", "\"/\"", "\"*\"", "\"**\"",
  "\"=~=\"", "\"==\"", "\"===\"", "\">=\"", "\">\"", "\"<=\"", "\"<\"",
  "\"!=\"", "\"!==\"", "\"~=\"", "\"&&\"", "\"||\"", "\"%unscope:\"",
  "\"%exp:\"", "\"%lvalue:\"", "\"%id:\"", "\"%exps:\"", "$accept",
  "start", "root", "root_exp", "root_exps", "stmts", "cstmt.opt", "cstmt",
  "stmt.opt", "stmt", "block", "visibility", "proto", "protos.1", "protos",
  "exp", "id.0", "id.1", "from", "event_or_function", "routine", "k1_id",
  "modifier", "modifiers", "primary-exp", "default.opt", "else.opt",
  "onleave.opt", "cases", "case", "catches.1", "match", "match.opt",
  "catch", "catch.opt", "finally.opt", "in_or_colon", "detach", "lvalue",
  "id", "bitor-exp", "new", "float-exp", "duration", "assoc", "assocs.1",
  "assocs", "dictionary", "tuple.exps", "tuple", "bitor-exps",
  "bitor-exps.1", "literal-exp", "string", "event_match", "guard.opt",
  "tilda.opt", "unary-exp", "rel-op", "rel-exp", "rel-ops", "exp.opt",
  "unsigned", "claims", "claims.1", "exps", "exps.1", "exps.2", "args",
  "args.opt", "identifiers", "typespec", "typespec.opt", "formal",
  "formals.1", "formals.0", "formals", "comma.opt", "semi.opt", "var.opt", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short
  parser::yyrline_[] =
  {
       0,   313,   313,   328,   329,   330,   336,   337,   338,   339,
     340,   341,   346,   358,   359,   360,   368,   369,   370,   375,
     376,   377,   387,   388,   393,   404,   408,   409,   413,   426,
     428,   429,   430,   435,   441,   442,   447,   448,   453,   462,
     478,   479,   483,   484,   489,   500,   509,   513,   523,   528,
     533,   546,   587,   600,   601,   607,   613,   660,   661,   662,
     673,   682,   686,   703,   707,   723,   724,   725,   726,   727,
     728,   736,   737,   748,   759,   763,   767,   771,   775,   779,
     783,   787,   791,   795,   800,   804,   808,   812,   816,   820,
     824,   841,   842,   847,   848,   854,   855,   865,   866,   872,
     881,   882,   887,   888,   891,   892,   896,   903,   904,   910,
     911,   915,   919,   923,   952,   956,   960,   964,   968,   974,
     974,   984,   985,   997,   998,  1002,  1003,  1004,  1005,  1006,
    1007,  1017,  1018,  1019,  1023,  1024,  1028,  1032,  1036,  1043,
    1047,  1060,  1072,  1077,  1087,  1104,  1114,  1115,  1128,  1136,
    1140,  1148,  1149,  1154,  1165,  1166,  1167,  1171,  1185,  1186,
    1190,  1191,  1199,  1200,  1201,  1202,  1203,  1204,  1205,  1206,
    1212,  1213,  1221,  1231,  1239,  1240,  1245,  1246,  1255,  1271,
    1272,  1276,  1277,  1278,  1279,  1284,  1285,  1286,  1287,  1288,
    1289,  1290,  1315,  1316,  1317,  1318,  1319,  1320,  1321,  1322,
    1323,  1324,  1325,  1351,  1352,  1353,  1354,  1355,  1356,  1357,
    1358,  1359,  1360,  1364,  1369,  1370,  1384,  1385,  1386,  1391,
    1392,  1396,  1397,  1408,  1416,  1428,  1436,  1444,  1448,  1456,
    1473,  1474,  1478,  1479,  1485,  1486,  1490,  1491,  1495,  1500,
    1504,  1505,  1515,  1516,  1521,  1526,  1527,  1532,  1533,  1534,
    1540,  1541,  1546,  1547,  1552,  1553,  1556,  1556,  1557,  1557,
    1558,  1558
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 4902 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.cc" // lalr1.cc:1181
#line 1560 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:1182


// The error function that 'bison' calls.
void
yy::parser::error(const location_type& l, const std::string& m)
{
  GD_CATEGORY(Urbi.Error);
  GD_FINFO_TRACE("%s: %s", l, m);
  up.error(l, m);
}

// Local Variables:
// mode: c++
// End:
