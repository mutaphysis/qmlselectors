#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QDebug>

#include <sstream>

#include "css/cssselector.h"

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
    std::string selector = "a, b.c, d";
    css::CssSelector parser;
    parser.parse_string( selector );
    }

    {
    std::string selector = "a b c d";
    css::CssSelector parser;
    parser.parse_string( selector );
    }

    qDebug() << engine.rootObjects();

//    return app.exec();
    return 0;
}
