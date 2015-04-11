#ifndef MATCHERS
#define MATCHERS

#include <QObject>
#include <QVariant>
#include <QMetaObject>
#include <QRegularExpression>
#include <QSharedPointer>

/**
 * The Matcher Interface.
 *
 * Allows matching QObject in the QObject tree by using the @see ObjectVisitor.
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
 * Matches two matchers against a QObject and its parent hierarchy.
 * Starts with the initial Matcher.
 * If a match is found, matches the parent matcher with the parent node.
 * If no match is found, continues through the hierarchy.
 * If a match is found, returns true.
 * Aborts when no more parent nodes exist.
 */
class ParentMatcher : public Matcher
{
public:
    enum MatchMode { ANY_PARENT, DIRECT_PARENT };

    ParentMatcher(SharedMatcher initial, SharedMatcher parent, MatchMode mode);

    virtual bool match(QObject *object) const;
private:
    bool matchParent(QObject *parent) const;

    const SharedMatcher m_initial;
    const SharedMatcher m_parent;
    const bool m_mode;
};


/**
 * Collection of helper functions for applying matchers to the QObject tree.
 */
class ObjectVisitor
{
public:

    /**
     * Finds all the objects matching the given selector.
     *
     * Starts checking at the root node, and continues to check all sub-sequent children.
     * Any object for which the selector matches, is collected and later returned.
     *
     * @param root The root node to start
     * @param selector The selector to check against
     * @return The List of objects matching the matcher
     */
    static QObjectList findObjects(QObject *root, const QString& selector);
    /**
     * Finds all the objects matching any of the given matchers.
     *
     * Starts checking at the root node, and continues to check all sub-sequent children.
     * Any object for which a matcher matches, is collected and later returned.
     *
     * @param root The root node to start
     * @param matchers The matchers to check against
     * @return The List of objects matching the matcher
     */
    static QObjectList findObjects(QObject *root, const MatcherList& matchers);
    /**
     * Finds all the objects matching the given matcher.
     *
     * Starts checking at the root node, and continues to check all sub-sequent children.
     * Any object for which the matcher matches, is collected and later returned.
     *
     * @param root The root node to start
     * @param matcher The matcher to check against
     * @return The List of objects matching the matcher
     */
    static QObjectList findObjects(QObject *root, SharedMatcher matcher);
    /**
     * Finds all the objects matching the given matcher.
     *
     * Starts checking at the root node, and continues to check all sub-sequent children.
     * Any object for which the matcher matches, is collected and later returned.
     *
     * @param root The root node to start
     * @param matcher The matcher to check against
     * @return The List of objects matching the matcher
     */
    static QObjectList findObjects(QObject *root, const Matcher& matcher);

    /**
     * Like @see findObjects, but returns only the first node matching the selector.
     * @param root The root node to start
     * @param selector The selector to check against
     * @return The object matched, or NULL if none matched
     */
    static QObject* findFirstObject(QObject *root, const QString& selector);
    /**
     * Like @see findObjects, but returns only the first node matching any of the matchers.
     * @param root The root node to start
     * @param matchers The matchers to check against
     * @return The object matched, or NULL if none matched
     */
    static QObject* findFirstObject(QObject *root, const MatcherList& matchers);
    /**
     * Like @see findObjects, but returns only the first node matching the matcher.
     * @param root The root node to start
     * @param matcher The matcher to check against
     * @return The object matched, or NULL if none matched
     */
    static QObject* findFirstObject(QObject *root, SharedMatcher matcher);
    /**
     * Like @see findObjects, but returns only the first node matching the matcher.
     * @param root The root node to start
     * @param matcher The matcher to check against
     * @return The object matched, or NULL if none matched
     */
    static QObject* findFirstObject(QObject *root, const Matcher& matcher);

private:
    static bool collect(QObject *object, const Matcher& matcher, bool stopOnFirst, QObjectList& matches);
};

#endif // MATCHERS

