%{
#include <string>
%}

%skeleton "lalr1.cc" /* -*- C++ -*- */

%name-prefix="css"

%require "2.3"

%debug

%defines

%parse-param { class CssSelector& driver }

%start stylesheet

%define "parser_class_name" "cssselector_parser"

%union {
    int                         integerVal;
    double                      doubleVal;
    std::string*                stringVal;
}

%error-verbose


%locations
%initial-action
{
  // Initialize the initial location.
/*  @$.begin.filename = @$.end.filename = &driver._file;*/
};

%token                  END                  0                        "end of file"
%token <stringVal>    ANGLE
%token <stringVal>    BAD_STRING
%token <stringVal>    BAD_URI
%token CDC CDO CHARSET_SYM
%token <stringVal>    DASHMATCH
%token DIMENSION
%token EMS EXS
%token S
%token <stringVal>    STRING
%token <stringVal>    FREQ
%token FUNCTION
%token <stringVal>    HASH
%token <stringVal>    IDENT
%token <stringVal>    INCLUDES
%token                  IMPORT_SYM IMPORTANT_SYM
%token <stringVal>    LENGTH
%token MEDIA_SYM
%token <stringVal>    NUMBER
%token PAGE_SYM
%token <stringVal>    PERCENTAGE
%token <stringVal>    TIME
%token <stringVal>    URI

%type <stringVal>     type_selector
%type <stringVal>     id_selector
%type <stringVal>     class_selector

%type <stringVal>     attrib_eq
%type <stringVal>     attrib_value

%type <stringVal> term
%type <stringVal> property
%type <stringVal> expr


%{
#include "css/cssselectorscanner.h"
#include "css/cssselector.h"

#undef yylex
#define yylex driver.lexer->lex
%}


%%

/*** Grammar Rules ***/

stylesheet // : [ CHARSET_SYM STRING ';' ]?
           //   [S|CDO|CDC]* [ import [ CDO S* | CDC S* ]* ]*
           //   [ [ ruleset | media | page ] [ CDO S* | CDC S* ]* ]* ;
    : charset comments import_block body
;

charset
    :
    | CHARSET_SYM STRING ';'
    {
        driver.cssparser_handle_charset($2);
    }
;

comments
    :
    | comments S
    | comments CDO
    | comments CDC
;

import_block
    :
    | import subcomments
;

body
    :
    | body ruleset subcomments
    | body media subcomments
    | body page subcomments
;

subcomments
    :
    | subcomments CDO spaces
    | subcomments CDC spaces
;

import // : IMPORT_SYM S* [STRING|URI] S* media_list? ';' S* ;
    : IMPORT_SYM spaces STRING spaces media_list ';' spaces
    | IMPORT_SYM spaces URI spaces media_list ';' spaces
    | IMPORT_SYM spaces STRING spaces ';' spaces
    | IMPORT_SYM spaces URI spaces ';' spaces
;

media // : MEDIA_SYM S* media_list '{' S* ruleset* '}' S* ;
    : MEDIA_SYM spaces media_list '{' spaces rulesets '}' spaces
;

rulesets
    :
    | rulesets ruleset
;

media_list // : medium [ COMMA S* medium]* ;
    : medium
    | media_list ',' spaces medium
;

medium // : IDENT S* ;
    : IDENT spaces
;

page // : PAGE_SYM S* pseudo_page?
     //   '{' S* declaration? [ ';' S* declaration? ]* '}' S* ;
    : PAGE_SYM spaces pseudo_page '{' page_declarations '}' spaces
    | PAGE_SYM spaces '{' page_declarations '}' spaces
;

page_declarations
    : spaces declaration
    | spaces
    | page_declarations ';' spaces declaration
    | page_declarations ';' spaces
;

pseudo_page // : ':' IDENT S* ;
    : ':' IDENT spaces
;

operator // : '/' S* | ',' S* ;
    : '/' spaces
    | ',' spaces
;

combinator // : '+' S* | '>' S* ;
    : '+' spaces
    {
        // TODO PyObject_CallMethod((PyObject*)global_self, CSSPARSER_HANDLE_COMBINATOR, "s", "+");
    }
    | '>' spaces
    {
        // TODO PyObject_CallMethod((PyObject*)global_self, CSSPARSER_HANDLE_COMBINATOR, "s", ">");
    }
;

unary_operator // : '-' | '+' ;
    : '-'
    | '+'
;

property // : IDENT S* ;
    : IDENT spaces
    {
        $$ = $1;
    }
;

ruleset // : selector [ ',' S* selector ]* '{' S* declaration? [ ';' S* declaration? ]* '}' S* ;
    : selector_list '{' spaces declarations '}' spaces
    | selector_list '{' spaces '}' spaces
;

selector_list
    : complex_selector
    | universal_selector
    | selector_list ',' spaces complex_selector
    | selector_list ',' spaces universal_selector
;

complex_selector // : simple_selector [ combinator selector | S+ [ combinator? selector ]? ]? ;
    : compound_selector
    | complex_selector combinator compound_selector
    | complex_selector S compound_selector
    | complex_selector S
        /* for space symbols skipping */
;

universal_selector
    :
    | '*'
;

compound_selector // : element_name [ HASH | class | attrib | pseudo ]* | [ HASH | class | attrib | pseudo ]+ ;
    : '*' type_selector
    | type_selector
    | '*' simple_selector
    | simple_selector
    | compound_selector simple_selector
;

simple_selector
    : attribute_selector
    | class_selector
    | id_selector
    | pseudo_class_selector
;

id_selector
    : HASH
    {
        driver.cssparser_handle_id_selector($1);
    }
;

class_selector // : '.' IDENT ;
    : '.' IDENT
    {
        driver.cssparser_handle_class_selector($2);
    }
;

type_selector // : IDENT | '*' ;
    : IDENT
    {
        driver.cssparser_handle_type_selector($1);
    }
;

attribute_selector // : '[' S* IDENT S* [ [ '=' | INCLUDES | DASHMATCH ] S* [ IDENT | STRING ] S* ]? ']';
    : '[' spaces IDENT spaces ']'
    {
        driver.cssparser_handle_empty_attribute_selector($3);
    }
    | '[' spaces IDENT spaces attrib_eq spaces attrib_value spaces ']'
    {
        driver.cssparser_handle_attribute_selector($3, $5, $7);
    }
;

attrib_eq
    : '='
    {   $$ = new std::string("=");    }
    | INCLUDES
    {   $$ = $1;    }
    | DASHMATCH
    {   $$ = $1;    }
;

attrib_value
    : IDENT
    {   $$ = $1;    }
    | STRING
    {   $$ = $1;    }
;

pseudo_class_selector // : ':' [ IDENT | FUNCTION S* [IDENT S*]? ')' ] ;
    : ':' pseudo_block
;

pseudo_block
    : IDENT
    | FUNCTION spaces pseudo_block_function_ident ')'
;

pseudo_block_function_ident
    :
    | IDENT spaces
;

declarations
    : declaration
    | declarations ';' spaces declaration
    | declarations ';' spaces
;

declaration // : property ':' S* expr prio? ;
    : property ':' spaces expr prio
    {
        // TODO PyObject_CallMethod((PyObject*)global_self, CSSPARSER_HANDLE_DECLARATION, "ss", $1, $4);
    }
    | property ':' spaces expr
    {
        // TODO PyObject_CallMethod((PyObject*)global_self, CSSPARSER_HANDLE_DECLARATION, "ss", $1, $4);
    }
;

prio // : IMPORTANT_SYM S* ;
    : IMPORTANT_SYM spaces
;

expr //: term [ operator? term ]*;
    : term
    {
        $$ = $1;
    }
    | expr operator term
    | expr term
;

term // : unary_operator?
     // [ NUMBER S* | PERCENTAGE S* | LENGTH S* | EMS S* | EXS S* | ANGLE S* | TIME S* | FREQ S* ]
     // | STRING S* | IDENT S* | URI S* | hexcolor | function ;
    : unary_operator term_numeral spaces
    | term_numeral spaces
    | STRING spaces
    {
        $$ = $1;
    }
    | IDENT spaces
    {
        $$ = $1;
    }
    | URI spaces
    {
        $$ = $1;
    }
    | hexcolor
    | function
;

term_numeral
    : NUMBER
    | PERCENTAGE
    | LENGTH
    | EMS
    | EXS
    | ANGLE
    | TIME
    | FREQ
;

function // : FUNCTION S* expr ')' S* ;
    : FUNCTION spaces expr ')' spaces
;


// There is a constraint on the color that it must
// have either 3 or 6 hex-digits (i.e., [0-9a-fA-F])
// after the "#"; e.g., "#000" is OK, but "#abcd" is not.

hexcolor // : HASH S* ;
    : HASH spaces
;

spaces
    :
    | spaces S
;

%%


void css::cssselector_parser::error (const location_type& l, const std::string& m)
{
    driver.error(l, m);
}
