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
#line 73 "css/cssselector.yy"

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
    #line 32 "css/cssselector.yy"
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
	  case 4:
#line 95 "css/cssselector.yy"
    {
        driver.cssparser_handle_charset((yysemantic_stack_[(3) - (2)].stringVal));
    ;}
    break;

  case 37:
#line 174 "css/cssselector.yy"
    {
        // TODO PyObject_CallMethod((PyObject*)global_self, CSSPARSER_HANDLE_COMBINATOR, "s", "+");
    ;}
    break;

  case 38:
#line 178 "css/cssselector.yy"
    {
        // TODO PyObject_CallMethod((PyObject*)global_self, CSSPARSER_HANDLE_COMBINATOR, "s", ">");
    ;}
    break;

  case 41:
#line 190 "css/cssselector.yy"
    {
        (yyval.stringVal) = (yysemantic_stack_[(2) - (1)].stringVal);
    ;}
    break;

  case 63:
#line 237 "css/cssselector.yy"
    {
        driver.cssparser_handle_id_selector((yysemantic_stack_[(1) - (1)].stringVal));
    ;}
    break;

  case 64:
#line 244 "css/cssselector.yy"
    {
        driver.cssparser_handle_class_selector((yysemantic_stack_[(2) - (2)].stringVal));
    ;}
    break;

  case 65:
#line 251 "css/cssselector.yy"
    {
        driver.cssparser_handle_type_selector((yysemantic_stack_[(1) - (1)].stringVal));
    ;}
    break;

  case 66:
#line 258 "css/cssselector.yy"
    {
        driver.cssparser_handle_empty_attribute_selector((yysemantic_stack_[(5) - (3)].stringVal));
    ;}
    break;

  case 67:
#line 262 "css/cssselector.yy"
    {
        driver.cssparser_handle_attribute_selector((yysemantic_stack_[(9) - (3)].stringVal), (yysemantic_stack_[(9) - (5)].stringVal), (yysemantic_stack_[(9) - (7)].stringVal));
    ;}
    break;

  case 68:
#line 269 "css/cssselector.yy"
    {   (yyval.stringVal) = new std::string("=");    ;}
    break;

  case 69:
#line 271 "css/cssselector.yy"
    {   (yyval.stringVal) = (yysemantic_stack_[(1) - (1)].stringVal);    ;}
    break;

  case 70:
#line 273 "css/cssselector.yy"
    {   (yyval.stringVal) = (yysemantic_stack_[(1) - (1)].stringVal);    ;}
    break;

  case 71:
#line 278 "css/cssselector.yy"
    {   (yyval.stringVal) = (yysemantic_stack_[(1) - (1)].stringVal);    ;}
    break;

  case 72:
#line 280 "css/cssselector.yy"
    {   (yyval.stringVal) = (yysemantic_stack_[(1) - (1)].stringVal);    ;}
    break;

  case 81:
#line 305 "css/cssselector.yy"
    {
        // TODO PyObject_CallMethod((PyObject*)global_self, CSSPARSER_HANDLE_DECLARATION, "ss", $1, $4);
    ;}
    break;

  case 82:
#line 309 "css/cssselector.yy"
    {
        // TODO PyObject_CallMethod((PyObject*)global_self, CSSPARSER_HANDLE_DECLARATION, "ss", $1, $4);
    ;}
    break;

  case 84:
#line 320 "css/cssselector.yy"
    {
        (yyval.stringVal) = (yysemantic_stack_[(1) - (1)].stringVal);
    ;}
    break;

  case 89:
#line 333 "css/cssselector.yy"
    {
        (yyval.stringVal) = (yysemantic_stack_[(2) - (1)].stringVal);
    ;}
    break;

  case 90:
#line 337 "css/cssselector.yy"
    {
        (yyval.stringVal) = (yysemantic_stack_[(2) - (1)].stringVal);
    ;}
    break;

  case 91:
#line 341 "css/cssselector.yy"
    {
        (yyval.stringVal) = (yysemantic_stack_[(2) - (1)].stringVal);
    ;}
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
  const signed char cssselector_parser::yypact_ninf_ = -119;
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

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
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

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  cssselector_parser::yypgoto_[] =
  {
      -119,  -119,  -119,  -119,  -119,  -119,   156,  -119,  -119,  -119,
       9,    23,  -119,    47,  -119,  -119,  -119,  -119,  -119,    32,
    -119,   126,   142,   132,   -20,  -119,  -119,   -23,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,   -92,  -119,    36,  -118,    56,
    -119,  -119,   -11
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  cssselector_parser::yydefgoto_[] =
  {
        -1,     2,     3,     6,    12,    15,    16,    13,    28,   128,
      68,    69,    29,    92,    75,   176,    62,   158,   101,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,   121,
     142,    40,    49,    97,   102,   103,   177,   159,   160,   161,
     162,   163,    93
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char cssselector_parser::yytable_ninf_ = -3;
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

  /* YYCHECK.  */
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

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
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

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
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
  "')'", "$accept", "stylesheet", "charset", "comments", "import_block",
  "body", "subcomments", "import", "media", "rulesets", "media_list",
  "medium", "page", "page_declarations", "pseudo_page", "operator",
  "combinator", "unary_operator", "property", "ruleset", "selector_list",
  "complex_selector", "universal_selector", "compound_selector",
  "simple_selector", "id_selector", "class_selector", "type_selector",
  "attribute_selector", "attrib_eq", "attrib_value",
  "pseudo_class_selector", "pseudo_block", "pseudo_block_function_ident",
  "declarations", "declaration", "prio", "expr", "term", "term_numeral",
  "function", "hexcolor", "spaces", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const cssselector_parser::rhs_number_type
  cssselector_parser::yyrhs_[] =
  {
        45,     0,    -1,    46,    47,    48,    49,    -1,    -1,     8,
      14,    29,    -1,    -1,    47,    13,    -1,    47,     7,    -1,
      47,     6,    -1,    -1,    51,    50,    -1,    -1,    49,    63,
      50,    -1,    49,    52,    50,    -1,    49,    56,    50,    -1,
      -1,    50,     7,    86,    -1,    50,     6,    86,    -1,    20,
      86,    14,    86,    54,    29,    86,    -1,    20,    86,    28,
      86,    54,    29,    86,    -1,    20,    86,    14,    86,    29,
      86,    -1,    20,    86,    28,    86,    29,    86,    -1,    23,
      86,    54,    30,    86,    53,    31,    86,    -1,    -1,    53,
      63,    -1,    55,    -1,    54,    32,    86,    55,    -1,    18,
      86,    -1,    25,    86,    58,    30,    57,    31,    86,    -1,
      25,    86,    30,    57,    31,    86,    -1,    86,    79,    -1,
      86,    -1,    57,    29,    86,    79,    -1,    57,    29,    86,
      -1,    33,    18,    86,    -1,    34,    86,    -1,    32,    86,
      -1,    35,    86,    -1,    36,    86,    -1,    37,    -1,    35,
      -1,    18,    86,    -1,    64,    30,    86,    78,    31,    86,
      -1,    64,    30,    86,    31,    86,    -1,    65,    -1,    66,
      -1,    64,    32,    86,    65,    -1,    64,    32,    86,    66,
      -1,    67,    -1,    65,    60,    67,    -1,    65,    13,    67,
      -1,    65,    13,    -1,    -1,    38,    -1,    38,    71,    -1,
      71,    -1,    38,    68,    -1,    68,    -1,    67,    68,    -1,
      72,    -1,    70,    -1,    69,    -1,    75,    -1,    17,    -1,
      39,    18,    -1,    18,    -1,    40,    86,    18,    86,    41,
      -1,    40,    86,    18,    86,    73,    86,    74,    86,    41,
      -1,    42,    -1,    19,    -1,     9,    -1,    18,    -1,    14,
      -1,    33,    76,    -1,    18,    -1,    16,    86,    77,    43,
      -1,    -1,    18,    86,    -1,    79,    -1,    78,    29,    86,
      79,    -1,    78,    29,    86,    -1,    62,    33,    86,    81,
      80,    -1,    62,    33,    86,    81,    -1,    21,    86,    -1,
      82,    -1,    81,    59,    82,    -1,    81,    82,    -1,    61,
      83,    86,    -1,    83,    86,    -1,    14,    86,    -1,    18,
      86,    -1,    28,    86,    -1,    85,    -1,    84,    -1,    24,
      -1,    26,    -1,    22,    -1,    11,    -1,    12,    -1,     3,
      -1,    27,    -1,    15,    -1,    16,    86,    81,    43,    86,
      -1,    17,    86,    -1,    -1,    86,    13,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  cssselector_parser::yyprhs_[] =
  {
         0,     0,     3,     8,     9,    13,    14,    17,    20,    23,
      24,    27,    28,    32,    36,    40,    41,    45,    49,    57,
      65,    72,    79,    88,    89,    92,    94,    99,   102,   110,
     117,   120,   122,   127,   131,   135,   138,   141,   144,   147,
     149,   151,   154,   161,   167,   169,   171,   176,   181,   183,
     187,   191,   194,   195,   197,   200,   202,   205,   207,   210,
     212,   214,   216,   218,   220,   223,   225,   231,   241,   243,
     245,   247,   249,   251,   254,   256,   261,   262,   265,   267,
     272,   276,   282,   287,   290,   292,   296,   299,   303,   306,
     309,   312,   315,   317,   319,   321,   323,   325,   327,   329,
     331,   333,   335,   341,   344,   345
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  cssselector_parser::yyrline_[] =
  {
         0,    89,    89,    92,    94,   100,   102,   103,   104,   107,
     109,   112,   114,   115,   116,   119,   121,   122,   126,   127,
     128,   129,   133,   136,   138,   142,   143,   147,   152,   153,
     157,   158,   159,   160,   164,   168,   169,   173,   177,   184,
     185,   189,   196,   197,   201,   202,   203,   204,   208,   209,
     210,   211,   215,   217,   221,   222,   223,   224,   225,   229,
     230,   231,   232,   236,   243,   250,   257,   261,   268,   270,
     272,   277,   279,   284,   288,   289,   292,   294,   298,   299,
     300,   304,   308,   315,   319,   323,   324,   330,   331,   332,
     336,   340,   344,   345,   349,   350,   351,   352,   353,   354,
     355,   356,   360,   369,   372,   374
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
  const int cssselector_parser::yylast_ = 276;
  const int cssselector_parser::yynnts_ = 43;
  const int cssselector_parser::yyempty_ = -2;
  const int cssselector_parser::yyfinal_ = 5;
  const int cssselector_parser::yyterror_ = 1;
  const int cssselector_parser::yyerrcode_ = 256;
  const int cssselector_parser::yyntokens_ = 44;

  const unsigned int cssselector_parser::yyuser_token_number_max_ = 283;
  const cssselector_parser::token_number_type cssselector_parser::yyundef_token_ = 2;

} // namespace css

#line 377 "css/cssselector.yy"



void css::cssselector_parser::error (const location_type& l, const std::string& m)
{
    driver.error(l, m);
}

