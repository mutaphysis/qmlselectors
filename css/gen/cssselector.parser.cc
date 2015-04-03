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
#line 71 "css/cssselector.yy"

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
#line 87 "css/cssselector.yy"
    {
        driver.cssparser_handle_new_selector_list();
    ;}
    break;

  case 3:
#line 91 "css/cssselector.yy"
    {
        driver.cssparser_handle_new_selector_list();
    ;}
    break;

  case 4:
#line 95 "css/cssselector.yy"
    {
        driver.cssparser_handle_new_selector_list();
    ;}
    break;

  case 5:
#line 99 "css/cssselector.yy"
    {
        driver.cssparser_handle_new_selector_list();
    ;}
    break;

  case 6:
#line 106 "css/cssselector.yy"
    {
        driver.cssparser_handle_new_compound_selector();
    ;}
    break;

  case 7:
#line 110 "css/cssselector.yy"
    {
        driver.cssparser_handle_new_compound_selector();
    ;}
    break;

  case 8:
#line 114 "css/cssselector.yy"
    {
        driver.cssparser_handle_new_compound_selector();
    ;}
    break;

  case 11:
#line 124 "css/cssselector.yy"
    {
        driver.cssparser_handle_new_universal_selector();
    ;}
    break;

  case 17:
#line 139 "css/cssselector.yy"
    {
        // TODO
    ;}
    break;

  case 18:
#line 143 "css/cssselector.yy"
    {
        // TODO
    ;}
    break;

  case 23:
#line 157 "css/cssselector.yy"
    {
        driver.cssparser_handle_id_selector((yysemantic_stack_[(1) - (1)].stringVal));
    ;}
    break;

  case 24:
#line 164 "css/cssselector.yy"
    {
        driver.cssparser_handle_class_selector((yysemantic_stack_[(2) - (2)].stringVal));
    ;}
    break;

  case 25:
#line 171 "css/cssselector.yy"
    {
        driver.cssparser_handle_type_selector((yysemantic_stack_[(1) - (1)].stringVal));
    ;}
    break;

  case 26:
#line 178 "css/cssselector.yy"
    {
        driver.cssparser_handle_empty_attribute_selector((yysemantic_stack_[(5) - (3)].stringVal));
    ;}
    break;

  case 27:
#line 182 "css/cssselector.yy"
    {
        driver.cssparser_handle_attribute_selector((yysemantic_stack_[(9) - (3)].stringVal), (yysemantic_stack_[(9) - (5)].stringVal), (yysemantic_stack_[(9) - (7)].stringVal));
    ;}
    break;

  case 28:
#line 189 "css/cssselector.yy"
    {   (yyval.stringVal) = new std::string("=");    ;}
    break;

  case 29:
#line 191 "css/cssselector.yy"
    {   (yyval.stringVal) = (yysemantic_stack_[(1) - (1)].stringVal);    ;}
    break;

  case 30:
#line 193 "css/cssselector.yy"
    {   (yyval.stringVal) = (yysemantic_stack_[(1) - (1)].stringVal);    ;}
    break;

  case 31:
#line 198 "css/cssselector.yy"
    {   (yyval.stringVal) = (yysemantic_stack_[(1) - (1)].stringVal);    ;}
    break;

  case 32:
#line 200 "css/cssselector.yy"
    {   (yyval.stringVal) = (yysemantic_stack_[(1) - (1)].stringVal);    ;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 536 "css/gen/cssselector.parser.cc"
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
  const signed char cssselector_parser::yypact_ninf_ = -21;
  const signed char
  cssselector_parser::yypact_[] =
  {
        25,   -21,   -21,    35,   -16,   -21,    31,     1,    -9,   -21,
      40,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
      -4,   -21,   -21,   -21,   -21,   -21,    33,   -21,   -21,    33,
     -21,   -21,   -21,     7,    11,    35,    40,    -5,    -5,    40,
       2,   -21,   -20,    -9,   -21,   -21,   -21,   -21,   -21,   -21,
      -5,   -21,    47,   -21,   -21,   -21,    -8,   -21
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  cssselector_parser::yydefact_[] =
  {
        10,    23,    25,    11,     0,    38,     0,     0,     2,     3,
       6,    15,    21,    20,    13,    19,    22,    14,    12,    24,
       0,    38,    34,    33,     1,    38,     9,    38,    38,     0,
      16,    39,    38,    36,    10,     0,     8,    17,    18,     7,
       0,    38,     0,     4,     5,    30,    29,    26,    28,    38,
      37,    35,     0,    32,    31,    38,     0,    27
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  cssselector_parser::yypgoto_[] =
  {
       -21,   -21,     5,    12,   -10,   -21,    -3,   -21,   -21,     0,
     -21,   -21,   -21,   -21,   -21,   -21,   -15
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  cssselector_parser::yydefgoto_[] =
  {
        -1,     7,     8,     9,    10,    29,    11,    12,    13,    14,
      15,    49,    55,    16,    23,    42,    20
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char cssselector_parser::yytable_ninf_ = -1;
  const unsigned char
  cssselector_parser::yytable_[] =
  {
        17,    24,    19,    18,    26,    31,    33,    30,    31,    31,
      34,    45,    37,    38,    32,    31,    36,    40,    51,    39,
      31,    46,    27,    28,    31,    41,    50,    57,     1,     2,
      25,     0,    17,    30,    52,    18,    30,    47,    48,    43,
      56,     3,     1,     2,     4,     5,    44,    21,     6,    22,
       1,     2,     1,     2,     0,     3,     0,     1,     4,     5,
      31,    53,     6,    35,     0,    54,     4,     5,     4,     5,
       6,     0,     6,     4,     5,     0,     0,     6
  };

  /* YYCHECK.  */
  const signed char
  cssselector_parser::yycheck_[] =
  {
         3,     0,    18,     3,    13,    13,    21,    10,    13,    13,
      25,     9,    27,    28,    18,    13,    26,    32,    38,    29,
      13,    19,    31,    32,    13,    18,    41,    35,    17,    18,
      29,    -1,    35,    36,    49,    35,    39,    35,    36,    34,
      55,    30,    17,    18,    33,    34,    34,    16,    37,    18,
      17,    18,    17,    18,    -1,    30,    -1,    17,    33,    34,
      13,    14,    37,    30,    -1,    18,    33,    34,    33,    34,
      37,    -1,    37,    33,    34,    -1,    -1,    37
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  cssselector_parser::yystos_[] =
  {
         0,    17,    18,    30,    33,    34,    37,    40,    41,    42,
      43,    45,    46,    47,    48,    49,    52,    45,    48,    18,
      55,    16,    18,    53,     0,    29,    13,    31,    32,    44,
      45,    13,    18,    55,    55,    30,    43,    55,    55,    43,
      55,    18,    54,    41,    42,     9,    19,    35,    36,    50,
      55,    38,    55,    14,    18,    51,    55,    35
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  cssselector_parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    44,
      42,    43,    62,    46,    91,    93,    61,    58,    41
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  cssselector_parser::yyr1_[] =
  {
         0,    39,    40,    40,    40,    40,    41,    41,    41,    41,
      42,    42,    43,    43,    43,    43,    43,    44,    44,    45,
      45,    45,    45,    46,    47,    48,    49,    49,    50,    50,
      50,    51,    51,    52,    53,    53,    54,    54,    55,    55
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  cssselector_parser::yyr2_[] =
  {
         0,     2,     1,     1,     4,     4,     1,     3,     3,     2,
       0,     1,     2,     1,     2,     1,     2,     2,     2,     1,
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
  "PAGE_SYM", "PERCENTAGE", "TIME", "URI", "','", "'*'", "'+'", "'>'",
  "'.'", "'['", "']'", "'='", "':'", "')'", "$accept", "selector_list",
  "complex_selector", "universal_selector", "compound_selector",
  "combinator", "simple_selector", "id_selector", "class_selector",
  "type_selector", "attribute_selector", "attrib_eq", "attrib_value",
  "pseudo_class_selector", "pseudo_block", "pseudo_block_function_ident",
  "spaces", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const cssselector_parser::rhs_number_type
  cssselector_parser::yyrhs_[] =
  {
        40,     0,    -1,    41,    -1,    42,    -1,    40,    29,    55,
      41,    -1,    40,    29,    55,    42,    -1,    43,    -1,    41,
      44,    43,    -1,    41,    13,    43,    -1,    41,    13,    -1,
      -1,    30,    -1,    30,    48,    -1,    48,    -1,    30,    45,
      -1,    45,    -1,    43,    45,    -1,    31,    55,    -1,    32,
      55,    -1,    49,    -1,    47,    -1,    46,    -1,    52,    -1,
      17,    -1,    33,    18,    -1,    18,    -1,    34,    55,    18,
      55,    35,    -1,    34,    55,    18,    55,    50,    55,    51,
      55,    35,    -1,    36,    -1,    19,    -1,     9,    -1,    18,
      -1,    14,    -1,    37,    53,    -1,    18,    -1,    16,    55,
      54,    38,    -1,    -1,    18,    55,    -1,    -1,    55,    13,
      -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  cssselector_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,    12,    17,    19,    23,    27,
      30,    31,    33,    36,    38,    41,    43,    46,    49,    52,
      54,    56,    58,    60,    62,    65,    67,    73,    83,    85,
      87,    89,    91,    93,    96,    98,   103,   104,   107,   108
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned char
  cssselector_parser::yyrline_[] =
  {
         0,    86,    86,    90,    94,    98,   105,   109,   113,   117,
     121,   123,   130,   131,   132,   133,   134,   138,   142,   149,
     150,   151,   152,   156,   163,   170,   177,   181,   188,   190,
     192,   197,   199,   204,   208,   209,   212,   214,   217,   219
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
       2,    38,    30,    31,    29,     2,    33,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,     2,
       2,    36,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,    35,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int cssselector_parser::yyeof_ = 0;
  const int cssselector_parser::yylast_ = 77;
  const int cssselector_parser::yynnts_ = 17;
  const int cssselector_parser::yyempty_ = -2;
  const int cssselector_parser::yyfinal_ = 24;
  const int cssselector_parser::yyterror_ = 1;
  const int cssselector_parser::yyerrcode_ = 256;
  const int cssselector_parser::yyntokens_ = 39;

  const unsigned int cssselector_parser::yyuser_token_number_max_ = 283;
  const cssselector_parser::token_number_type cssselector_parser::yyundef_token_ = 2;

} // namespace css

#line 222 "css/cssselector.yy"


void css::cssselector_parser::error (const location_type& l, const std::string& m)
{
    driver.error(l, m);
}

