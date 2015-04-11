TEMPLATE = app

QT += qml quick

SOURCES += \
    css/gen/cssselector.scanner.cc \
    css/gen/cssselector.parser.cc \
    css/cssselector.cpp \
    matchers.cpp \
    matchergenerator.cpp \
    main.cpp

HEADERS += \
    css/gen/cssselector.parser.hh \
    css/gen/location.hh \
    css/gen/position.hh \
    css/gen/stack.hh \
    css/cssselector.h \
    css/cssselectorscanner.h \
    matchers.h \
    matchergenerator.h

OTHER_FILES += \
    css/cssselector.ll \
    css/cssselector.yy

RESOURCES += qml.qrc

# osx lexer dependency
macx:LIBS += -ll

# Default rules for deployment.
include(deployment.pri)

DISTFILES += \
    cssselector.yy
