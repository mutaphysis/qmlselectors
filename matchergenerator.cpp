#include "matchergenerator.h"

#include <QDebug>

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

void MatcherGenerator::cssparser_handle_universal_selector()
{
    SharedMatcher newMatcher = CreateSharedMatcher(AnyMatcher());
    updateCurrentMatcher(newMatcher);
}

void MatcherGenerator::cssparser_handle_pseudo_class_selector(const std::string *pseudo_class)
{
    if (qstrcmp(pseudo_class->c_str(), "last-child") == 0) {
        SharedMatcher newMatcher = CreateSharedMatcher(IndexedMatcher(IndexedMatcher::LAST));
        updateCurrentMatcher(newMatcher);
        return;
    }

    if (qstrcmp(pseudo_class->c_str(), "first-child") == 0) {
        SharedMatcher newMatcher = CreateSharedMatcher(IndexedMatcher(IndexedMatcher::FIRST));
        updateCurrentMatcher(newMatcher);
        return;
    }

    qWarning() << "WARNING: Unhandled pseudo_class" << pseudo_class->c_str();
}

void MatcherGenerator::cssparser_handle_pseudo_class_function_selector(const std::string *pseudo_class, const std::string *function)
{
    if (qstrcmp(pseudo_class->c_str(), "nth-child") == 0) {
        bool ok;
        int index = QString(function->c_str()).toInt(&ok);

        if (ok) {
            SharedMatcher newMatcher = CreateSharedMatcher(IndexedMatcher(index, IndexedMatcher::NTH));
            updateCurrentMatcher(newMatcher);
        } else {
            qWarning() << "WARNING: Unhandled nth-child param" << function->c_str();
        }

        return;
    }

    qWarning() << "WARNING: Unhandled pseudo_class function" << pseudo_class->c_str();
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

void MatcherGenerator::cssparser_handle_class_selector(const std::string *cssclass)
{
    qWarning() << "WARNING: Unhandled class" << cssclass->c_str();
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
        qWarning() << "WARNING: Unhandled operator" << cssoperator->c_str();
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

MatcherList MatcherGenerator::parse(const QString &selector, bool *error)
{
    MatcherGenerator mg;
    css::CssSelector parser(&mg);
    *error = parser.parse_string(selector.toStdString());

    return mg.results();
}
