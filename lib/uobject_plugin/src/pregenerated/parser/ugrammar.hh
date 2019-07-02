// A Bison parser, made by GNU Bison 3.1.

// Skeleton interface for Bison LALR(1) parsers in C++

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
 ** \file /alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_YY_ALPHA_HOME_BEARCLAW_PROJECTS_URBIREBORD_URBIFORGE_URBI_BUILD_SYS_LINUX_X86_64_SRC_PARSER_UGRAMMAR_HH_INCLUDED
# define YY_YY_ALPHA_HOME_BEARCLAW_PROJECTS_URBIREBORD_URBIFORGE_URBI_BUILD_SYS_LINUX_X86_64_SRC_PARSER_UGRAMMAR_HH_INCLUDED
// //                    "%code requires" blocks.
#line 29 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:380

#include <ast/call.hh>
#include <ast/catches-type.hh>
#include <ast/dictionary.hh>
#include <ast/event-match.hh>
#include <ast/exps-type.hh>
#include <ast/factory.hh>
#include <ast/formal.hh>
#include <ast/fwd.hh>
#include <ast/symbols-type.hh>
#include <urbi/kernel/fwd.hh>
#include <libport/hash.hh>
#include <libport/ufloat.hh>
#include <list>
#include <urbi/object/symbols.hh>
#include <parser/fwd.hh>
#line 198 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/src/parser/ugrammar.y" // lalr1.cc:380

#include <ast/flavor.hh>

#line 66 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.hh" // lalr1.cc:380


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>
# include "stack.hh"
# include "location.hh"

#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif


namespace yy {
#line 150 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.hh" // lalr1.cc:380



  /// A char[S] buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current state.
  template <size_t S>
  struct variant
  {
    /// Type of *this.
    typedef variant<S> self_type;

    /// Empty construction.
    variant ()
      : yybuffer_ ()
    {}

    /// Construct and fill.
    template <typename T>
    variant (const T& t)
    {
      YYASSERT (sizeof (T) <= S);
      new (yyas_<T> ()) T (t);
    }

    /// Destruction, allowed only if empty.
    ~variant ()
    {}

    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    build ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    build (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as ()
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a other, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsability.
    /// Swapping between built and (possibly) non-built is done with
    /// variant::move ().
    template <typename T>
    void
    swap (self_type& other)
    {
      std::swap (as<T> (), other.as<T> ());
    }

    /// Move the content of \a other to this.
    ///
    /// Destroys \a other.
    template <typename T>
    void
    move (self_type& other)
    {
      build<T> ();
      swap<T> (other);
      other.destroy<T> ();
    }

    /// Copy the content of \a other to this.
    template <typename T>
    void
    copy (const self_type& other)
    {
      build<T> (other.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
    /// Prohibit blind copies.
    self_type& operator=(const self_type&);
    variant (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ ()
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[S];
    } yybuffer_;
  };


  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // event_match
      char dummy1[sizeof(ast::EventMatch)];

      // case
      char dummy2[sizeof(ast::Factory::case_type)];

      // cases
      char dummy3[sizeof(ast::Factory::cases_type)];

      // modifier
      char dummy4[sizeof(ast::Factory::modifier_type)];

      // rel-ops
      char dummy5[sizeof(ast::Factory::relations_type)];

      // formal
      char dummy6[sizeof(ast::Formal)];

      // formals.1
      // formals.0
      // formals
      char dummy7[sizeof(ast::Formals*)];

      // catches.1
      char dummy8[sizeof(ast::catches_type)];

      // assoc
      char dummy9[sizeof(ast::dictionary_elt_type)];

      // assocs.1
      // assocs
      char dummy10[sizeof(ast::dictionary_elts_type)];

      // protos.1
      // protos
      // tuple.exps
      // tuple
      // bitor-exps
      // bitor-exps.1
      // claims
      // claims.1
      // exps
      // exps.1
      // exps.2
      // args
      // args.opt
      char dummy11[sizeof(ast::exps_type*)];

      // ","
      // ";"
      // "&"
      // "|"
      // "every"
      // "for"
      // "loop"
      // "while"
      // "at"
      char dummy12[sizeof(ast::flavor_type)];

      // modifiers
      char dummy13[sizeof(ast::modifiers_type)];

      // k1_id
      char dummy14[sizeof(ast::rCall)];

      // catch
      char dummy15[sizeof(ast::rCatch)];

      // dictionary
      char dummy16[sizeof(ast::rDictionary)];

      // root
      // root_exp
      // root_exps
      // cstmt.opt
      // cstmt
      // stmt.opt
      // stmt
      // block
      // proto
      // exp
      // primary-exp
      // else.opt
      // onleave.opt
      // catch.opt
      // finally.opt
      // bitor-exp
      // new
      // float-exp
      // literal-exp
      // guard.opt
      // tilda.opt
      // unary-exp
      // rel-exp
      // exp.opt
      // typespec
      // typespec.opt
      char dummy17[sizeof(ast::rExp)];

      // lvalue
      char dummy18[sizeof(ast::rLValue)];

      // match
      // match.opt
      char dummy19[sizeof(ast::rMatch)];

      // stmts
      // default.opt
      char dummy20[sizeof(ast::rNary)];

      // id.0
      // id.1
      // identifiers
      char dummy21[sizeof(ast::symbols_type)];

      // routine
      // detach
      char dummy22[sizeof(bool)];

      // "identifier"
      // "^="
      // "-="
      // "%="
      // "+="
      // "/="
      // "*="
      // "new"
      // "!"
      // "bitand"
      // "bitor"
      // "^"
      // "compl"
      // ">>"
      // "<<"
      // "-"
      // "%"
      // "+"
      // "/"
      // "*"
      // "**"
      // "=~="
      // "=="
      // "==="
      // ">="
      // ">"
      // "<="
      // "<"
      // "!="
      // "!=="
      // "~="
      // "&&"
      // "||"
      // event_or_function
      // id
      // rel-op
      char dummy23[sizeof(libport::Symbol)];

      // "angle"
      // "duration"
      // "float"
      // duration
      char dummy24[sizeof(libport::ufloat)];

      // "string"
      // string
      char dummy25[sizeof(std::string)];

      // unsigned
      char dummy26[sizeof(unsigned)];
};

    /// Symbol semantic values.
    typedef variant<sizeof(union_type)> semantic_type;
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m);
      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        TOK_EOF = 0,
        TOK_MODE_EXP = 258,
        TOK_MODE_EXPS = 259,
        TOK___HERE__ = 260,
        TOK_EQ = 261,
        TOK_BREAK = 262,
        TOK_CASE = 263,
        TOK_CATCH = 264,
        TOK_CLOSURE = 265,
        TOK_CONST = 266,
        TOK_CONTINUE = 267,
        TOK_COLON = 268,
        TOK_DEFAULT = 269,
        TOK_ELSE = 270,
        TOK_FINALLY = 271,
        TOK_FREEZEIF = 272,
        TOK_FUNCTION = 273,
        TOK_IF = 274,
        TOK_IN = 275,
        TOK_ISDEF = 276,
        TOK_LBRACE = 277,
        TOK_LBRACKET = 278,
        TOK_LPAREN = 279,
        TOK_ONLEAVE = 280,
        TOK_POINT = 281,
        TOK_RBRACE = 282,
        TOK_RBRACKET = 283,
        TOK_RETURN = 284,
        TOK_RPAREN = 285,
        TOK_STOPIF = 286,
        TOK_SWITCH = 287,
        TOK_THROW = 288,
        TOK_TILDA = 289,
        TOK_TIMEOUT = 290,
        TOK_TRY = 291,
        TOK_VAR = 292,
        TOK_WAITUNTIL = 293,
        TOK_WATCH = 294,
        TOK_WHENEVER = 295,
        TOK_COMMA = 296,
        TOK_SEMICOLON = 297,
        TOK_AMPERSAND = 298,
        TOK_PIPE = 299,
        TOK_EVERY = 300,
        TOK_FOR = 301,
        TOK_LOOP = 302,
        TOK_WHILE = 303,
        TOK_AT = 304,
        TOK_IDENTIFIER = 305,
        TOK_ASSIGN = 306,
        TOK_EMPTY = 307,
        TOK_UNARY = 308,
        TOK_PRIVATE = 309,
        TOK_PROTECTED = 310,
        TOK_PUBLIC = 311,
        TOK_CLASS = 312,
        TOK_PACKAGE = 313,
        TOK_ENUM = 314,
        TOK_EXTERNAL = 315,
        TOK_IMPORT = 316,
        TOK_CARET_EQ = 317,
        TOK_MINUS_EQ = 318,
        TOK_PERCENT_EQ = 319,
        TOK_PLUS_EQ = 320,
        TOK_SLASH_EQ = 321,
        TOK_STAR_EQ = 322,
        TOK_MINUS_MINUS = 323,
        TOK_PLUS_PLUS = 324,
        TOK_MINUS_GT = 325,
        TOK_DO = 326,
        TOK_ASSERT = 327,
        TOK_DETACH = 328,
        TOK_DISOWN = 329,
        TOK_NEW = 330,
        TOK_ANGLE = 331,
        TOK_DURATION = 332,
        TOK_FLOAT = 333,
        TOK_EQ_GT = 334,
        TOK_STRING = 335,
        TOK_QUEST_MARK = 336,
        TOK_CALL = 337,
        TOK_THIS = 338,
        TOK_BANG = 339,
        TOK_BITAND = 340,
        TOK_BITOR = 341,
        TOK_CARET = 342,
        TOK_COMPL = 343,
        TOK_GT_GT = 344,
        TOK_LT_LT = 345,
        TOK_MINUS = 346,
        TOK_PERCENT = 347,
        TOK_PLUS = 348,
        TOK_SLASH = 349,
        TOK_STAR = 350,
        TOK_STAR_STAR = 351,
        TOK_EQ_TILDA_EQ = 352,
        TOK_EQ_EQ = 353,
        TOK_EQ_EQ_EQ = 354,
        TOK_GT_EQ = 355,
        TOK_GT = 356,
        TOK_LT_EQ = 357,
        TOK_LT = 358,
        TOK_BANG_EQ = 359,
        TOK_BANG_EQ_EQ = 360,
        TOK_TILDA_EQ = 361,
        TOK_AMPERSAND_AMPERSAND = 362,
        TOK_PIPE_PIPE = 363,
        TOK_PERCENT_UNSCOPE_COLON = 364,
        TOK_PERCENT_EXP_COLON = 365,
        TOK_PERCENT_LVALUE_COLON = 366,
        TOK_PERCENT_ID_COLON = 367,
        TOK_PERCENT_EXPS_COLON = 368
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols, and symbols from each type.

  basic_symbol (typename Base::kind_type t, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::EventMatch& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::Factory::case_type& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::Factory::cases_type& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::Factory::modifier_type& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::Factory::relations_type& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::Formal& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::Formals*& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::catches_type& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::dictionary_elt_type& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::dictionary_elts_type& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::exps_type*& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::flavor_type& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::modifiers_type& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::rCall& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::rCatch& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::rDictionary& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::rExp& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::rLValue& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::rMatch& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::rNary& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const ast::symbols_type& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const bool& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const libport::Symbol& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const libport::ufloat& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l);

  basic_symbol (typename Base::kind_type t, const unsigned& v, const location_type& l);


      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v,
                    const location_type& l);

      /// Destroy the symbol.
      ~basic_symbol ();

      /// Destroy contents, and record that is empty.
      void clear ();

      /// Whether empty.
      bool empty () const;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;

    // Symbol constructors declarations.
    static inline
    symbol_type
    make_EOF (const location_type& l);

    static inline
    symbol_type
    make_MODE_EXP (const location_type& l);

    static inline
    symbol_type
    make_MODE_EXPS (const location_type& l);

    static inline
    symbol_type
    make___HERE__ (const location_type& l);

    static inline
    symbol_type
    make_EQ (const location_type& l);

    static inline
    symbol_type
    make_BREAK (const location_type& l);

    static inline
    symbol_type
    make_CASE (const location_type& l);

    static inline
    symbol_type
    make_CATCH (const location_type& l);

    static inline
    symbol_type
    make_CLOSURE (const location_type& l);

    static inline
    symbol_type
    make_CONST (const location_type& l);

    static inline
    symbol_type
    make_CONTINUE (const location_type& l);

    static inline
    symbol_type
    make_COLON (const location_type& l);

    static inline
    symbol_type
    make_DEFAULT (const location_type& l);

    static inline
    symbol_type
    make_ELSE (const location_type& l);

    static inline
    symbol_type
    make_FINALLY (const location_type& l);

    static inline
    symbol_type
    make_FREEZEIF (const location_type& l);

    static inline
    symbol_type
    make_FUNCTION (const location_type& l);

    static inline
    symbol_type
    make_IF (const location_type& l);

    static inline
    symbol_type
    make_IN (const location_type& l);

    static inline
    symbol_type
    make_ISDEF (const location_type& l);

    static inline
    symbol_type
    make_LBRACE (const location_type& l);

    static inline
    symbol_type
    make_LBRACKET (const location_type& l);

    static inline
    symbol_type
    make_LPAREN (const location_type& l);

    static inline
    symbol_type
    make_ONLEAVE (const location_type& l);

    static inline
    symbol_type
    make_POINT (const location_type& l);

    static inline
    symbol_type
    make_RBRACE (const location_type& l);

    static inline
    symbol_type
    make_RBRACKET (const location_type& l);

    static inline
    symbol_type
    make_RETURN (const location_type& l);

    static inline
    symbol_type
    make_RPAREN (const location_type& l);

    static inline
    symbol_type
    make_STOPIF (const location_type& l);

    static inline
    symbol_type
    make_SWITCH (const location_type& l);

    static inline
    symbol_type
    make_THROW (const location_type& l);

    static inline
    symbol_type
    make_TILDA (const location_type& l);

    static inline
    symbol_type
    make_TIMEOUT (const location_type& l);

    static inline
    symbol_type
    make_TRY (const location_type& l);

    static inline
    symbol_type
    make_VAR (const location_type& l);

    static inline
    symbol_type
    make_WAITUNTIL (const location_type& l);

    static inline
    symbol_type
    make_WATCH (const location_type& l);

    static inline
    symbol_type
    make_WHENEVER (const location_type& l);

    static inline
    symbol_type
    make_COMMA (const ast::flavor_type& v, const location_type& l);

    static inline
    symbol_type
    make_SEMICOLON (const ast::flavor_type& v, const location_type& l);

    static inline
    symbol_type
    make_AMPERSAND (const ast::flavor_type& v, const location_type& l);

    static inline
    symbol_type
    make_PIPE (const ast::flavor_type& v, const location_type& l);

    static inline
    symbol_type
    make_EVERY (const ast::flavor_type& v, const location_type& l);

    static inline
    symbol_type
    make_FOR (const ast::flavor_type& v, const location_type& l);

    static inline
    symbol_type
    make_LOOP (const ast::flavor_type& v, const location_type& l);

    static inline
    symbol_type
    make_WHILE (const ast::flavor_type& v, const location_type& l);

    static inline
    symbol_type
    make_AT (const ast::flavor_type& v, const location_type& l);

    static inline
    symbol_type
    make_IDENTIFIER (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_ASSIGN (const location_type& l);

    static inline
    symbol_type
    make_EMPTY (const location_type& l);

    static inline
    symbol_type
    make_UNARY (const location_type& l);

    static inline
    symbol_type
    make_PRIVATE (const location_type& l);

    static inline
    symbol_type
    make_PROTECTED (const location_type& l);

    static inline
    symbol_type
    make_PUBLIC (const location_type& l);

    static inline
    symbol_type
    make_CLASS (const location_type& l);

    static inline
    symbol_type
    make_PACKAGE (const location_type& l);

    static inline
    symbol_type
    make_ENUM (const location_type& l);

    static inline
    symbol_type
    make_EXTERNAL (const location_type& l);

    static inline
    symbol_type
    make_IMPORT (const location_type& l);

    static inline
    symbol_type
    make_CARET_EQ (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_MINUS_EQ (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_PERCENT_EQ (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_PLUS_EQ (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_SLASH_EQ (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_STAR_EQ (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_MINUS_MINUS (const location_type& l);

    static inline
    symbol_type
    make_PLUS_PLUS (const location_type& l);

    static inline
    symbol_type
    make_MINUS_GT (const location_type& l);

    static inline
    symbol_type
    make_DO (const location_type& l);

    static inline
    symbol_type
    make_ASSERT (const location_type& l);

    static inline
    symbol_type
    make_DETACH (const location_type& l);

    static inline
    symbol_type
    make_DISOWN (const location_type& l);

    static inline
    symbol_type
    make_NEW (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_ANGLE (const libport::ufloat& v, const location_type& l);

    static inline
    symbol_type
    make_DURATION (const libport::ufloat& v, const location_type& l);

    static inline
    symbol_type
    make_FLOAT (const libport::ufloat& v, const location_type& l);

    static inline
    symbol_type
    make_EQ_GT (const location_type& l);

    static inline
    symbol_type
    make_STRING (const std::string& v, const location_type& l);

    static inline
    symbol_type
    make_QUEST_MARK (const location_type& l);

    static inline
    symbol_type
    make_CALL (const location_type& l);

    static inline
    symbol_type
    make_THIS (const location_type& l);

    static inline
    symbol_type
    make_BANG (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_BITAND (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_BITOR (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_CARET (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_COMPL (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_GT_GT (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_LT_LT (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_MINUS (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_PERCENT (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_PLUS (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_SLASH (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_STAR (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_STAR_STAR (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_EQ_TILDA_EQ (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_EQ_EQ (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_EQ_EQ_EQ (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_GT_EQ (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_GT (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_LT_EQ (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_LT (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_BANG_EQ (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_BANG_EQ_EQ (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_TILDA_EQ (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_AMPERSAND_AMPERSAND (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_PIPE_PIPE (const libport::Symbol& v, const location_type& l);

    static inline
    symbol_type
    make_PERCENT_UNSCOPE_COLON (const location_type& l);

    static inline
    symbol_type
    make_PERCENT_EXP_COLON (const location_type& l);

    static inline
    symbol_type
    make_PERCENT_LVALUE_COLON (const location_type& l);

    static inline
    symbol_type
    make_PERCENT_ID_COLON (const location_type& l);

    static inline
    symbol_type
    make_PERCENT_EXPS_COLON (const location_type& l);


    /// Build a parser object.
    parser (::parser::ParserImpl& up_yyarg);
    virtual ~parser ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

  private:
    /// This class is not copyable.
    parser (const parser&);
    parser& operator= (const parser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short yypact_ninf_;
    static const short yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned short yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short yytable_[];

  static const short yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Copy construct (for efficiency).
      stack_symbol_type (const stack_symbol_type& that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 1804,     ///< Last index in yytable_.
      yynnts_ = 80,  ///< Number of nonterminal symbols.
      yyfinal_ = 87, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 114  ///< Number of tokens.
    };


    // User arguments.
    ::parser::ParserImpl& up;
  };

  // Symbol number corresponding to token number t.
  inline
  parser::token_number_type
  parser::yytranslate_ (token_type t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113
    };
    const unsigned user_token_number_max_ = 368;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  inline
  parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
    , location ()
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    switch (other.type_get ())
    {
      case 168: // event_match
        value.copy< ast::EventMatch > (other.value);
        break;

      case 143: // case
        value.copy< ast::Factory::case_type > (other.value);
        break;

      case 142: // cases
        value.copy< ast::Factory::cases_type > (other.value);
        break;

      case 136: // modifier
        value.copy< ast::Factory::modifier_type > (other.value);
        break;

      case 174: // rel-ops
        value.copy< ast::Factory::relations_type > (other.value);
        break;

      case 187: // formal
        value.copy< ast::Formal > (other.value);
        break;

      case 188: // formals.1
      case 189: // formals.0
      case 190: // formals
        value.copy< ast::Formals* > (other.value);
        break;

      case 144: // catches.1
        value.copy< ast::catches_type > (other.value);
        break;

      case 158: // assoc
        value.copy< ast::dictionary_elt_type > (other.value);
        break;

      case 159: // assocs.1
      case 160: // assocs
        value.copy< ast::dictionary_elts_type > (other.value);
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
        value.copy< ast::exps_type* > (other.value);
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
        value.copy< ast::flavor_type > (other.value);
        break;

      case 137: // modifiers
        value.copy< ast::modifiers_type > (other.value);
        break;

      case 135: // k1_id
        value.copy< ast::rCall > (other.value);
        break;

      case 147: // catch
        value.copy< ast::rCatch > (other.value);
        break;

      case 161: // dictionary
        value.copy< ast::rDictionary > (other.value);
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
        value.copy< ast::rExp > (other.value);
        break;

      case 152: // lvalue
        value.copy< ast::rLValue > (other.value);
        break;

      case 145: // match
      case 146: // match.opt
        value.copy< ast::rMatch > (other.value);
        break;

      case 119: // stmts
      case 139: // default.opt
        value.copy< ast::rNary > (other.value);
        break;

      case 130: // id.0
      case 131: // id.1
      case 184: // identifiers
        value.copy< ast::symbols_type > (other.value);
        break;

      case 134: // routine
      case 151: // detach
        value.copy< bool > (other.value);
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
        value.copy< libport::Symbol > (other.value);
        break;

      case 76: // "angle"
      case 77: // "duration"
      case 78: // "float"
      case 157: // duration
        value.copy< libport::ufloat > (other.value);
        break;

      case 80: // "string"
      case 167: // string
        value.copy< std::string > (other.value);
        break;

      case 176: // unsigned
        value.copy< unsigned > (other.value);
        break;

      default:
        break;
    }

  }

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {
    (void) v;
    switch (this->type_get ())
    {
      case 168: // event_match
        value.copy< ast::EventMatch > (v);
        break;

      case 143: // case
        value.copy< ast::Factory::case_type > (v);
        break;

      case 142: // cases
        value.copy< ast::Factory::cases_type > (v);
        break;

      case 136: // modifier
        value.copy< ast::Factory::modifier_type > (v);
        break;

      case 174: // rel-ops
        value.copy< ast::Factory::relations_type > (v);
        break;

      case 187: // formal
        value.copy< ast::Formal > (v);
        break;

      case 188: // formals.1
      case 189: // formals.0
      case 190: // formals
        value.copy< ast::Formals* > (v);
        break;

      case 144: // catches.1
        value.copy< ast::catches_type > (v);
        break;

      case 158: // assoc
        value.copy< ast::dictionary_elt_type > (v);
        break;

      case 159: // assocs.1
      case 160: // assocs
        value.copy< ast::dictionary_elts_type > (v);
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
        value.copy< ast::exps_type* > (v);
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
        value.copy< ast::flavor_type > (v);
        break;

      case 137: // modifiers
        value.copy< ast::modifiers_type > (v);
        break;

      case 135: // k1_id
        value.copy< ast::rCall > (v);
        break;

      case 147: // catch
        value.copy< ast::rCatch > (v);
        break;

      case 161: // dictionary
        value.copy< ast::rDictionary > (v);
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
        value.copy< ast::rExp > (v);
        break;

      case 152: // lvalue
        value.copy< ast::rLValue > (v);
        break;

      case 145: // match
      case 146: // match.opt
        value.copy< ast::rMatch > (v);
        break;

      case 119: // stmts
      case 139: // default.opt
        value.copy< ast::rNary > (v);
        break;

      case 130: // id.0
      case 131: // id.1
      case 184: // identifiers
        value.copy< ast::symbols_type > (v);
        break;

      case 134: // routine
      case 151: // detach
        value.copy< bool > (v);
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
        value.copy< libport::Symbol > (v);
        break;

      case 76: // "angle"
      case 77: // "duration"
      case 78: // "float"
      case 157: // duration
        value.copy< libport::ufloat > (v);
        break;

      case 80: // "string"
      case 167: // string
        value.copy< std::string > (v);
        break;

      case 176: // unsigned
        value.copy< unsigned > (v);
        break;

      default:
        break;
    }
}


  // Implementation of basic_symbol constructor for each type.

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::EventMatch& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::Factory::case_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::Factory::cases_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::Factory::modifier_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::Factory::relations_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::Formal& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::Formals*& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::catches_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::dictionary_elt_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::dictionary_elts_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::exps_type*& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::flavor_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::modifiers_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::rCall& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::rCatch& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::rDictionary& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::rExp& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::rLValue& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::rMatch& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::rNary& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const ast::symbols_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const bool& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const libport::Symbol& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const libport::ufloat& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const unsigned& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  template <typename Base>
  parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::clear ()
  {
    // User destructor.
    symbol_number_type yytype = this->type_get ();
    basic_symbol<Base>& yysym = *this;
    (void) yysym;
    switch (yytype)
    {
   default:
      break;
    }

    // Type destructor.
  switch (yytype)
    {
      case 168: // event_match
        value.template destroy< ast::EventMatch > ();
        break;

      case 143: // case
        value.template destroy< ast::Factory::case_type > ();
        break;

      case 142: // cases
        value.template destroy< ast::Factory::cases_type > ();
        break;

      case 136: // modifier
        value.template destroy< ast::Factory::modifier_type > ();
        break;

      case 174: // rel-ops
        value.template destroy< ast::Factory::relations_type > ();
        break;

      case 187: // formal
        value.template destroy< ast::Formal > ();
        break;

      case 188: // formals.1
      case 189: // formals.0
      case 190: // formals
        value.template destroy< ast::Formals* > ();
        break;

      case 144: // catches.1
        value.template destroy< ast::catches_type > ();
        break;

      case 158: // assoc
        value.template destroy< ast::dictionary_elt_type > ();
        break;

      case 159: // assocs.1
      case 160: // assocs
        value.template destroy< ast::dictionary_elts_type > ();
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
        value.template destroy< ast::exps_type* > ();
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
        value.template destroy< ast::flavor_type > ();
        break;

      case 137: // modifiers
        value.template destroy< ast::modifiers_type > ();
        break;

      case 135: // k1_id
        value.template destroy< ast::rCall > ();
        break;

      case 147: // catch
        value.template destroy< ast::rCatch > ();
        break;

      case 161: // dictionary
        value.template destroy< ast::rDictionary > ();
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
        value.template destroy< ast::rExp > ();
        break;

      case 152: // lvalue
        value.template destroy< ast::rLValue > ();
        break;

      case 145: // match
      case 146: // match.opt
        value.template destroy< ast::rMatch > ();
        break;

      case 119: // stmts
      case 139: // default.opt
        value.template destroy< ast::rNary > ();
        break;

      case 130: // id.0
      case 131: // id.1
      case 184: // identifiers
        value.template destroy< ast::symbols_type > ();
        break;

      case 134: // routine
      case 151: // detach
        value.template destroy< bool > ();
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
        value.template destroy< libport::Symbol > ();
        break;

      case 76: // "angle"
      case 77: // "duration"
      case 78: // "float"
      case 157: // duration
        value.template destroy< libport::ufloat > ();
        break;

      case 80: // "string"
      case 167: // string
        value.template destroy< std::string > ();
        break;

      case 176: // unsigned
        value.template destroy< unsigned > ();
        break;

      default:
        break;
    }

    Base::clear ();
  }

  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 168: // event_match
        value.move< ast::EventMatch > (s.value);
        break;

      case 143: // case
        value.move< ast::Factory::case_type > (s.value);
        break;

      case 142: // cases
        value.move< ast::Factory::cases_type > (s.value);
        break;

      case 136: // modifier
        value.move< ast::Factory::modifier_type > (s.value);
        break;

      case 174: // rel-ops
        value.move< ast::Factory::relations_type > (s.value);
        break;

      case 187: // formal
        value.move< ast::Formal > (s.value);
        break;

      case 188: // formals.1
      case 189: // formals.0
      case 190: // formals
        value.move< ast::Formals* > (s.value);
        break;

      case 144: // catches.1
        value.move< ast::catches_type > (s.value);
        break;

      case 158: // assoc
        value.move< ast::dictionary_elt_type > (s.value);
        break;

      case 159: // assocs.1
      case 160: // assocs
        value.move< ast::dictionary_elts_type > (s.value);
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
        value.move< ast::exps_type* > (s.value);
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
        value.move< ast::flavor_type > (s.value);
        break;

      case 137: // modifiers
        value.move< ast::modifiers_type > (s.value);
        break;

      case 135: // k1_id
        value.move< ast::rCall > (s.value);
        break;

      case 147: // catch
        value.move< ast::rCatch > (s.value);
        break;

      case 161: // dictionary
        value.move< ast::rDictionary > (s.value);
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
        value.move< ast::rExp > (s.value);
        break;

      case 152: // lvalue
        value.move< ast::rLValue > (s.value);
        break;

      case 145: // match
      case 146: // match.opt
        value.move< ast::rMatch > (s.value);
        break;

      case 119: // stmts
      case 139: // default.opt
        value.move< ast::rNary > (s.value);
        break;

      case 130: // id.0
      case 131: // id.1
      case 184: // identifiers
        value.move< ast::symbols_type > (s.value);
        break;

      case 134: // routine
      case 151: // detach
        value.move< bool > (s.value);
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
        value.move< libport::Symbol > (s.value);
        break;

      case 76: // "angle"
      case 77: // "duration"
      case 78: // "float"
      case 157: // duration
        value.move< libport::ufloat > (s.value);
        break;

      case 80: // "string"
      case 167: // string
        value.move< std::string > (s.value);
        break;

      case 176: // unsigned
        value.move< unsigned > (s.value);
        break;

      default:
        break;
    }

    location = s.location;
  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const
  {
    return type;
  }

  inline
  parser::token_type
  parser::by_type::token () const
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368
    };
    return static_cast<token_type> (yytoken_number_[type]);
  }
  // Implementation of make_symbol for each symbol type.
  parser::symbol_type
  parser::make_EOF (const location_type& l)
  {
    return symbol_type (token::TOK_EOF, l);
  }

  parser::symbol_type
  parser::make_MODE_EXP (const location_type& l)
  {
    return symbol_type (token::TOK_MODE_EXP, l);
  }

  parser::symbol_type
  parser::make_MODE_EXPS (const location_type& l)
  {
    return symbol_type (token::TOK_MODE_EXPS, l);
  }

  parser::symbol_type
  parser::make___HERE__ (const location_type& l)
  {
    return symbol_type (token::TOK___HERE__, l);
  }

  parser::symbol_type
  parser::make_EQ (const location_type& l)
  {
    return symbol_type (token::TOK_EQ, l);
  }

  parser::symbol_type
  parser::make_BREAK (const location_type& l)
  {
    return symbol_type (token::TOK_BREAK, l);
  }

  parser::symbol_type
  parser::make_CASE (const location_type& l)
  {
    return symbol_type (token::TOK_CASE, l);
  }

  parser::symbol_type
  parser::make_CATCH (const location_type& l)
  {
    return symbol_type (token::TOK_CATCH, l);
  }

  parser::symbol_type
  parser::make_CLOSURE (const location_type& l)
  {
    return symbol_type (token::TOK_CLOSURE, l);
  }

  parser::symbol_type
  parser::make_CONST (const location_type& l)
  {
    return symbol_type (token::TOK_CONST, l);
  }

  parser::symbol_type
  parser::make_CONTINUE (const location_type& l)
  {
    return symbol_type (token::TOK_CONTINUE, l);
  }

  parser::symbol_type
  parser::make_COLON (const location_type& l)
  {
    return symbol_type (token::TOK_COLON, l);
  }

  parser::symbol_type
  parser::make_DEFAULT (const location_type& l)
  {
    return symbol_type (token::TOK_DEFAULT, l);
  }

  parser::symbol_type
  parser::make_ELSE (const location_type& l)
  {
    return symbol_type (token::TOK_ELSE, l);
  }

  parser::symbol_type
  parser::make_FINALLY (const location_type& l)
  {
    return symbol_type (token::TOK_FINALLY, l);
  }

  parser::symbol_type
  parser::make_FREEZEIF (const location_type& l)
  {
    return symbol_type (token::TOK_FREEZEIF, l);
  }

  parser::symbol_type
  parser::make_FUNCTION (const location_type& l)
  {
    return symbol_type (token::TOK_FUNCTION, l);
  }

  parser::symbol_type
  parser::make_IF (const location_type& l)
  {
    return symbol_type (token::TOK_IF, l);
  }

  parser::symbol_type
  parser::make_IN (const location_type& l)
  {
    return symbol_type (token::TOK_IN, l);
  }

  parser::symbol_type
  parser::make_ISDEF (const location_type& l)
  {
    return symbol_type (token::TOK_ISDEF, l);
  }

  parser::symbol_type
  parser::make_LBRACE (const location_type& l)
  {
    return symbol_type (token::TOK_LBRACE, l);
  }

  parser::symbol_type
  parser::make_LBRACKET (const location_type& l)
  {
    return symbol_type (token::TOK_LBRACKET, l);
  }

  parser::symbol_type
  parser::make_LPAREN (const location_type& l)
  {
    return symbol_type (token::TOK_LPAREN, l);
  }

  parser::symbol_type
  parser::make_ONLEAVE (const location_type& l)
  {
    return symbol_type (token::TOK_ONLEAVE, l);
  }

  parser::symbol_type
  parser::make_POINT (const location_type& l)
  {
    return symbol_type (token::TOK_POINT, l);
  }

  parser::symbol_type
  parser::make_RBRACE (const location_type& l)
  {
    return symbol_type (token::TOK_RBRACE, l);
  }

  parser::symbol_type
  parser::make_RBRACKET (const location_type& l)
  {
    return symbol_type (token::TOK_RBRACKET, l);
  }

  parser::symbol_type
  parser::make_RETURN (const location_type& l)
  {
    return symbol_type (token::TOK_RETURN, l);
  }

  parser::symbol_type
  parser::make_RPAREN (const location_type& l)
  {
    return symbol_type (token::TOK_RPAREN, l);
  }

  parser::symbol_type
  parser::make_STOPIF (const location_type& l)
  {
    return symbol_type (token::TOK_STOPIF, l);
  }

  parser::symbol_type
  parser::make_SWITCH (const location_type& l)
  {
    return symbol_type (token::TOK_SWITCH, l);
  }

  parser::symbol_type
  parser::make_THROW (const location_type& l)
  {
    return symbol_type (token::TOK_THROW, l);
  }

  parser::symbol_type
  parser::make_TILDA (const location_type& l)
  {
    return symbol_type (token::TOK_TILDA, l);
  }

  parser::symbol_type
  parser::make_TIMEOUT (const location_type& l)
  {
    return symbol_type (token::TOK_TIMEOUT, l);
  }

  parser::symbol_type
  parser::make_TRY (const location_type& l)
  {
    return symbol_type (token::TOK_TRY, l);
  }

  parser::symbol_type
  parser::make_VAR (const location_type& l)
  {
    return symbol_type (token::TOK_VAR, l);
  }

  parser::symbol_type
  parser::make_WAITUNTIL (const location_type& l)
  {
    return symbol_type (token::TOK_WAITUNTIL, l);
  }

  parser::symbol_type
  parser::make_WATCH (const location_type& l)
  {
    return symbol_type (token::TOK_WATCH, l);
  }

  parser::symbol_type
  parser::make_WHENEVER (const location_type& l)
  {
    return symbol_type (token::TOK_WHENEVER, l);
  }

  parser::symbol_type
  parser::make_COMMA (const ast::flavor_type& v, const location_type& l)
  {
    return symbol_type (token::TOK_COMMA, v, l);
  }

  parser::symbol_type
  parser::make_SEMICOLON (const ast::flavor_type& v, const location_type& l)
  {
    return symbol_type (token::TOK_SEMICOLON, v, l);
  }

  parser::symbol_type
  parser::make_AMPERSAND (const ast::flavor_type& v, const location_type& l)
  {
    return symbol_type (token::TOK_AMPERSAND, v, l);
  }

  parser::symbol_type
  parser::make_PIPE (const ast::flavor_type& v, const location_type& l)
  {
    return symbol_type (token::TOK_PIPE, v, l);
  }

  parser::symbol_type
  parser::make_EVERY (const ast::flavor_type& v, const location_type& l)
  {
    return symbol_type (token::TOK_EVERY, v, l);
  }

  parser::symbol_type
  parser::make_FOR (const ast::flavor_type& v, const location_type& l)
  {
    return symbol_type (token::TOK_FOR, v, l);
  }

  parser::symbol_type
  parser::make_LOOP (const ast::flavor_type& v, const location_type& l)
  {
    return symbol_type (token::TOK_LOOP, v, l);
  }

  parser::symbol_type
  parser::make_WHILE (const ast::flavor_type& v, const location_type& l)
  {
    return symbol_type (token::TOK_WHILE, v, l);
  }

  parser::symbol_type
  parser::make_AT (const ast::flavor_type& v, const location_type& l)
  {
    return symbol_type (token::TOK_AT, v, l);
  }

  parser::symbol_type
  parser::make_IDENTIFIER (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_IDENTIFIER, v, l);
  }

  parser::symbol_type
  parser::make_ASSIGN (const location_type& l)
  {
    return symbol_type (token::TOK_ASSIGN, l);
  }

  parser::symbol_type
  parser::make_EMPTY (const location_type& l)
  {
    return symbol_type (token::TOK_EMPTY, l);
  }

  parser::symbol_type
  parser::make_UNARY (const location_type& l)
  {
    return symbol_type (token::TOK_UNARY, l);
  }

  parser::symbol_type
  parser::make_PRIVATE (const location_type& l)
  {
    return symbol_type (token::TOK_PRIVATE, l);
  }

  parser::symbol_type
  parser::make_PROTECTED (const location_type& l)
  {
    return symbol_type (token::TOK_PROTECTED, l);
  }

  parser::symbol_type
  parser::make_PUBLIC (const location_type& l)
  {
    return symbol_type (token::TOK_PUBLIC, l);
  }

  parser::symbol_type
  parser::make_CLASS (const location_type& l)
  {
    return symbol_type (token::TOK_CLASS, l);
  }

  parser::symbol_type
  parser::make_PACKAGE (const location_type& l)
  {
    return symbol_type (token::TOK_PACKAGE, l);
  }

  parser::symbol_type
  parser::make_ENUM (const location_type& l)
  {
    return symbol_type (token::TOK_ENUM, l);
  }

  parser::symbol_type
  parser::make_EXTERNAL (const location_type& l)
  {
    return symbol_type (token::TOK_EXTERNAL, l);
  }

  parser::symbol_type
  parser::make_IMPORT (const location_type& l)
  {
    return symbol_type (token::TOK_IMPORT, l);
  }

  parser::symbol_type
  parser::make_CARET_EQ (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_CARET_EQ, v, l);
  }

  parser::symbol_type
  parser::make_MINUS_EQ (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_MINUS_EQ, v, l);
  }

  parser::symbol_type
  parser::make_PERCENT_EQ (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_PERCENT_EQ, v, l);
  }

  parser::symbol_type
  parser::make_PLUS_EQ (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_PLUS_EQ, v, l);
  }

  parser::symbol_type
  parser::make_SLASH_EQ (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_SLASH_EQ, v, l);
  }

  parser::symbol_type
  parser::make_STAR_EQ (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_STAR_EQ, v, l);
  }

  parser::symbol_type
  parser::make_MINUS_MINUS (const location_type& l)
  {
    return symbol_type (token::TOK_MINUS_MINUS, l);
  }

  parser::symbol_type
  parser::make_PLUS_PLUS (const location_type& l)
  {
    return symbol_type (token::TOK_PLUS_PLUS, l);
  }

  parser::symbol_type
  parser::make_MINUS_GT (const location_type& l)
  {
    return symbol_type (token::TOK_MINUS_GT, l);
  }

  parser::symbol_type
  parser::make_DO (const location_type& l)
  {
    return symbol_type (token::TOK_DO, l);
  }

  parser::symbol_type
  parser::make_ASSERT (const location_type& l)
  {
    return symbol_type (token::TOK_ASSERT, l);
  }

  parser::symbol_type
  parser::make_DETACH (const location_type& l)
  {
    return symbol_type (token::TOK_DETACH, l);
  }

  parser::symbol_type
  parser::make_DISOWN (const location_type& l)
  {
    return symbol_type (token::TOK_DISOWN, l);
  }

  parser::symbol_type
  parser::make_NEW (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_NEW, v, l);
  }

  parser::symbol_type
  parser::make_ANGLE (const libport::ufloat& v, const location_type& l)
  {
    return symbol_type (token::TOK_ANGLE, v, l);
  }

  parser::symbol_type
  parser::make_DURATION (const libport::ufloat& v, const location_type& l)
  {
    return symbol_type (token::TOK_DURATION, v, l);
  }

  parser::symbol_type
  parser::make_FLOAT (const libport::ufloat& v, const location_type& l)
  {
    return symbol_type (token::TOK_FLOAT, v, l);
  }

  parser::symbol_type
  parser::make_EQ_GT (const location_type& l)
  {
    return symbol_type (token::TOK_EQ_GT, l);
  }

  parser::symbol_type
  parser::make_STRING (const std::string& v, const location_type& l)
  {
    return symbol_type (token::TOK_STRING, v, l);
  }

  parser::symbol_type
  parser::make_QUEST_MARK (const location_type& l)
  {
    return symbol_type (token::TOK_QUEST_MARK, l);
  }

  parser::symbol_type
  parser::make_CALL (const location_type& l)
  {
    return symbol_type (token::TOK_CALL, l);
  }

  parser::symbol_type
  parser::make_THIS (const location_type& l)
  {
    return symbol_type (token::TOK_THIS, l);
  }

  parser::symbol_type
  parser::make_BANG (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_BANG, v, l);
  }

  parser::symbol_type
  parser::make_BITAND (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_BITAND, v, l);
  }

  parser::symbol_type
  parser::make_BITOR (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_BITOR, v, l);
  }

  parser::symbol_type
  parser::make_CARET (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_CARET, v, l);
  }

  parser::symbol_type
  parser::make_COMPL (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_COMPL, v, l);
  }

  parser::symbol_type
  parser::make_GT_GT (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_GT_GT, v, l);
  }

  parser::symbol_type
  parser::make_LT_LT (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_LT_LT, v, l);
  }

  parser::symbol_type
  parser::make_MINUS (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_MINUS, v, l);
  }

  parser::symbol_type
  parser::make_PERCENT (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_PERCENT, v, l);
  }

  parser::symbol_type
  parser::make_PLUS (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_PLUS, v, l);
  }

  parser::symbol_type
  parser::make_SLASH (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_SLASH, v, l);
  }

  parser::symbol_type
  parser::make_STAR (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_STAR, v, l);
  }

  parser::symbol_type
  parser::make_STAR_STAR (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_STAR_STAR, v, l);
  }

  parser::symbol_type
  parser::make_EQ_TILDA_EQ (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_EQ_TILDA_EQ, v, l);
  }

  parser::symbol_type
  parser::make_EQ_EQ (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_EQ_EQ, v, l);
  }

  parser::symbol_type
  parser::make_EQ_EQ_EQ (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_EQ_EQ_EQ, v, l);
  }

  parser::symbol_type
  parser::make_GT_EQ (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_GT_EQ, v, l);
  }

  parser::symbol_type
  parser::make_GT (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_GT, v, l);
  }

  parser::symbol_type
  parser::make_LT_EQ (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_LT_EQ, v, l);
  }

  parser::symbol_type
  parser::make_LT (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_LT, v, l);
  }

  parser::symbol_type
  parser::make_BANG_EQ (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_BANG_EQ, v, l);
  }

  parser::symbol_type
  parser::make_BANG_EQ_EQ (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_BANG_EQ_EQ, v, l);
  }

  parser::symbol_type
  parser::make_TILDA_EQ (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_TILDA_EQ, v, l);
  }

  parser::symbol_type
  parser::make_AMPERSAND_AMPERSAND (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_AMPERSAND_AMPERSAND, v, l);
  }

  parser::symbol_type
  parser::make_PIPE_PIPE (const libport::Symbol& v, const location_type& l)
  {
    return symbol_type (token::TOK_PIPE_PIPE, v, l);
  }

  parser::symbol_type
  parser::make_PERCENT_UNSCOPE_COLON (const location_type& l)
  {
    return symbol_type (token::TOK_PERCENT_UNSCOPE_COLON, l);
  }

  parser::symbol_type
  parser::make_PERCENT_EXP_COLON (const location_type& l)
  {
    return symbol_type (token::TOK_PERCENT_EXP_COLON, l);
  }

  parser::symbol_type
  parser::make_PERCENT_LVALUE_COLON (const location_type& l)
  {
    return symbol_type (token::TOK_PERCENT_LVALUE_COLON, l);
  }

  parser::symbol_type
  parser::make_PERCENT_ID_COLON (const location_type& l)
  {
    return symbol_type (token::TOK_PERCENT_ID_COLON, l);
  }

  parser::symbol_type
  parser::make_PERCENT_EXPS_COLON (const location_type& l)
  {
    return symbol_type (token::TOK_PERCENT_EXPS_COLON, l);
  }



} // yy
#line 3290 "/alpha/home/bearclaw/projects/urbirebord/urbiforge/urbi/build-sys-linux-x86_64/src/parser/ugrammar.hh" // lalr1.cc:380




#endif // !YY_YY_ALPHA_HOME_BEARCLAW_PROJECTS_URBIREBORD_URBIFORGE_URBI_BUILD_SYS_LINUX_X86_64_SRC_PARSER_UGRAMMAR_HH_INCLUDED
