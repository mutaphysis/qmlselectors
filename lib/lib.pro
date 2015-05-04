TEMPLATE = lib
TARGET = qmlselectors
CONFIG += staticlib

QT += qml quick

SOURCES += $$files($$PWD/*.cpp, true)
SOURCES += $$files($$PWD/*.cc, true)
HEADERS += $$files($$PWD/*.h, true)
HEADERS += $$files($$PWD/*.hh, true)

INCLUDEPATH += $$PWD/css
INCLUDEPATH += $$PWD/css/gen

OTHER_FILES += \
    $$PWD/css/cssselector.ll \
    $$PWD/css/cssselector.yy
