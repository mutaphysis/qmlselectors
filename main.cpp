#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QDebug>

#include <sstream>

#include "css/cssselector.h"

#include "matchers.h"
#include "matchergenerator.h"

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
    ObjectVisitor vis;
    qDebug() << vis.findObjects(root, NameMatcher("text"));
    qDebug() << vis.findObjects(root, PropertyMatcher("text", "Hello World 3"));
    qDebug() << vis.findObjects(root, ClassNameMatcher("QQuickRectangle"));
    qDebug() << vis.findObjects(root, QmlTypeMatcher("QQuickRectangle"));
    qDebug() << vis.findObjects(root, QmlTypeMatcher("YetAnother"));

    qDebug() << vis.findObjects(root, ParentMatcher( CreateSharedMatcher(QmlTypeMatcher("QQuickRectangle")),
                                                     CreateSharedMatcher(QmlTypeMatcher("Other")),
                                                     ParentMatcher::ANY_PARENT));

    qDebug() << vis.findObjects(root, ParentMatcher( CreateSharedMatcher(QmlTypeMatcher("QQuickRectangle")),
                                                     CreateSharedMatcher(QmlTypeMatcher("Other")),
                                                     ParentMatcher::DIRECT_PARENT));

    qDebug() << vis.findObjects(root, ParentMatcher( CreateSharedMatcher(PropertyMatcher("dynamicTwo", 30)),
                                                     CreateSharedMatcher(ParentMatcher(
                                                             CreateSharedMatcher(AndMatcher( CreateSharedMatcher(QmlTypeMatcher("QQuickLoader")),
                                                                                             CreateSharedMatcher(IndexedMatcher(1, IndexedMatcher::NTH)))),
                                                             CreateSharedMatcher(QmlTypeMatcher("Other")),
                                                             ParentMatcher::ANY_PARENT)),
                                                     ParentMatcher::ANY_PARENT));

    qDebug() << vis.findObjects(root, SiblingMatcher( CreateSharedMatcher(QmlTypeMatcher("QQuickRectangle")),
                                                      CreateSharedMatcher(QmlTypeMatcher("QObject")),
                                                      SiblingMatcher::NEXT_SIBLING));

    qDebug() << vis.findObjects(root, SiblingMatcher( CreateSharedMatcher(QmlTypeMatcher("QObject")),
                                                      CreateSharedMatcher(QmlTypeMatcher("QQuickRectangle")),
                                                      SiblingMatcher::PREVIOUS_SIBLING));
}

void testCssMatching(QObject* root)
{
    {
        ObjectVisitor vis;
        MatcherGenerator mg;
        std::string selector = "#text";
        css::CssSelector parser(&mg);
        parser.parse_string( selector );

        MatcherList list = mg.results();
        qDebug() << vis.findObjects(root, list.at(0));
    }
    {
        ObjectVisitor vis;
        MatcherGenerator mg;
        std::string selector = "QQuickText";
        css::CssSelector parser(&mg);
        parser.parse_string( selector );

        MatcherList list = mg.results();
        qDebug() << vis.findObjects(root, list.at(0));
    }
    {
        ObjectVisitor vis;
        MatcherGenerator mg;
        std::string selector = "[text=\"Hello World 3\"]";
        css::CssSelector parser(&mg);
        parser.parse_string( selector );

        MatcherList list = mg.results();
        qDebug() << vis.findObjects(root, list.at(0));
    }
    {
        ObjectVisitor vis;
        MatcherGenerator mg;
        std::string selector = "QQuickText#text2";
        css::CssSelector parser(&mg);
        parser.parse_string( selector );

        MatcherList list = mg.results();
        qDebug() << vis.findObjects(root, list.at(0));
    }
    {
        ObjectVisitor vis;
        MatcherGenerator mg;
        std::string selector = "QQuickText#text2[text='Hello World 3']";
        css::CssSelector parser(&mg);
        parser.parse_string( selector );

        MatcherList list = mg.results();
        qDebug() << vis.findObjects(root, list.at(0));
    }
    {
        ObjectVisitor vis;
        MatcherGenerator mg;
        std::string selector = "#text #text #text2";
        css::CssSelector parser(&mg);
        parser.parse_string( selector );

        MatcherList list = mg.results();
        qDebug() << vis.findObjects(root, list.at(0));
    }
    {
        ObjectVisitor vis;
        MatcherGenerator mg;
        std::string selector = "#text:last-child";
        css::CssSelector parser(&mg);
        parser.parse_string( selector );

        MatcherList list = mg.results();
        qDebug() << vis.findObjects(root, list.at(0));
    }
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject* root = engine.rootObjects().first();
//    testParsing();
//    testMatching(root);
//    testCssMatching(root);

    {
        ObjectVisitor vis;
        MatcherGenerator mg;
        std::string selector = "#text:last-child Text:nth-child(1)";
        css::CssSelector parser(&mg);
        parser.parse_string( selector );

        MatcherList list = mg.results();
        qDebug() << vis.findObjects(root, list.at(0));
    }


//    return app.exec();
    return 0;
}
