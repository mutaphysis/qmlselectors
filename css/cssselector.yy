%{
#include <string>
%}

%skeleton "lalr1.cc" /* -*- C++ -*- */

%name-prefix="css"

%require "2.3"

%debug

%defines

%parse-param { class CssSelector& driver }

 // Correct start for parsing css files
 // %start stylesheet
 // But we want to parse selectors instead
%start selector_list

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

%token                END                  0                        "end of file"
%token <stringVal>    ANGLE
%token <stringVal>    BAD_STRING
%token <stringVal>    BAD_URI
%token CDC CDO CHARSET_SYM
%token <stringVal>    DASHMATCH
%token <stringVal>    DIMENSION
%token EMS EXS
%token S
%token <stringVal>    STRING
%token <stringVal>    FREQ
%token <stringVal>    FUNCTION
%token <stringVal>    HASH
%token <stringVal>    IDENT
%token <stringVal>    INCLUDES
%token                IMPORT_SYM IMPORTANT_SYM
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

%type <stringVal>     expression
%type <stringVal>     expression_statement

%type <stringVal>     attrib_eq
%type <stringVal>     attrib_value


%{
#include "css/cssselectorscanner.h"
#include "css/cssselector.h"

#undef yylex
#define yylex driver.lexer->lex
%}


%%

/*** Grammar Rules ***/


selector_list
    : complex_selector
    {
        driver.cssparser_handle_new_selector_list();
    }
    | universal_selector
    {
        driver.cssparser_handle_new_selector_list();
    }
    | selector_list ',' spaces complex_selector
    {
        driver.cssparser_handle_new_selector_list();
    }
    | selector_list ',' spaces universal_selector
    {
        driver.cssparser_handle_new_selector_list();
    }
;

complex_selector // : simple_selector [ combinator selector | S+ [ combinator? selector ]? ]? ;
    : compound_selector
    {
        driver.cssparser_handle_new_compound_selector();
    }
    | complex_selector combinator compound_selector
    {
        driver.cssparser_handle_new_compound_selector();
    }
    | complex_selector S compound_selector
    {
        driver.cssparser_handle_new_compound_selector();
    }
    | complex_selector S
        /* for space symbols skipping */
;

universal_selector
    :
    | '*'
    {
        driver.cssparser_handle_universal_selector();
    }
;

compound_selector // : element_name [ HASH | class | attrib | pseudo ]* | [ HASH | class | attrib | pseudo ]+ ;
    : '*' type_selector
    | type_selector
    | '*' simple_selector
    | simple_selector
    | compound_selector simple_selector
;

combinator // : '+' S* | '>' S* ;
    : '+' spaces
    {
        // TODO
    }
    | '>' spaces
    {
        // TODO
    }
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

pseudo_block // : ':' ':'? [ IDENT | functional_pseudo ]
    : IDENT
    {
        driver.cssparser_handle_pseudo_class_selector($1);
    }
    | FUNCTION spaces expression ')'
    {
        driver.cssparser_handle_pseudo_class_function_selector($1, $3);
    }
;

expression // : [ [ PLUS | '-' | DIMENSION | NUMBER | STRING | IDENT ] S* ]+
    : expression_statement
    {   $$ = $1;    }
    | expression spaces expression_statement
    {   $$ = $1;    }
;

expression_statement
    : '+'
    {   $$ = new std::string("+");    }
    | '-'
    {   $$ = new std::string("-");    }
    | DIMENSION
    {   $$ = $1;    }
    | NUMBER
    {   $$ = $1;    }
    | STRING
    {   $$ = $1;    }
    | IDENT
    {   $$ = $1;    }
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
