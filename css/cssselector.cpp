#include "cssselector.h"

#include <iostream>
#include <sstream>

#include "css/cssselectorscanner.h"

namespace css {

SelectorMatcherGenerator::~SelectorMatcherGenerator() {}

CssSelector::CssSelector(SelectorMatcherGenerator *generator)
    : m_generator(generator)
{
}

CssSelector::~CssSelector()
{
}

void CssSelector::cssparser_handle_new_selector_list()
{
    std::cout << "  cssparser_handle_new_selector_list" << std::endl;
    m_generator->cssparser_handle_new_selector_list();
}

void CssSelector::cssparser_handle_new_compound_selector()
{
    std::cout << "    cssparser_handle_new_compound_selector" << std::endl;
    m_generator->cssparser_handle_new_compound_selector();
}

void CssSelector::cssparser_handle_new_simple_selector()
{
    std::cout << "    cssparser_handle_new_simple_selector" << std::endl;
    m_generator->cssparser_handle_new_simple_selector();
}

void CssSelector::cssparser_handle_new_complex_selector()
{
    std::cout << "    cssparser_handle_new_complex_selector" << std::endl;
    m_generator->cssparser_handle_new_complex_selector();
}

void CssSelector::cssparser_handle_new_universal_selector()
{
    std::cout << "    cssparser_handle_new_universal_selector" << std::endl;
    m_generator->cssparser_handle_new_universal_selector();
}

void CssSelector::cssparser_handle_id_selector(const std::string *id)
{
    std::cout << "      cssparser_handle_id_selector " << id->c_str() << std::endl;
    m_generator->cssparser_handle_id_selector(id);
}

void CssSelector::cssparser_handle_class_selector(const std::string *cssclass)
{
    std::cout << "      cssparser_handle_class_selector " << cssclass->c_str() << std::endl;
    m_generator->cssparser_handle_class_selector(cssclass);
}

void CssSelector::cssparser_handle_type_selector(const std::string *type)
{
    std::cout << "      cssparser_handle_type_selector " << type->c_str() << std::endl;
    m_generator->cssparser_handle_type_selector(type);
}

void CssSelector::cssparser_handle_empty_attribute_selector(const std::string *attribute)
{
    std::cout << "      cssparser_handle_empty_attribute_selector " << attribute->c_str() << std::endl;
    m_generator->cssparser_handle_empty_attribute_selector(attribute);
}

void CssSelector::cssparser_handle_attribute_selector(const std::string *id, const std::string *cssoperator, const std::string *value)
{
    std::cout << "      cssparser_handle_attribute_selector " << id->c_str() << cssoperator->c_str() << value->c_str() << std::endl;
    m_generator->cssparser_handle_attribute_selector(id, cssoperator, value);
}

void CssSelector::error(const cssselector_parser::location_type &loc, const std::string &message)
{
    std::cerr << loc << message << std::endl;
}

void CssSelector::error(const std::string &message)
{
    std::cerr << message << std::endl;
}

bool CssSelector::parse_stream(std::istream& in, const std::string& sname)
{
    streamname = sname;

    std::cout << "Started parsing" << std::endl;

    m_generator->cssparser_begin();

    CssSelectorScanner scanner(&in);
//    scanner.set_debug(1);
    this->lexer = &scanner;

    css::cssselector_parser parser(*this);
//    parser.set_debug_level(1);
    int result = parser.parse();

    if (result == 0) {
        std::cout << "Finished parsing" << std::endl;
    } else {
        std::cout << "Failed parsing" << std::endl;
    }

    m_generator->cssparser_finish(result == 0);

    return (result == 0);
}

bool CssSelector::parse_string(const std::string &input, const std::string& sname)
{
    std::istringstream iss(input);
    return parse_stream(iss, sname);
}



}
