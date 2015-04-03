#ifndef CSSSELECTORSCANNER_H
#define CSSSELECTORSCANNER_H

// Tell Flex the lexer's prototype
#ifndef YY_DECL
#define YY_DECL                                                     \
    css::cssselector_parser::token_type css::CssSelectorScanner::lex(     \
        css::cssselector_parser::semantic_type* yylval,              \
        css::cssselector_parser::location_type* yylloc               \
    )
#endif

#ifndef __FLEX_LEXER_H
#define yyFlexLexer CssSelectorFlexLexer
#include "FlexLexer.h"
#undef yyFlexLexer
#endif

#include "css/gen/cssselector.parser.hh"

namespace css {

class CssSelectorScanner : public CssSelectorFlexLexer
{
public:
    CssSelectorScanner(std::istream* arg_yyin = 0, std::ostream* arg_yyout = 0);
    virtual ~CssSelectorScanner();

    //  virtual Parser::token_type lex( Parser::semantic_type* yylval, Parser::location_type* yylloc);

    void set_debug(bool b);

    virtual css::cssselector_parser::token_type lex( css::cssselector_parser::semantic_type* yylval,
                                    css::cssselector_parser::location_type* yylloc );
};

}

#endif // CSSSELECTORSCANNER_H

