%{

#include <string>

#include "css/cssselectorscanner.h"

#undef yywrap
#define yywrap() 1

typedef css::cssselector_parser::token token;
typedef css::cssselector_parser::token_type token_type;

#define yyterminate() return token::END
%}

%option prefix="CssSelector"

%option c++
%option batch
%option debug
%option stack
%option case-insensitive
%option noyywrap
%option nounput

%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}


h              [0-9a-f]
nonascii       [\240-\377]
unicode        \\{h}{1,6}(\r\n|[ \t\r\n\f])?
escape         {unicode}|\\[^\r\n\f0-9a-f]
nmstart        [_a-z]|{nonascii}|{escape}
nmchar         [_a-z0-9-]|{nonascii}|{escape}
string1        \"([^\n\r\f\\"]|\\{nl}|{escape})*\"
string2        \'([^\n\r\f\\']|\\{nl}|{escape})*\'
badstring1     \"([^\n\r\f\\"]|\\{nl}|{escape})*\\?
badstring2     \'([^\n\r\f\\']|\\{nl}|{escape})*\\?
badcomment1    \/\*[^*]*\*+([^/*][^*]*\*+)*
badcomment2    \/\*[^*]*(\*+[^/*][^*]*)*
baduri1        url\({w}([!#$%&*-\[\]-~]|{nonascii}|{escape})*{w}
baduri2        url\({w}{string}{w}
baduri3        url\({w}{badstring}
comment        \/\*[^*]*\*+([^/*][^*]*\*+)*\/
ident          -?{nmstart}{nmchar}*
name           {nmchar}+
num            [0-9]+|[0-9]*"."[0-9]+
string         {string1}|{string2}
badstring      {badstring1}|{badstring2}
badcomment     {badcomment1}|{badcomment2}
baduri         {baduri1}|{baduri2}|{baduri3}
url	           ([!#$%&*-~]|{nonascii}|{escape})*
s              [ \t\r\n\f]+
w              {s}?
nl             \n|\r\n|\r|\f

A		a|\\0{0,4}(41|61)(\r\n|[ \t\r\n\f])?
C		c|\\0{0,4}(43|63)(\r\n|[ \t\r\n\f])?
D		d|\\0{0,4}(44|64)(\r\n|[ \t\r\n\f])?
E		e|\\0{0,4}(45|65)(\r\n|[ \t\r\n\f])?
G		g|\\0{0,4}(47|67)(\r\n|[ \t\r\n\f])?|\\g
H		h|\\0{0,4}(48|68)(\r\n|[ \t\r\n\f])?|\\h
I		i|\\0{0,4}(49|69)(\r\n|[ \t\r\n\f])?|\\i
K		k|\\0{0,4}(4b|6b)(\r\n|[ \t\r\n\f])?|\\k
L       l|\\0{0,4}(4c|6c)(\r\n|[ \t\r\n\f])?|\\l
M		m|\\0{0,4}(4d|6d)(\r\n|[ \t\r\n\f])?|\\m
N		n|\\0{0,4}(4e|6e)(\r\n|[ \t\r\n\f])?|\\n
O		o|\\0{0,4}(4f|6f)(\r\n|[ \t\r\n\f])?|\\o
P		p|\\0{0,4}(50|70)(\r\n|[ \t\r\n\f])?|\\p
R		r|\\0{0,4}(52|72)(\r\n|[ \t\r\n\f])?|\\r
S		s|\\0{0,4}(53|73)(\r\n|[ \t\r\n\f])?|\\s
T		t|\\0{0,4}(54|74)(\r\n|[ \t\r\n\f])?|\\t
U       u|\\0{0,4}(55|75)(\r\n|[ \t\r\n\f])?|\\u
X		x|\\0{0,4}(58|78)(\r\n|[ \t\r\n\f])?|\\x
Z		z|\\0{0,4}(5a|7a)(\r\n|[ \t\r\n\f])?|\\z

%%

%{
    // reset location
    yylloc->step();
%}

{s}                     {return token::S;}

\/\*[^*]*\*+([^/*][^*]*\*+)*\/       /* ignore comments */
{badcomment}                         /* unclosed comment at EOF */

"<!--"                  {return token::CDO;}
"-->"                   {return token::CDC;}
"~="                    {return token::INCLUDES;}
"|="                    {return token::DASHMATCH;}

{string}                { yylval->stringVal = text(yytext + 1, yyleng - 2);
                          return token::STRING;
                        }

{badstring}             {return token::BAD_STRING;}

{ident}	                { yylval->stringVal = text(yytext, yyleng);
                          return token::IDENT;}

"#"{name}               { yylval->stringVal = text(yytext + 1, yyleng - 1);
                          return token::HASH;}

@{I}{M}{P}{O}{R}{T}     {return token::IMPORT_SYM;}
@{P}{A}{G}{E}           {return token::PAGE_SYM;}
@{M}{E}{D}{I}{A}        {return token::MEDIA_SYM;}
"@charset "             {return token::CHARSET_SYM;}

"!"({w}|{comment})*{I}{M}{P}{O}{R}{T}{A}{N}{T}          {return token::IMPORTANT_SYM;}


{num}{E}{M}             {return token::EMS;}
{num}{E}{X}             {return token::EXS;}
{num}{P}{X}             {return token::LENGTH;}
{num}{C}{M}             {return token::LENGTH;}
{num}{M}{M}             {return token::LENGTH;}
{num}{I}{N}             {return token::LENGTH;}
{num}{P}{T}             {return token::LENGTH;}
{num}{P}{C}             {return token::LENGTH;}
{num}{D}{E}{G}          {return token::ANGLE;}
{num}{R}{A}{D}          {return token::ANGLE;}
{num}{G}{R}{A}{D}       {return token::ANGLE;}
{num}{M}{S} 	        {return token::TIME;}
{num}{S}                {return token::TIME;}
{num}{H}{Z}             {return token::FREQ;}
{num}{K}{H}{Z}          {return token::FREQ;}
{num}{ident}            { yylval->stringVal = text(yytext, yyleng);
                          return token::DIMENSION;}

{num}%                  {return token::PERCENTAGE;}

{num}                   { yylval->stringVal = text(yytext, yyleng);
                          return token::NUMBER;}

"url("{w}{string}{w}")" {return token::URI;}
"url("{w}{url}{w}")"    {return token::URI;}
{baduri}                {return token::BAD_URI;}

{ident}"("              { yylval->stringVal = text(yytext, yyleng - 1);
                          return token::FUNCTION;}

.                       { return static_cast<token_type>(*yytext); }

%%

namespace css {

void delete_pointer_element( std::string* element )
{
    delete element;
}

CssSelectorScanner::CssSelectorScanner(std::istream* in, std::ostream* out)
    : CssSelectorFlexLexer(in, out)
{
}

CssSelectorScanner::~CssSelectorScanner()
{
    std::for_each( m_dynamic_strings.begin(), m_dynamic_strings.end(), delete_pointer_element );
    m_dynamic_strings.clear();
}

void CssSelectorScanner::set_debug(bool b)
{
    yy_flex_debug = b;
}

std::string* CssSelectorScanner::text(const char *str, int length)
{
    std::string* val = new std::string(str, length);
    m_dynamic_strings.push_back( val );
    return val;
}

}

/* This implementation of ExampleFlexLexer::yylex() is required to fill the
 * vtable of the class ExampleFlexLexer. We define the scanner's main yylex
 * function via YY_DECL to reside in the Scanner class instead. */

#ifdef yylex
#undef yylex
#endif

int CssSelectorFlexLexer::yylex()
{
    std::cerr << "in FlexLexer::yylex() !" << std::endl;
    return 0;
}
