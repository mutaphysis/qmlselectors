#ifndef MATCHERS
#define MATCHERS

#include <QObject>
#include <QVariant>
#include <QMetaObject>
#include <QRegularExpression>
#include <QSharedPointer>

/**
 * Matcher Interface
 */
class Matcher
{
public:
    virtual ~Matcher();

    virtual bool match(QObject *object) const = 0;
};

typedef QSharedPointer< const Matcher > SharedMatcher;
typedef QList< QSharedPointer< const Matcher > > MatcherList;
#define CreateSharedMatcher(MATCHER_INIT) (QSharedPointer< const Matcher >(new MATCHER_INIT))

/**
 * Matches QObject by their objectName property
 */
class NameMatcher : public Matcher
{
public:
    NameMatcher(const QString& name);

    virtual bool match(QObject *object) const;
private:
    const QString m_name;
};

/**
 * Inverts a matcher
 */
class NotMatcher : public Matcher
{
public:
    NotMatcher(SharedMatcher matcher);

    virtual bool match(QObject *object) const;
private:
    const SharedMatcher m_matcher;
};

/**
 * Inverts a matcher
 */
class AndMatcher : public Matcher
{
public:
    AndMatcher(SharedMatcher matcherA, SharedMatcher matcherB);

    virtual bool match(QObject *object) const;
private:
    const SharedMatcher m_matcherA;
    const SharedMatcher m_matcherB;
};

/**
 * Easy guy. Okay with everything.
 */
class AnyMatcher : public Matcher
{
public:
    AnyMatcher();

    virtual bool match(QObject */*object*/) const;
};

/**
 * Matches QObject by their className.
 * Be aware that qml items that are declared in QML or
 * that have dynamic properties added in QML will have unexpected classnames
 * eg. ClassName_QMLTYPE_1, ClassName_QMLTYPE_1_QML_1, ClassName_QML_1
 *
 * Use the QmlTypeMatcher for these instances.
 */
class ClassNameMatcher : public Matcher
{
public:
    ClassNameMatcher(const QString& typeName);

    virtual bool match(QObject *object) const;
private:
    const QString m_typeName;
};

/**
 * Matches by index in parent object
 *
 * Can support
 * :first-child
 * :last-child
 * :nth-child
 * :nth-last-child
 */
class IndexedMatcher : public Matcher
{
public:
    enum MatchMode { NTH, NTH_LAST, FIRST, LAST };

    IndexedMatcher(int index, MatchMode mode);
    IndexedMatcher(MatchMode mode);

    virtual bool match(QObject *object) const;
private:
    const int m_index;
    const MatchMode m_mode;
};


/**
 * Matches QObjects by their QML Type name:
 *
 * e.g. ClassName_QMLTYPE_1, ClassName_QMLTYPE_1_QML_1, ClassName_QML_1
 * will all match with ClassName.
 */
class QmlTypeMatcher : public Matcher
{
public:
    QmlTypeMatcher(const QString& typeName);

    virtual bool match(QObject *object) const;
private:
    static const QRegularExpression QML_TY4PE_RE;
    const QString m_typeName;
};

/**
 * Matches property by equality
 */
class PropertyMatcher : public Matcher
{
public:
    PropertyMatcher(const QString& property, const QVariant& value);
    PropertyMatcher(const QString& property);

    virtual bool match(QObject *object) const;
private:
    const QString m_property;
    const QVariant m_value;
    const bool m_exists; // check if is existing only
};

/**
 * Matches next and previous sibling
 */
class SiblingMatcher : public Matcher
{
public:
    enum MatchMode { NEXT_SIBLING, PREVIOUS_SIBLING, ANY_PREVIOUS_SIBLING, ANY_NEXT_SIBLING, ANY_SIBLING };

    SiblingMatcher(SharedMatcher initial, SharedMatcher sibling, MatchMode mode);

    virtual bool match(QObject *object) const;
private:
    const SharedMatcher m_initial;
    const SharedMatcher m_sibling;
    const MatchMode m_mode;
};

/**
 * Matches a set of matchers against a QObject and its parent hierarchy.
 * Starts with the last matcher in the MatcherList.
 * If a match is found, matches the previous matcher with the parent node.
 * If no match is found, continues through the hierarchy.
 * If a match is found, continues through the hierarchy with the previous matcher.
 * Finishes when all matches were found or no more parent nodes exist.
 */
class ChildHierarchyMatcher : public Matcher
{
public:
    enum MatchMode { ALL_CHILDREN, DIRECT_CHILDREN };

    ChildHierarchyMatcher(const MatcherList& matchers, MatchMode mode) : m_matchers(matchers), m_mode(mode) {}

    virtual bool match(QObject *object) const;
private:
    bool matchHierarchy(QObject *object, int matcherIndex) const;

    const MatcherList m_matchers;
    const bool m_mode;
};

class ObjectVisitor
{
public:
    QObjectList findObjects(QObject *root, const Matcher& matcher) const;
    QObjectList findFirstObject(QObject *root, const Matcher& matcher) const;

private:
    bool collect(QObject *object, const Matcher& matcher, bool stopOnFirst, QObjectList& matches) const;
};

#endif // MATCHERS

