QT += qml quick

INCLUDEPATH += $$PWD/

# osx lexer dependency
macx {
    LIBS += -ll
}

LIBS += $$OUT_PWD/../lib/libqmlselectors.a
PRE_TARGETDEPS += $$OUT_PWD/../lib/libqmlselectors.a
