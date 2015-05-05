QT += qml quick

SOURCES += $$files($$PWD/*.cpp, true)
SOURCES += $$files($$PWD/*.cc, true)
HEADERS += $$files($$PWD/*.h, true)
HEADERS += $$files($$PWD/*.hh, true)

INCLUDEPATH += $$PWD/
INCLUDEPATH += $$PWD/css
INCLUDEPATH += $$PWD/css/gen

# Ignore wanring in generated code
QMAKE_CXXFLAGS_WARN_ON += \
    -Wno-type-limits

# osx lexer dependency
macx {
    LIBS += -ll
}
