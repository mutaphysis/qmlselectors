// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

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

#line 37 "cssselector.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "cssselector.tab.hh"

// User implementation prologue.

#line 51 "cssselector.tab.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 33 "cssselector.yy" // lalr1.cc:413

#include "cssselector.h"

#line 57 "cssselector.tab.cc" // lalr1.cc:413


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
      *yycdebug_ << std::endl;                  \
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
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace yy {
#line 143 "cssselector.tab.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  cssselector_parser::yytnamerr_ (const char *yystr)
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
  cssselector_parser::cssselector_parser (CssSelector& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  cssselector_parser::~cssselector_parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  inline
  cssselector_parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  cssselector_parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  cssselector_parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  cssselector_parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  cssselector_parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  cssselector_parser::symbol_number_type
  cssselector_parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  cssselector_parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  cssselector_parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
      switch (that.type_get ())
    {
      case 3: // ANGLE
      case 4: // BAD_STRING
      case 5: // BAD_URI
      case 9: // DASHMATCH
      case 14: // STRING
      case 15: // FREQ
      case 17: // HASH
      case 18: // IDENT
      case 19: // INCLUDES
      case 22: // LENGTH
      case 24: // NUMBER
      case 26: // PERCENTAGE
      case 27: // TIME
      case 28: // URI
      case 62: // property
      case 69: // id_selector
      case 70: // class_selector
      case 71: // type_selector
      case 73: // attrib_eq
      case 74: // attrib_value
      case 81: // expr
      case 82: // term
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  cssselector_parser::stack_symbol_type&
  cssselector_parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 3: // ANGLE
      case 4: // BAD_STRING
      case 5: // BAD_URI
      case 9: // DASHMATCH
      case 14: // STRING
      case 15: // FREQ
      case 17: // HASH
      case 18: // IDENT
      case 19: // INCLUDES
      case 22: // LENGTH
      case 24: // NUMBER
      case 26: // PERCENTAGE
      case 27: // TIME
      case 28: // URI
      case 62: // property
      case 69: // id_selector
      case 70: // class_selector
      case 71: // type_selector
      case 73: // attrib_eq
      case 74: // attrib_value
      case 81: // expr
      case 82: // term
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  cssselector_parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  cssselector_parser::yy_print_ (std::ostream& yyo,
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
            case 3: // ANGLE

#line 75 "cssselector.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 360 "cssselector.tab.cc" // lalr1.cc:636
        break;

      case 4: // BAD_STRING

#line 75 "cssselector.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 367 "cssselector.tab.cc" // lalr1.cc:636
        break;

      case 5: // BAD_URI

#line 75 "cssselector.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 374 "cssselector.tab.cc" // lalr1.cc:636
        break;

      case 9: // DASHMATCH

#line 75 "cssselector.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 381 "cssselector.tab.cc" // lalr1.cc:636
        break;

      case 14: // STRING

#line 75 "cssselector.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 388 "cssselector.tab.cc" // lalr1.cc:636
        break;

      case 15: // FREQ

#line 75 "cssselector.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 395 "cssselector.tab.cc" // lalr1.cc:636
        break;

      case 17: // HASH

#line 75 "cssselector.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 402 "cssselector.tab.cc" // lalr1.cc:636
        break;

      case 18: // IDENT

#line 75 "cssselector.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 409 "cssselector.tab.cc" // lalr1.cc:636
        break;

      case 19: // INCLUDES

#line 75 "cssselector.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 416 "cssselector.tab.cc" // lalr1.cc:636
        break;

      case 22: // LENGTH

#line 75 "cssselector.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 423 "cssselector.tab.cc" // lalr1.cc:636
        break;

      case 24: // NUMBER

#line 75 "cssselector.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 430 "cssselector.tab.cc" // lalr1.cc:636
        break;

      case 26: // PERCENTAGE

#line 75 "cssselector.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 437 "cssselector.tab.cc" // lalr1.cc:636
        break;

      case 27: // TIME

#line 75 "cssselector.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 444 "cssselector.tab.cc" // lalr1.cc:636
        break;

      case 28: // URI

#line 75 "cssselector.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 451 "cssselector.tab.cc" // lalr1.cc:636
        break;

      case 62: // property

#line 75 "cssselector.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 458 "cssselector.tab.cc" // lalr1.cc:636
        break;

      case 69: // id_selector

#line 75 "cssselector.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 465 "cssselector.tab.cc" // lalr1.cc:636
        break;

      case 70: // class_selector

#line 75 "cssselector.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 472 "cssselector.tab.cc" // lalr1.cc:636
        break;

      case 71: // type_selector

#line 75 "cssselector.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 479 "cssselector.tab.cc" // lalr1.cc:636
        break;

      case 73: // attrib_eq

#line 75 "cssselector.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 486 "cssselector.tab.cc" // lalr1.cc:636
        break;

      case 74: // attrib_value

#line 75 "cssselector.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 493 "cssselector.tab.cc" // lalr1.cc:636
        break;

      case 81: // expr

#line 75 "cssselector.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 500 "cssselector.tab.cc" // lalr1.cc:636
        break;

      case 82: // term

#line 75 "cssselector.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 507 "cssselector.tab.cc" // lalr1.cc:636
        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  inline
  void
  cssselector_parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  cssselector_parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  cssselector_parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  cssselector_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  cssselector_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  cssselector_parser::debug_level_type
  cssselector_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  cssselector_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline cssselector_parser::state_type
  cssselector_parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  cssselector_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  cssselector_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  cssselector_parser::parse ()
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

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 27 "cssselector.yy" // lalr1.cc:745
{
  // Initialize the initial location.
  yyla.location.begin.filename = yyla.location.end.filename = &driver._file;
}

#line 626 "cssselector.tab.cc" // lalr1.cc:745

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

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
        try
          {
            symbol_type yylookahead (yylex (driver));
            yyla.move (yylookahead);
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
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
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 3: // ANGLE
      case 4: // BAD_STRING
      case 5: // BAD_URI
      case 9: // DASHMATCH
      case 14: // STRING
      case 15: // FREQ
      case 17: // HASH
      case 18: // IDENT
      case 19: // INCLUDES
      case 22: // LENGTH
      case 24: // NUMBER
      case 26: // PERCENTAGE
      case 27: // TIME
      case 28: // URI
      case 62: // property
      case 69: // id_selector
      case 70: // class_selector
      case 71: // type_selector
      case 73: // attrib_eq
      case 74: // attrib_value
      case 81: // expr
      case 82: // term
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }


      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 4:
#line 88 "cssselector.yy" // lalr1.cc:859
    {
        driver.cssparser_handle_charset(yystack_[1].value.as< std::string > ());
    }
#line 763 "cssselector.tab.cc" // lalr1.cc:859
    break;

  case 37:
#line 167 "cssselector.yy" // lalr1.cc:859
    {
        // TODO PyObject_CallMethod((PyObject*)global_self, CSSPARSER_HANDLE_COMBINATOR, "s", "+");
    }
#line 771 "cssselector.tab.cc" // lalr1.cc:859
    break;

  case 38:
#line 171 "cssselector.yy" // lalr1.cc:859
    {
        // TODO PyObject_CallMethod((PyObject*)global_self, CSSPARSER_HANDLE_COMBINATOR, "s", ">");
    }
#line 779 "cssselector.tab.cc" // lalr1.cc:859
    break;

  case 41:
#line 183 "cssselector.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[1].value.as< std::string > ();
    }
#line 787 "cssselector.tab.cc" // lalr1.cc:859
    break;

  case 63:
#line 230 "cssselector.yy" // lalr1.cc:859
    {
        driver.cssparser_handle_id_selector(yystack_[0].value.as< std::string > ());
    }
#line 795 "cssselector.tab.cc" // lalr1.cc:859
    break;

  case 64:
#line 237 "cssselector.yy" // lalr1.cc:859
    {
        driver.cssparser_handle_class_selector(yystack_[0].value.as< std::string > ());
    }
#line 803 "cssselector.tab.cc" // lalr1.cc:859
    break;

  case 65:
#line 244 "cssselector.yy" // lalr1.cc:859
    {
        driver.cssparser_handle_type_selector(yystack_[0].value.as< std::string > ());
    }
#line 811 "cssselector.tab.cc" // lalr1.cc:859
    break;

  case 66:
#line 251 "cssselector.yy" // lalr1.cc:859
    {
        driver.cssparser_handle_empty_attribute_selector(yystack_[2].value.as< std::string > ());
    }
#line 819 "cssselector.tab.cc" // lalr1.cc:859
    break;

  case 67:
#line 255 "cssselector.yy" // lalr1.cc:859
    {
        driver.cssparser_handle_attribute_selector(yystack_[6].value.as< std::string > (), yystack_[4].value.as< std::string > (), yystack_[2].value.as< std::string > ());
    }
#line 827 "cssselector.tab.cc" // lalr1.cc:859
    break;

  case 68:
#line 262 "cssselector.yy" // lalr1.cc:859
    {   yylhs.value.as< std::string > () = "=";    }
#line 833 "cssselector.tab.cc" // lalr1.cc:859
    break;

  case 69:
#line 264 "cssselector.yy" // lalr1.cc:859
    {   yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();    }
#line 839 "cssselector.tab.cc" // lalr1.cc:859
    break;

  case 70:
#line 266 "cssselector.yy" // lalr1.cc:859
    {   yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();    }
#line 845 "cssselector.tab.cc" // lalr1.cc:859
    break;

  case 71:
#line 271 "cssselector.yy" // lalr1.cc:859
    {   yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();    }
#line 851 "cssselector.tab.cc" // lalr1.cc:859
    break;

  case 72:
#line 273 "cssselector.yy" // lalr1.cc:859
    {   yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();    }
#line 857 "cssselector.tab.cc" // lalr1.cc:859
    break;

  case 81:
#line 298 "cssselector.yy" // lalr1.cc:859
    {
        // TODO PyObject_CallMethod((PyObject*)global_self, CSSPARSER_HANDLE_DECLARATION, "ss", $1, $4);
    }
#line 865 "cssselector.tab.cc" // lalr1.cc:859
    break;

  case 82:
#line 302 "cssselector.yy" // lalr1.cc:859
    {
        // TODO PyObject_CallMethod((PyObject*)global_self, CSSPARSER_HANDLE_DECLARATION, "ss", $1, $4);
    }
#line 873 "cssselector.tab.cc" // lalr1.cc:859
    break;

  case 84:
#line 313 "cssselector.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[0].value.as< std::string > ();
    }
#line 881 "cssselector.tab.cc" // lalr1.cc:859
    break;

  case 89:
#line 326 "cssselector.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[1].value.as< std::string > ();
    }
#line 889 "cssselector.tab.cc" // lalr1.cc:859
    break;

  case 90:
#line 330 "cssselector.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[1].value.as< std::string > ();
    }
#line 897 "cssselector.tab.cc" // lalr1.cc:859
    break;

  case 91:
#line 334 "cssselector.yy" // lalr1.cc:859
    {
        yylhs.value.as< std::string > () = yystack_[1].value.as< std::string > ();
    }
#line 905 "cssselector.tab.cc" // lalr1.cc:859
    break;


#line 909 "cssselector.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
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
    yyerror_range[1].location = yystack_[yylen - 1].location;
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
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  cssselector_parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  cssselector_parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
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
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
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


  const signed char cssselector_parser::yypact_ninf_ = -119;

  const signed char cssselector_parser::yytable_ninf_ = -3;

  const short int
  cssselector_parser::yypact_[] =
  {
      -2,     1,    22,  -119,     6,  -119,    14,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,    -4,    69,    37,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,    66,   135,    44,  -119,  -119,  -119,
    -119,   125,   -10,  -119,   101,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,    52,   136,    80,    15,  -119,  -119,  -119,
    -119,  -119,  -119,    98,    37,    37,    37,  -119,  -119,    57,
    -119,  -119,    57,  -119,    58,    58,  -119,  -119,    72,  -119,
    -119,   127,   148,  -119,    85,    92,    99,  -119,    60,     0,
     135,   101,    58,    58,   101,    58,    58,  -119,  -119,    58,
    -119,  -119,   164,   133,  -119,  -119,  -119,    86,    10,  -119,
    -119,    90,   179,  -119,   -10,  -119,    58,    80,    58,    58,
    -119,  -119,  -119,    58,   187,    58,  -119,  -119,  -119,  -119,
    -119,  -119,    58,    58,  -119,  -119,  -119,  -119,    88,   133,
      58,  -119,    54,   212,   133,    58,  -119,  -119,  -119,    58,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,   121,   185,
    -119,  -119,  -119,  -119,  -119,    58,    -9,    58,   212,    58,
      58,    58,  -119,  -119,  -119,  -119,   239,  -119,  -119,    58,
    -119,   155,    58,    58,    58,    58,  -119,  -119,    58
  };

  const unsigned char
  cssselector_parser::yydefact_[] =
  {
       3,     0,     0,     5,     0,     1,     9,     4,     8,     7,
       6,   104,    11,    15,     0,    52,    10,   105,   104,   104,
      63,    65,   104,   104,     0,    53,     0,   104,    15,    15,
      15,     0,    44,    45,    48,    57,    61,    60,    55,    59,
      62,   104,   104,     0,     0,     0,     0,   104,    74,    73,
      56,    54,    64,     0,    13,    14,    12,   104,   104,    51,
     104,   104,     0,    58,    17,    16,   104,   104,     0,    25,
     104,     0,     0,   104,     0,     0,    76,   104,     0,    52,
       0,    50,    37,    38,    49,    27,    20,   104,   104,    21,
     104,   104,     0,    31,   104,   104,   104,     0,     0,   104,
     104,     0,     0,    78,    46,    47,    18,     0,    19,    23,
     104,   104,    30,    34,     0,    77,    75,    70,    69,    66,
      68,   104,    41,    43,   104,   104,   104,    26,    52,    33,
      29,   104,     0,     0,    80,    42,   104,    24,    32,    28,
      72,    71,   104,    99,    97,    98,   104,   101,   104,   104,
     104,    96,    94,    95,   100,   104,    40,    39,     0,    82,
      84,   104,    93,    92,    79,    22,     0,    89,     0,   103,
      90,    91,   104,   104,   104,   104,     0,    81,    86,    88,
      67,     0,    87,    83,    36,    35,    85,   104,   102
  };

  const short int
  cssselector_parser::yypgoto_[] =
  {
    -119,  -119,  -119,  -119,  -119,  -119,   156,  -119,  -119,  -119,
       9,    23,  -119,    47,  -119,  -119,  -119,  -119,  -119,    32,
    -119,   126,   142,   132,   -20,  -119,  -119,   -23,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,   -92,  -119,    36,  -118,    56,
    -119,  -119,   -11
  };

  const short int
  cssselector_parser::yydefgoto_[] =
  {
      -1,     2,     3,     6,    12,    15,    16,    13,    28,   128,
      68,    69,    29,    92,    75,   176,    62,   158,   101,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,   121,
     142,    40,    49,    97,   102,   103,   177,   159,   160,   161,
     162,   163,    93
  };

  const short int
  cssselector_parser::yytable_[] =
  {
      14,   112,    51,    59,    17,    50,     1,    43,    44,    17,
      18,    45,    46,    17,    63,     4,    53,    20,    21,   117,
       8,     9,     5,    17,    19,    60,    61,    10,    17,   118,
      64,    65,   180,    24,    11,     7,    76,   138,    25,    26,
      27,   178,   164,    41,    42,    73,    78,    79,    74,    82,
      83,   119,   120,    71,    72,    85,    86,    51,   186,    89,
      50,    63,    52,   178,    63,    17,    98,    17,   140,    -2,
      66,    17,   141,    17,    20,    21,   106,   107,    99,   108,
     109,    67,    47,   113,    48,   115,    20,    21,   122,   123,
      24,   100,    22,    17,    23,    80,    26,    27,    66,   129,
     130,    87,    24,    94,    88,    20,    21,    25,    26,    27,
     132,    17,    17,   133,   134,   135,    77,    96,    20,   136,
     139,    24,    95,   124,   143,   165,    25,    26,    27,   116,
     127,   166,   144,   145,    24,   167,   147,   168,   169,   170,
      26,    27,   114,   151,   171,   152,    17,   153,   154,    17,
     179,    99,    20,    21,    66,    57,    90,    58,   143,    88,
     137,   182,   183,   184,   185,    70,   144,   145,    24,   146,
     147,   148,   149,   150,    26,    27,   188,   151,    91,   152,
      88,   153,   154,   155,    54,    55,    56,   174,   143,   175,
     156,    81,   157,   110,    84,   111,   144,   145,   187,   146,
     147,   148,   149,   150,   181,   104,   173,   151,   125,   152,
     126,   153,   154,   155,   172,   143,   110,   174,   131,   175,
     156,   105,   157,   144,   145,    17,   146,   147,   148,   149,
     150,     0,     0,     0,   151,     0,   152,     0,   153,   154,
     155,     0,   143,     0,     0,     0,     0,   156,     0,   157,
     144,   145,     0,   146,   147,   148,   149,   150,     0,     0,
       0,   151,     0,   152,     0,   153,   154,   155,     0,     0,
       0,     0,     0,     0,   156,     0,   157
  };

  const short int
  cssselector_parser::yycheck_[] =
  {
      11,    93,    25,    13,    13,    25,     8,    18,    19,    13,
      14,    22,    23,    13,    34,    14,    27,    17,    18,     9,
       6,     7,     0,    13,    28,    35,    36,    13,    13,    19,
      41,    42,    41,    33,    20,    29,    47,   129,    38,    39,
      40,   159,   134,     6,     7,    30,    57,    58,    33,    60,
      61,    41,    42,    44,    45,    66,    67,    80,   176,    70,
      80,    81,    18,   181,    84,    13,    77,    13,    14,     0,
      18,    13,    18,    13,    17,    18,    87,    88,    18,    90,
      91,    29,    16,    94,    18,    96,    17,    18,    99,   100,
      33,    31,    23,    13,    25,    38,    39,    40,    18,   110,
     111,    29,    33,    18,    32,    17,    18,    38,    39,    40,
     121,    13,    13,   124,   125,   126,    18,    18,    17,    31,
     131,    33,    30,    33,     3,   136,    38,    39,    40,    43,
     107,   142,    11,    12,    33,   146,    15,   148,   149,   150,
      39,    40,    95,    22,   155,    24,    13,    26,    27,    13,
     161,    18,    17,    18,    18,    30,    29,    32,     3,    32,
     128,   172,   173,   174,   175,    29,    11,    12,    33,    14,
      15,    16,    17,    18,    39,    40,   187,    22,    30,    24,
      32,    26,    27,    28,    28,    29,    30,    32,     3,    34,
      35,    59,    37,    29,    62,    31,    11,    12,    43,    14,
      15,    16,    17,    18,   168,    79,    21,    22,    29,    24,
      31,    26,    27,    28,   158,     3,    29,    32,    31,    34,
      35,    79,    37,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    22,    -1,    24,    -1,    26,    27,
      28,    -1,     3,    -1,    -1,    -1,    -1,    35,    -1,    37,
      11,    12,    -1,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    22,    -1,    24,    -1,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    37
  };

  const unsigned char
  cssselector_parser::yystos_[] =
  {
       0,     8,    45,    46,    14,     0,    47,    29,     6,     7,
      13,    20,    48,    51,    86,    49,    50,    13,    14,    28,
      17,    18,    23,    25,    33,    38,    39,    40,    52,    56,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      75,     6,     7,    86,    86,    86,    86,    16,    18,    76,
      68,    71,    18,    86,    50,    50,    50,    30,    32,    13,
      35,    36,    60,    68,    86,    86,    18,    29,    54,    55,
      29,    54,    54,    30,    33,    58,    86,    18,    86,    86,
      38,    67,    86,    86,    67,    86,    86,    29,    32,    86,
      29,    30,    57,    86,    18,    30,    18,    77,    86,    18,
      31,    62,    78,    79,    65,    66,    86,    86,    86,    86,
      29,    31,    79,    86,    57,    86,    43,     9,    19,    41,
      42,    73,    86,    86,    33,    29,    31,    55,    53,    86,
      86,    31,    86,    86,    86,    86,    31,    63,    79,    86,
      14,    18,    74,     3,    11,    12,    14,    15,    16,    17,
      18,    22,    24,    26,    27,    28,    35,    37,    61,    81,
      82,    83,    84,    85,    79,    86,    86,    86,    86,    86,
      86,    86,    83,    21,    32,    34,    59,    80,    82,    86,
      41,    81,    86,    86,    86,    86,    82,    43,    86
  };

  const unsigned char
  cssselector_parser::yyr1_[] =
  {
       0,    44,    45,    46,    46,    47,    47,    47,    47,    48,
      48,    49,    49,    49,    49,    50,    50,    50,    51,    51,
      51,    51,    52,    53,    53,    54,    54,    55,    56,    56,
      57,    57,    57,    57,    58,    59,    59,    60,    60,    61,
      61,    62,    63,    63,    64,    64,    64,    64,    65,    65,
      65,    65,    66,    66,    67,    67,    67,    67,    67,    68,
      68,    68,    68,    69,    70,    71,    72,    72,    73,    73,
      73,    74,    74,    75,    76,    76,    77,    77,    78,    78,
      78,    79,    79,    80,    81,    81,    81,    82,    82,    82,
      82,    82,    82,    82,    83,    83,    83,    83,    83,    83,
      83,    83,    84,    85,    86,    86
  };

  const unsigned char
  cssselector_parser::yyr2_[] =
  {
       0,     2,     4,     0,     3,     0,     2,     2,     2,     0,
       2,     0,     3,     3,     3,     0,     3,     3,     7,     7,
       6,     6,     8,     0,     2,     1,     4,     2,     7,     6,
       2,     1,     4,     3,     3,     2,     2,     2,     2,     1,
       1,     2,     6,     5,     1,     1,     4,     4,     1,     3,
       3,     2,     0,     1,     2,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     2,     1,     5,     9,     1,     1,
       1,     1,     1,     2,     1,     4,     0,     2,     1,     4,
       3,     5,     4,     2,     1,     3,     2,     3,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     2,     0,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const cssselector_parser::yytname_[] =
  {
  "$end", "error", "$undefined", "ANGLE", "BAD_STRING", "BAD_URI", "CDC",
  "CDO", "CHARSET_SYM", "DASHMATCH", "DIMENSION", "EMS", "EXS", "S",
  "STRING", "FREQ", "FUNCTION", "HASH", "IDENT", "INCLUDES", "IMPORT_SYM",
  "IMPORTANT_SYM", "LENGTH", "MEDIA_SYM", "NUMBER", "PAGE_SYM",
  "PERCENTAGE", "TIME", "URI", "';'", "'{'", "'}'", "','", "':'", "'/'",
  "'+'", "'>'", "'-'", "'*'", "'.'", "'['", "']'", "'='", "')'", "$accept",
  "stylesheet", "charset", "comments", "import_block", "body",
  "subcomments", "import", "media", "rulesets", "media_list", "medium",
  "page", "page_declarations", "pseudo_page", "operator", "combinator",
  "unary_operator", "property", "ruleset", "selector_list",
  "complex_selector", "universal_selector", "compound_selector",
  "simple_selector", "id_selector", "class_selector", "type_selector",
  "attribute_selector", "attrib_eq", "attrib_value",
  "pseudo_class_selector", "pseudo_block", "pseudo_block_function_ident",
  "declarations", "declaration", "prio", "expr", "term", "term_numeral",
  "function", "hexcolor", "spaces", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  cssselector_parser::yyrline_[] =
  {
       0,    82,    82,    85,    87,    93,    95,    96,    97,   100,
     102,   105,   107,   108,   109,   112,   114,   115,   119,   120,
     121,   122,   126,   129,   131,   135,   136,   140,   145,   146,
     150,   151,   152,   153,   157,   161,   162,   166,   170,   177,
     178,   182,   189,   190,   194,   195,   196,   197,   201,   202,
     203,   204,   208,   210,   214,   215,   216,   217,   218,   222,
     223,   224,   225,   229,   236,   243,   250,   254,   261,   263,
     265,   270,   272,   277,   281,   282,   285,   287,   291,   292,
     293,   297,   301,   308,   312,   316,   317,   323,   324,   325,
     329,   333,   337,   338,   342,   343,   344,   345,   346,   347,
     348,   349,   353,   362,   365,   367
  };

  // Print the state stack on the debug stream.
  void
  cssselector_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  cssselector_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG



} // yy
#line 1432 "cssselector.tab.cc" // lalr1.cc:1167
#line 370 "cssselector.yy" // lalr1.cc:1168



void yy::cssselector_parser::error (const location_type& l, const std::string& m)
{
    driver.error(l, m);
}
