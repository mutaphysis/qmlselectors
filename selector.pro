TEMPLATE = app

QT += qml quick

SOURCES += \
    css/gen/cssselector.scanner.cc \
    css/gen/cssselector.parser.cc \
    css/cssselector.cpp \
    matchers.cpp \
    main.cpp

HEADERS += \
    css/gen/cssselector.parser.hh \
    css/gen/location.hh \
    css/gen/position.hh \
    css/gen/stack.hh \
    css/cssselector.h \
    css/cssselectorscanner.h \
    matchers.h

# flex --header-file=lexer.h cssselector.l
OTHER_FILES += \
    css/cssselector.ll \
    css/cssselector.yy

RESOURCES += qml.qrc

macx:LIBS += -ll

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

DISTFILES += \
    cssselector.yy
