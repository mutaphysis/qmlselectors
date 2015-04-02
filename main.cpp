#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QDebug>

#include <sstream>

extern "C" {
    #include "cssselector.tab.h"

    extern int yyparse();
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    std::string selector = "#name Type.class[@attrib= \"some value\" ]";

    yyparse();

    qDebug() << engine.rootObjects();

//    return app.exec();
    return 0;
}
