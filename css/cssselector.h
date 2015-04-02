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

    bool parse_stream(std::istream& in,
    const std::string& sname = "stream input");

    bool parse_string( const std::string& input,
                        const std::string& sname = "string stream");

protected:
    void cssparser_handle_new_selector_list();
    void cssparser_handle_new_compound_selector();
    void cssparser_handle_new_simple_selector();
    void cssparser_handle_new_universal_selector();
    void cssparser_handle_id_selector(const std::string* id);
    void cssparser_handle_charset(const std::string* id);
    void cssparser_handle_class_selector(const std::string* id);
    void cssparser_handle_type_selector(const std::string* id);
    void cssparser_handle_empty_attribute_selector(const std::string* id);
    void cssparser_handle_attribute_selector(const std::string* id, const std::string* id2, const std::string* id3);

    void error(const cssselector_parser::location_type& loc, const std::string& message);
    void error(const std::string& message);

    std::string streamname;
    class CssSelectorScanner* lexer;

    friend class cssselector_parser;
};

}

#endif // CSSSELECTOR_H

