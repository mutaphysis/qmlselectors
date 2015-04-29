TEMPLATE = app

QT += qml quick

SOURCES += main.cpp
RESOURCES += qml.qrc

include(deployment.pri)
include($$PWD/../lib/dependency.pri)

