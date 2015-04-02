TEMPLATE = app

QT += qml quick

SOURCES += \
    main.cpp \
    lex.yy.c \
    cssselector.tab.c

HEADERS += \
    cssparser.h \
    cssselector.tab.h

# flex --header-file=lexer.h cssselector.l
OTHER_FILES += cssselector.l cssselector.y

RESOURCES += qml.qrc

macx:LIBS += -ll

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
