/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++

   Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

// Take the name prefix into account.
#define yylex   csslex

#include "cssselector.parser.hh"

/* User implementation prologue.  */
#line 75 "css/cssselector.yy"

#include "css/cssselectorscanner.h"
#include "css/cssselector.h"

#undef yylex
#define yylex driver.lexer->lex


/* Line 317 of lalr1.cc.  */
#line 52 "css/gen/cssselector.parser.cc"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG							\
  for (bool yydebugcond_ = yydebug_; yydebugcond_; yydebugcond_ = false)	\
    (*yycdebug_)

/* Enable debugging if requested.  */
#if YYDEBUG

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab

namespace css
{
#if YYERROR_VERBOSE

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
              /* Fall through.  */
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

#endif

  /// Build a parser object.
  cssselector_parser::cssselector_parser (class CssSelector& driver_yyarg)
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
      driver (driver_yyarg)
  {
  }

  cssselector_parser::~cssselector_parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  cssselector_parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  cssselector_parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif /* ! YYDEBUG */

  void
  cssselector_parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  cssselector_parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

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


  int
  cssselector_parser::parse ()
  {
    /// Look-ahead and look-ahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the look-ahead.
    semantic_type yylval;
    /// Location of the look-ahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    #line 34 "css/cssselector.yy"
{
  // Initialize the initial location.
/*  @$.begin.filename = @$.end.filename = &driver._file;*/
}
  /* Line 555 of yacc.c.  */
#line 289 "css/gen/cssselector.parser.cc"
    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;
    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without look-ahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a look-ahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Accept?  */
    if (yyn == yyfinal_)
      goto yyacceptlab;

    /* Shift the look-ahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted unless it is eof.  */
    if (yychar != yyeof_)
      yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:
#line 176 "css/cssselector.yy"
    {
        // TODO PyObject_CallMethod((PyObject*)global_self, CSSPARSER_HANDLE_COMBINATOR, "s", "+");
    ;}
    break;

  case 3:
#line 180 "css/cssselector.yy"
    {
        // TODO PyObject_CallMethod((PyObject*)global_self, CSSPARSER_HANDLE_COMBINATOR, "s", ">");
    ;}
    break;

  case 7:
#line 207 "css/cssselector.yy"
    {
        driver.cssparser_handle_new_selector_list();
    ;}
    break;

  case 13:
#line 223 "css/cssselector.yy"
    {
        driver.cssparser_handle_new_universal_selector();
    ;}
    break;

  case 18:
#line 234 "css/cssselector.yy"
    {
        driver.cssparser_handle_new_compound_selector();
    ;}
    break;

  case 22:
#line 244 "css/cssselector.yy"
    {
        driver.cssparser_handle_new_simple_selector();
    ;}
    break;

  case 23:
#line 251 "css/cssselector.yy"
    {
        driver.cssparser_handle_id_selector((yysemantic_stack_[(1) - (1)].stringVal));
    ;}
    break;

  case 24:
#line 258 "css/cssselector.yy"
    {
        driver.cssparser_handle_class_selector((yysemantic_stack_[(2) - (2)].stringVal));
    ;}
    break;

  case 25:
#line 265 "css/cssselector.yy"
    {
        driver.cssparser_handle_type_selector((yysemantic_stack_[(1) - (1)].stringVal));
    ;}
    break;

  case 26:
#line 272 "css/cssselector.yy"
    {
        driver.cssparser_handle_empty_attribute_selector((yysemantic_stack_[(5) - (3)].stringVal));
    ;}
    break;

  case 27:
#line 276 "css/cssselector.yy"
    {
        driver.cssparser_handle_attribute_selector((yysemantic_stack_[(9) - (3)].stringVal), (yysemantic_stack_[(9) - (5)].stringVal), (yysemantic_stack_[(9) - (7)].stringVal));
    ;}
    break;

  case 28:
#line 283 "css/cssselector.yy"
    {   (yyval.stringVal) = new std::string("=");    ;}
    break;

  case 29:
#line 285 "css/cssselector.yy"
    {   (yyval.stringVal) = (yysemantic_stack_[(1) - (1)].stringVal);    ;}
    break;

  case 30:
#line 287 "css/cssselector.yy"
    {   (yyval.stringVal) = (yysemantic_stack_[(1) - (1)].stringVal);    ;}
    break;

  case 31:
#line 292 "css/cssselector.yy"
    {   (yyval.stringVal) = (yysemantic_stack_[(1) - (1)].stringVal);    ;}
    break;

  case 32:
#line 294 "css/cssselector.yy"
    {   (yyval.stringVal) = (yysemantic_stack_[(1) - (1)].stringVal);    ;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 508 "css/gen/cssselector.parser.cc"
	default: break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse look-ahead token after shifting the error
       token.  */
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

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    if (yyn == yyfinal_)
      goto yyacceptlab;

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the look-ahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		   &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyeof_ && yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  cssselector_parser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char cssselector_parser::yypact_ninf_ = -30;
  const signed char
  cssselector_parser::yypact_[] =
  {
        10,   -30,   -30,    13,    36,   -13,   -30,     3,    43,   -30,
      22,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,
     -30,   -30,   -30,     8,   -30,   -30,    34,   -30,   -30,    34,
     -30,    45,   -30,   -30,     7,    36,    22,    -9,    -9,    22,
     -30,   -29,     0,    43,   -30,    -9,   -30,   -30,   -30,   -30,
     -30,   -30,     4,   -30,   -30,   -30,   -11,   -30
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  cssselector_parser::yydefact_[] =
  {
        12,    23,    25,     0,    13,     0,    38,     0,     4,     5,
       8,    17,    21,    20,    15,    19,    22,    38,    34,    33,
      16,    14,    24,     0,     1,    38,    11,    38,    38,     0,
      18,    36,    39,    38,    12,     0,    10,     2,     3,     9,
      38,     0,     0,     6,     7,    37,    35,    30,    29,    26,
      28,    38,     0,    32,    31,    38,     0,    27
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  cssselector_parser::yypgoto_[] =
  {
       -30,   -30,   -30,    23,    25,   -14,    -3,   -30,   -30,     2,
     -30,   -30,   -30,   -30,   -30,   -30,   -17
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  cssselector_parser::yydefgoto_[] =
  {
        -1,    29,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    51,    55,    16,    19,    41,    23
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char cssselector_parser::yytable_ninf_ = -1;
  const unsigned char
  cssselector_parser::yytable_[] =
  {
        31,    20,    32,    24,    32,    22,    21,    30,    34,    47,
      37,    38,    36,    32,    46,    39,    42,    32,    53,    48,
      32,    32,    54,    45,     1,     2,    33,     1,     2,    17,
      57,    18,    20,    30,    52,    25,    30,    21,    56,     1,
       3,    49,    50,     3,     0,     4,     5,     6,     4,     5,
       6,     1,     2,     1,     2,     3,    26,    43,    32,    44,
       0,     5,     6,    40,     0,     0,     0,     3,     0,     3,
       0,     0,    35,     5,     6,     5,     6,     0,    27,    28
  };

  /* YYCHECK.  */
  const signed char
  cssselector_parser::yycheck_[] =
  {
        17,     4,    13,     0,    13,    18,     4,    10,    25,     9,
      27,    28,    26,    13,    43,    29,    33,    13,    14,    19,
      13,    13,    18,    40,    17,    18,    18,    17,    18,    16,
      41,    18,    35,    36,    51,    32,    39,    35,    55,    17,
      33,    41,    42,    33,    -1,    38,    39,    40,    38,    39,
      40,    17,    18,    17,    18,    33,    13,    34,    13,    34,
      -1,    39,    40,    18,    -1,    -1,    -1,    33,    -1,    33,
      -1,    -1,    38,    39,    40,    39,    40,    -1,    35,    36
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  cssselector_parser::yystos_[] =
  {
         0,    17,    18,    33,    38,    39,    40,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    57,    16,    18,    58,
      50,    53,    18,    60,     0,    32,    13,    35,    36,    45,
      50,    60,    13,    18,    60,    38,    49,    60,    60,    49,
      18,    59,    60,    47,    48,    60,    43,     9,    19,    41,
      42,    55,    60,    14,    18,    56,    60,    41
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  cssselector_parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    59,
     123,   125,    44,    58,    47,    43,    62,    45,    42,    46,
      91,    93,    61,    41
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  cssselector_parser::yyr1_[] =
  {
         0,    44,    45,    45,    46,    46,    46,    46,    47,    47,
      47,    47,    48,    48,    49,    49,    49,    49,    49,    50,
      50,    50,    50,    51,    52,    53,    54,    54,    55,    55,
      55,    56,    56,    57,    58,    58,    59,    59,    60,    60
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  cssselector_parser::yyr2_[] =
  {
         0,     2,     2,     2,     1,     1,     4,     4,     1,     3,
       3,     2,     0,     1,     2,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     2,     1,     5,     9,     1,     1,
       1,     1,     1,     2,     1,     4,     0,     2,     0,     2
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const cssselector_parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "ANGLE", "BAD_STRING",
  "BAD_URI", "CDC", "CDO", "CHARSET_SYM", "DASHMATCH", "DIMENSION", "EMS",
  "EXS", "S", "STRING", "FREQ", "FUNCTION", "HASH", "IDENT", "INCLUDES",
  "IMPORT_SYM", "IMPORTANT_SYM", "LENGTH", "MEDIA_SYM", "NUMBER",
  "PAGE_SYM", "PERCENTAGE", "TIME", "URI", "';'", "'{'", "'}'", "','",
  "':'", "'/'", "'+'", "'>'", "'-'", "'*'", "'.'", "'['", "']'", "'='",
  "')'", "$accept", "combinator", "selector_list", "complex_selector",
  "universal_selector", "compound_selector", "simple_selector",
  "id_selector", "class_selector", "type_selector", "attribute_selector",
  "attrib_eq", "attrib_value", "pseudo_class_selector", "pseudo_block",
  "pseudo_block_function_ident", "spaces", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const cssselector_parser::rhs_number_type
  cssselector_parser::yyrhs_[] =
  {
        46,     0,    -1,    35,    60,    -1,    36,    60,    -1,    47,
      -1,    48,    -1,    46,    32,    60,    47,    -1,    46,    32,
      60,    48,    -1,    49,    -1,    47,    45,    49,    -1,    47,
      13,    49,    -1,    47,    13,    -1,    -1,    38,    -1,    38,
      53,    -1,    53,    -1,    38,    50,    -1,    50,    -1,    49,
      50,    -1,    54,    -1,    52,    -1,    51,    -1,    57,    -1,
      17,    -1,    39,    18,    -1,    18,    -1,    40,    60,    18,
      60,    41,    -1,    40,    60,    18,    60,    55,    60,    56,
      60,    41,    -1,    42,    -1,    19,    -1,     9,    -1,    18,
      -1,    14,    -1,    33,    58,    -1,    18,    -1,    16,    60,
      59,    43,    -1,    -1,    18,    60,    -1,    -1,    60,    13,
      -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  cssselector_parser::yyprhs_[] =
  {
         0,     0,     3,     6,     9,    11,    13,    18,    23,    25,
      29,    33,    36,    37,    39,    42,    44,    47,    49,    52,
      54,    56,    58,    60,    62,    65,    67,    73,    83,    85,
      87,    89,    91,    93,    96,    98,   103,   104,   107,   108
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  cssselector_parser::yyrline_[] =
  {
         0,    91,   175,   179,   203,   204,   205,   206,   213,   214,
     215,   216,   220,   222,   229,   230,   231,   232,   233,   240,
     241,   242,   243,   250,   257,   264,   271,   275,   282,   284,
     286,   291,   293,   298,   302,   303,   306,   308,   386,   388
  };

  // Print the state stack on the debug stream.
  void
  cssselector_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  cssselector_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "), ";
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  cssselector_parser::token_number_type
  cssselector_parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,    38,    35,    32,    37,    39,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    29,
       2,    42,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
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
      25,    26,    27,    28
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int cssselector_parser::yyeof_ = 0;
  const int cssselector_parser::yylast_ = 79;
  const int cssselector_parser::yynnts_ = 17;
  const int cssselector_parser::yyempty_ = -2;
  const int cssselector_parser::yyfinal_ = 24;
  const int cssselector_parser::yyterror_ = 1;
  const int cssselector_parser::yyerrcode_ = 256;
  const int cssselector_parser::yyntokens_ = 44;

  const unsigned int cssselector_parser::yyuser_token_number_max_ = 283;
  const cssselector_parser::token_number_type cssselector_parser::yyundef_token_ = 2;

} // namespace css

#line 391 "css/cssselector.yy"



void css::cssselector_parser::error (const location_type& l, const std::string& m)
{
    driver.error(l, m);
}

