#include "matchergenerator.h"

void MatcherGenerator::cssparser_begin()
{
    m_currentMatcher.reset();
}

void MatcherGenerator::cssparser_handle_new_selector_list()
{
    Q_ASSERT(!m_currentCompoundMatcher.isNull());

    m_resultingMatchers.append(m_currentCompoundMatcher);
    m_currentCompoundMatcher.reset();
}

void MatcherGenerator::cssparser_handle_new_complex_selector()
{

}

void MatcherGenerator::cssparser_handle_new_compound_selector()
{
    // TODO compound operators

    Q_ASSERT(!m_currentMatcher.isNull());

    if (m_currentCompoundMatcher.isNull()) {
        m_currentCompoundMatcher = m_currentMatcher;
    } else {
        m_currentCompoundMatcher = CreateSharedMatcher(ParentMatcher(m_currentMatcher, m_currentCompoundMatcher, ParentMatcher::ANY_PARENT));
    }
    m_currentMatcher.reset();
}

void MatcherGenerator::cssparser_handle_new_simple_selector()
{
}

void MatcherGenerator::cssparser_handle_new_universal_selector()
{
    SharedMatcher newMatcher = CreateSharedMatcher(AnyMatcher());
    updateCurrentMatcher(newMatcher);
}

void MatcherGenerator::updateCurrentMatcher(SharedMatcher newMatcher)
{
    if (m_currentMatcher.isNull()) {
        m_currentMatcher = newMatcher;
    } else {
        m_currentMatcher = CreateSharedMatcher(AndMatcher(m_currentMatcher, newMatcher));
    }
}

void MatcherGenerator::cssparser_handle_id_selector(const std::string *id)
{
    SharedMatcher newMatcher = CreateSharedMatcher(NameMatcher(QString(id->c_str())));
    updateCurrentMatcher(newMatcher);
}

void MatcherGenerator::cssparser_handle_class_selector(const std::string */*cssclass*/)
{
}

void MatcherGenerator::cssparser_handle_type_selector(const std::string *type)
{
    SharedMatcher newMatcher = CreateSharedMatcher(QmlTypeMatcher(QString(type->c_str())));
    updateCurrentMatcher(newMatcher);
}

void MatcherGenerator::cssparser_handle_empty_attribute_selector(const std::string *attribute)
{
    SharedMatcher newMatcher = CreateSharedMatcher(PropertyMatcher(QString(attribute->c_str())));
    updateCurrentMatcher(newMatcher);
}

void MatcherGenerator::cssparser_handle_attribute_selector(const std::string *attribute, const std::string *cssoperator, const std::string *value)
{
    if (qstrcmp(cssoperator->c_str(), "=") == 0) {
        SharedMatcher newMatcher = CreateSharedMatcher(PropertyMatcher(QString(attribute->c_str()),
                                                                   QString(value->c_str())));
        updateCurrentMatcher(newMatcher);
    } else {
        // TODO other operators
        Q_ASSERT(false);
    }
}

void MatcherGenerator::cssparser_finish(bool okay)
{
    // all started matchers should be finished
    if (okay) {
        Q_ASSERT(m_currentMatcher.isNull());
        Q_ASSERT(m_currentCompoundMatcher.isNull());
    } else {
        clear();
    }
}

MatcherGenerator::MatcherGenerator()
{

}

MatcherGenerator::~MatcherGenerator()
{
}

MatcherList MatcherGenerator::results() const
{
    return m_resultingMatchers;
}

void MatcherGenerator::clear()
{
    m_resultingMatchers.clear();
    m_currentMatcher.clear();
    m_currentCompoundMatcher.clear();
}
