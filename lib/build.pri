SOURCES += $$files($$PWD/*.cpp, true)
HEADERS += $$files($$PWD/*.h, true)
HEADERS += $$files($$PWD/*.hh, true)

INCLUDEPATH += $$PWD/css

import($$PWD/dependency.pri)


