#include "matchers.h"

#include <QDebug>

const QRegularExpression QmlTypeMatcher::QML_TY4PE_RE = QRegularExpression("([a-zA-Z0-9]+)(:?_QMLTYPE_[0-9]+){0,1}(:?_QML_[0-9]+){0,1}");

Matcher::~Matcher() {}

NameMatcher::NameMatcher(const QString &name) : m_name(name) {}

bool NameMatcher::match(QObject *object) const
{
    return object->objectName() == m_name;
}


NotMatcher::NotMatcher(SharedMatcher matcher) : m_matcher(matcher) {}

bool NotMatcher::match(QObject *object) const
{
    return !m_matcher->match(object);
}


AndMatcher::AndMatcher(SharedMatcher matcherA, SharedMatcher matcherB) : m_matcherA(matcherA), m_matcherB(matcherB) {}

bool AndMatcher::match(QObject *object) const
{
    return m_matcherA->match(object) && m_matcherB->match(object);
}


AnyMatcher::AnyMatcher() {}

bool AnyMatcher::match(QObject *) const
{
    return true;
}


ClassNameMatcher::ClassNameMatcher(const QString &typeName) : m_typeName(typeName) {}

bool ClassNameMatcher::match(QObject *object) const
{
    const QMetaObject *mo = object->metaObject();
    return m_typeName == mo->className();
}


IndexedMatcher::IndexedMatcher(int index, IndexedMatcher::MatchMode mode) : m_index(index), m_mode(mode) {}

IndexedMatcher::IndexedMatcher(IndexedMatcher::MatchMode mode) : m_index(0), m_mode(mode) {}

bool IndexedMatcher::match(QObject *object) const
{
    const QObject *parent = object->parent();
    if (!parent) {
        return false;
    }

    const QObjectList siblings = parent->children();
    int index;
    switch(m_mode) {
    case NTH:
        index = m_index;
        break;
    case FIRST:
        index = 0;
        break;
    case LAST:
        index = siblings.length() - 1;
    case NTH_LAST:
        index = siblings.length() - m_index;
    }

    // do not search, but rather compare directly
    return siblings.length() > index && siblings.at(index) == object;
}


QmlTypeMatcher::QmlTypeMatcher(const QString &typeName) : m_typeName(typeName) {}

bool QmlTypeMatcher::match(QObject *object) const
{
    const QMetaObject *mo = object->metaObject();
    QString className = mo->className();

    QRegularExpressionMatch classMatch = QML_TY4PE_RE.match(className);
    if (classMatch.hasMatch()) {
        className = classMatch.captured(1);
    }

    return m_typeName == className;
}


PropertyMatcher::PropertyMatcher(const QString &property, const QVariant &value) : m_property(property), m_value(value), m_exists(false) {}

PropertyMatcher::PropertyMatcher(const QString &property) : m_property(property), m_exists(true) {}

bool PropertyMatcher::match(QObject *object) const
{
    QVariant value = object->property(m_property.toLocal8Bit().data());
    if (m_exists && !value.isNull()) {
        return true;
    }
    return (value == m_value);
}


SiblingMatcher::SiblingMatcher(SharedMatcher initial, SharedMatcher sibling, SiblingMatcher::MatchMode mode) : m_initial(initial), m_sibling(sibling), m_mode(mode) {}

bool SiblingMatcher::match(QObject *object) const
{
    QObject* parent = object->parent();
    if (m_initial->match(object) && parent) {
        const QObjectList siblings = parent->children();

        int index = siblings.indexOf(object);

        if (m_mode == NEXT_SIBLING || m_mode == PREVIOUS_SIBLING) {
            if (m_mode == NEXT_SIBLING) {
                index++;
            }
            if (m_mode == PREVIOUS_SIBLING) {
                index--;
            }
            return index >= 0 && index < siblings.length() && m_sibling->match(siblings.at(index));
        }

        if (m_mode == ANY_PREVIOUS_SIBLING) {
            for (;index >= 0; index--) {
                if (m_sibling->match(siblings.at(index))) {
                    return true;
                }
            }
        } else if (m_mode == ANY_NEXT_SIBLING) {
            for (;index < siblings.length(); index++) {
                if (m_sibling->match(siblings.at(index))) {
                    return true;
                }
            }
        } else if (m_mode == ANY_SIBLING) {
            for (int siblingIndex = 0; siblingIndex < siblings.length(); siblingIndex++) {
                if (siblingIndex != index && m_sibling->match(siblings.at(siblingIndex))) {
                    return true;
                }
            }
        }
    }

    return false;
}

ParentMatcher::ParentMatcher(SharedMatcher initial, SharedMatcher parent, ParentMatcher::MatchMode mode) : m_initial(initial), m_parent(parent), m_mode(mode) {}

bool ParentMatcher::match(QObject *object) const
{
    // start with finding last one first, then look up parents
    if (m_initial->match(object)) {
        return matchParent(object->parent());
    }

    return false;
}

// very recursion, much useful
bool ParentMatcher::matchParent(QObject *parent) const
{
    // ran out of valid objects to check, not matched
    if (parent == 0) {
        return false;
    }

    // apply current matcher on current object
    if (m_parent->match(parent)) {
        // use next matcher matching until run out of parents or matchers
        return true;
    }

    // ignore parents further up the chain
    if (m_mode != ANY_PARENT) {
        return false;
    }

    // go up in hierarchy, reapply matcher
    return matchParent(parent->parent());
}

QObjectList ObjectVisitor::findObjects(QObject *root, MatcherList matchers) const
{
    QObjectList matches;
    foreach( SharedMatcher sm, matchers) {
        matches.append(findObjects(root, sm));
    }
    return matches;
}

QObjectList ObjectVisitor::findObjects(QObject *root, SharedMatcher matcher) const
{
    Q_ASSERT(!matcher.isNull());
    return findObjects(root, *matcher.data());
}

QObjectList ObjectVisitor::findObjects(QObject *root, const Matcher &matcher) const
{
    QObjectList matches;
    collect(root, matcher, false, matches);

    return matches;
}

QObject* ObjectVisitor::findFirstObject(QObject *root, SharedMatcher matcher) const
{
    Q_ASSERT(!matcher.isNull());
    return findFirstObject(root, *matcher.data());
}

QObject* ObjectVisitor::findFirstObject(QObject *root, const Matcher &matcher) const
{
    QObjectList matches;
    collect(root, matcher, true, matches);

    if (matches.length() > 0) {
        return matches.at(0);
    } else {
        return NULL;
    }
}

bool ObjectVisitor::collect(QObject *object, const Matcher &matcher, bool stopOnFirst, QObjectList &matches) const
{
    if (matcher.match(object)) {
        matches.append(object);
        if (stopOnFirst) {
            return true;
        }
    }

    foreach (QObject *child, object->children()) {
        if (collect(child, matcher, stopOnFirst, matches)) {
            return true;
        }
    }

    return false;
}


