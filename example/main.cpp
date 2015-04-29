#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QDebug>

#include <sstream>

#include "css/cssselector.h"

#include "matchers.h"
#include "matchergenerator.h"
#include "watcher.h"

void testParsing()
{
    {
        MatcherGenerator mg;
        std::string selector = "#name";
        css::CssSelector parser(&mg);
        parser.parse_string( selector );
    }

    {
        MatcherGenerator mg;
        std::string selector = "Type#name.class[attrib= \"some value\" ]";
        css::CssSelector parser(&mg);
        parser.parse_string( selector );
    }


    {
        MatcherGenerator mg;
        std::string selector = "a, b, c, d";
        css::CssSelector parser(&mg);
        parser.parse_string( selector );
    }

    {
        MatcherGenerator mg;
        std::string selector = "a b c d";
        css::CssSelector parser(&mg);
        parser.parse_string( selector );
    }

    {
        MatcherGenerator mg;
        std::string selector = "a.class b.class c.class d.class";
        css::CssSelector parser(&mg);
        parser.parse_string( selector );
    }

    {
        MatcherGenerator mg;
        std::string selector = "a, b.c, d";
        css::CssSelector parser(&mg);
        parser.parse_string( selector );
    }

    {
        MatcherGenerator mg;
        std::string selector = "a > b c d";
        css::CssSelector parser(&mg);
        parser.parse_string( selector );
    }
}

void testMatching(QObject* root)
{
    qDebug() << ObjectVisitor::findObjects(root, NameMatcher("text"));
    qDebug() << ObjectVisitor::findObjects(root, PropertyMatcher("text", "Hello World 3"));
    qDebug() << ObjectVisitor::findObjects(root, ClassNameMatcher("QQuickRectangle"));
    qDebug() << ObjectVisitor::findObjects(root, QmlTypeMatcher("QQuickRectangle"));
    qDebug() << ObjectVisitor::findObjects(root, QmlTypeMatcher("YetAnother"));

    qDebug() << ObjectVisitor::findObjects(root, ParentMatcher( CreateSharedMatcher(QmlTypeMatcher("QQuickRectangle")),
                                                     CreateSharedMatcher(QmlTypeMatcher("Other")),
                                                     ParentMatcher::ANY_PARENT));

    qDebug() << ObjectVisitor::findObjects(root, ParentMatcher( CreateSharedMatcher(QmlTypeMatcher("QQuickRectangle")),
                                                     CreateSharedMatcher(QmlTypeMatcher("Other")),
                                                     ParentMatcher::DIRECT_PARENT));

    qDebug() << ObjectVisitor::findObjects(root, ParentMatcher( CreateSharedMatcher(PropertyMatcher("dynamicTwo", 30)),
                                                     CreateSharedMatcher(ParentMatcher(
                                                             CreateSharedMatcher(AndMatcher( CreateSharedMatcher(QmlTypeMatcher("QQuickLoader")),
                                                                                             CreateSharedMatcher(IndexedMatcher(1, IndexedMatcher::NTH)))),
                                                             CreateSharedMatcher(QmlTypeMatcher("Other")),
                                                             ParentMatcher::ANY_PARENT)),
                                                     ParentMatcher::ANY_PARENT));

    qDebug() << ObjectVisitor::findObjects(root, SiblingMatcher( CreateSharedMatcher(QmlTypeMatcher("QQuickRectangle")),
                                                      CreateSharedMatcher(QmlTypeMatcher("QObject")),
                                                      SiblingMatcher::NEXT_SIBLING));

    qDebug() << ObjectVisitor::findObjects(root, SiblingMatcher( CreateSharedMatcher(QmlTypeMatcher("QObject")),
                                                      CreateSharedMatcher(QmlTypeMatcher("QQuickRectangle")),
                                                      SiblingMatcher::PREVIOUS_SIBLING));
}

void testCssMatching(QObject* root)
{
    qDebug() << ObjectVisitor::findObjects(root, "#text");
    qDebug() << ObjectVisitor::findObjects(root, "QQuickText");
    qDebug() << ObjectVisitor::findObjects(root, "[text=\"Hello World 3\"]");
    qDebug() << ObjectVisitor::findObjects(root, "QQuickText#text2");
    qDebug() << ObjectVisitor::findObjects(root, "QQuickText#text2[text='Hello World 3']");
    qDebug() << ObjectVisitor::findObjects(root, "#text #text #text2");
    qDebug() << ObjectVisitor::findObjects(root, "#text:first-child");
    qDebug() << ObjectVisitor::findObjects(root, "#text2:nth-child(1)");
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject* root = engine.rootObjects().first();
    testParsing();
    testMatching(root);
    testCssMatching(root);

    Watcher w(root, "#createdObject3");
    w.start(100);
    QObject::connect(&w, &Watcher::triggered, &app, &QGuiApplication::quit);

    return app.exec();
//    return 0;
}
