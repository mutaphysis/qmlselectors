#ifndef CSSSELECTOR_H
#define CSSSELECTOR_H

#include <string>

#include "css/cssselectorscanner.h"

namespace css {

class CssSelector
{
public:
    CssSelector();
    virtual ~CssSelector();

protected:
    void cssparser_handle_id_selector(const std::string* id);
    void cssparser_handle_charset(const std::string* id);
    void cssparser_handle_class_selector(const std::string* id);
    void cssparser_handle_type_selector(const std::string* id);
    void cssparser_handle_empty_attribute_selector(const std::string* id);
    void cssparser_handle_attribute_selector(const std::string* id, const std::string* id2, const std::string* id3);

    void error(const cssselector_parser::location_type& loc, const std::string& message);

    class CssSelectorScanner* lexer;

    friend class cssselector_parser;
};

}

#endif // CSSSELECTOR_H

