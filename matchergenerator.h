#ifndef MATCHERGENERATOR_H
#define MATCHERGENERATOR_H

#include "css/cssselector.h"
#include "matchers.h"

class MatcherGenerator : public css::SelectorMatcherGenerator
{
    // SelectorMatcherGenerator interface
public:
    void cssparser_begin();

    void cssparser_handle_new_selector_list();
    void cssparser_handle_new_compound_selector();

    void cssparser_handle_universal_selector();
    void cssparser_handle_pseudo_class_selector(const std::string *pseudo_class);
    void cssparser_handle_pseudo_class_function_selector(const std::string *pseudo_class, const std::string *function);
    void cssparser_handle_id_selector(const std::string *id);
    void cssparser_handle_class_selector(const std::string *cssclass);
    void cssparser_handle_type_selector(const std::string *type);
    void cssparser_handle_empty_attribute_selector(const std::string *attribute);
    void cssparser_handle_attribute_selector(const std::string *attribute, const std::string *cssoperator, const std::string *value);

    void cssparser_finish(bool okay);

public:
    MatcherGenerator();
    virtual ~MatcherGenerator();

    MatcherList results() const;
    void clear();
private:
    void updateCurrentMatcher(SharedMatcher newMatcher);

    MatcherList m_resultingMatchers;
    SharedMatcher m_currentMatcher;
    SharedMatcher m_currentCompoundMatcher;
};


#endif // MATCHERGENERATOR_H

