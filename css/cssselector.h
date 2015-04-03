#ifndef CSSSELECTOR_H
#define CSSSELECTOR_H

#include <string>

#include "css/cssselectorscanner.h"

namespace css {

class SelectorMatcherGenerator
{
public:
    virtual ~SelectorMatcherGenerator();

    /// Begins parsing
    virtual void cssparser_begin() = 0;

    virtual void cssparser_handle_new_selector_list() = 0;
    virtual void cssparser_handle_new_complex_selector() = 0;
    virtual void cssparser_handle_new_compound_selector() = 0;
    virtual void cssparser_handle_new_simple_selector() = 0;
    virtual void cssparser_handle_new_universal_selector() = 0;

    virtual void cssparser_handle_id_selector(const std::string* id) = 0;
    virtual void cssparser_handle_class_selector(const std::string* cssclass) = 0;
    virtual void cssparser_handle_type_selector(const std::string* type) = 0;
    virtual void cssparser_handle_empty_attribute_selector(const std::string* attribute) = 0;
    virtual void cssparser_handle_attribute_selector(const std::string* attribute, const std::string* cssoperator, const std::string* value) = 0;

    /// Parsing finished
    virtual void cssparser_finish(bool okay) = 0;
};

class CssSelector
{
public:
    CssSelector(SelectorMatcherGenerator* generator);
    virtual ~CssSelector();

    bool parse_stream(std::istream& in, const std::string& sname = "stream input");
    bool parse_string( const std::string& input, const std::string& sname = "string stream");
protected:
    void cssparser_handle_new_selector_list();
    void cssparser_handle_new_complex_selector();
    void cssparser_handle_new_compound_selector();
    void cssparser_handle_new_simple_selector();
    void cssparser_handle_new_universal_selector();
    void cssparser_handle_id_selector(const std::string* id);
    void cssparser_handle_class_selector(const std::string* cssclass);
    void cssparser_handle_type_selector(const std::string* type);
    void cssparser_handle_empty_attribute_selector(const std::string* attribute);
    void cssparser_handle_attribute_selector(const std::string* attribute, const std::string* cssoperator, const std::string* value);

    void error(const cssselector_parser::location_type& loc, const std::string& message);
    void error(const std::string& message);

    std::string streamname;
    class CssSelectorScanner* lexer;


private:
    SelectorMatcherGenerator* m_generator;
    friend class cssselector_parser;

};

}

#endif // CSSSELECTOR_H

