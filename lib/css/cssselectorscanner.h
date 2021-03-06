#ifndef CSSSELECTORSCANNER_H
#define CSSSELECTORSCANNER_H

// Tell Flex the lexer's prototype
#ifndef YY_DECL
#define YY_DECL                                                          \
    css::cssselector_parser::token_type css::CssSelectorScanner::lex(    \
        css::cssselector_parser::semantic_type* yylval,                  \
        css::cssselector_parser::location_type* yylloc                   \
    )
#endif

#ifndef __FLEX_LEXER_H
#define yyFlexLexer CssSelectorFlexLexer
#include "css/gen/FlexLexer.h"
#undef yyFlexLexer
#endif

#include <string>
#include <list>

#include "css/gen/cssselector.parser.hh"

namespace css {

class CssSelectorScanner : public CssSelectorFlexLexer
{
public:
    CssSelectorScanner(std::istream* arg_yyin = 0, std::ostream* arg_yyout = 0);
    virtual ~CssSelectorScanner();

    void set_debug(bool b);

    virtual css::cssselector_parser::token_type lex( css::cssselector_parser::semantic_type* yylval,
                                    css::cssselector_parser::location_type* yylloc );

private:
    std::string* text(const char* str, int length);

    std::list<std::string*> m_dynamic_strings;

    friend class cssselector_parser;
};

}

#endif // CSSSELECTORSCANNER_H

