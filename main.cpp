#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QDebug>

#include <sstream>

#include "css/cssselector.h"
#include "matchers.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    {
        std::string selector = "#name Type.class[attrib= \"some value\" ]";
        css::CssSelector parser;
        parser.parse_string( selector );
    }

    {
        std::string selector = "a, b, c, d";
        css::CssSelector parser;
        parser.parse_string( selector );
    }

    {
        std::string selector = "a, b.c, d";
        css::CssSelector parser;
        parser.parse_string( selector );
    }

    {
        std::string selector = "a > b c d";
        css::CssSelector parser;
        parser.parse_string( selector );
    }

    QObject* root = engine.rootObjects().first();

    ObjectVisitor vis;
    qDebug() << vis.findObjects(root, NameMatcher("text"));
    qDebug() << vis.findObjects(root, PropertyMatcher("text", "Hello World 3"));
    qDebug() << vis.findObjects(root, ClassNameMatcher("QQuickRectangle"));
    qDebug() << vis.findObjects(root, QmlTypeMatcher("QQuickRectangle"));
    qDebug() << vis.findObjects(root, QmlTypeMatcher("YetAnother"));

    qDebug() << vis.findObjects(root, ChildHierarchyMatcher( MatcherList() <<
                                                             CreateSharedMatcher(QmlTypeMatcher("Other")) <<
                                                             CreateSharedMatcher(QmlTypeMatcher("QQuickRectangle")),
                                                             ChildHierarchyMatcher::ALL_CHILDREN
                                                  ));


    qDebug() << vis.findObjects(root, ChildHierarchyMatcher( MatcherList() <<
                                                             CreateSharedMatcher(QmlTypeMatcher("Other")) <<
                                                             CreateSharedMatcher(QmlTypeMatcher("QQuickRectangle")),
                                                             ChildHierarchyMatcher::DIRECT_CHILDREN
                                                  ));

    qDebug() << vis.findObjects(root, ChildHierarchyMatcher( MatcherList() <<
                                                             CreateSharedMatcher(QmlTypeMatcher("Other")) <<
                                                             CreateSharedMatcher(AndMatcher( CreateSharedMatcher(QmlTypeMatcher("QQuickLoader")),
                                                                                             CreateSharedMatcher(IndexedMatcher(1, IndexedMatcher::NTH)))) <<
                                                             CreateSharedMatcher(PropertyMatcher("dynamicTwo", 30)),
                                                             ChildHierarchyMatcher::ALL_CHILDREN
                                                      ));

    qDebug() << vis.findObjects(root, SiblingMatcher( CreateSharedMatcher(QmlTypeMatcher("QQuickRectangle")),
                                                      CreateSharedMatcher(QmlTypeMatcher("QObject")),
                                                      SiblingMatcher::NEXT_SIBLING));

    qDebug() << vis.findObjects(root, SiblingMatcher( CreateSharedMatcher(QmlTypeMatcher("QObject")),
                                                      CreateSharedMatcher(QmlTypeMatcher("QQuickRectangle")),
                                                      SiblingMatcher::PREVIOUS_SIBLING));

//    return app.exec();
    return 0;
}
