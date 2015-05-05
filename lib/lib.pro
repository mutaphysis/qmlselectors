TEMPLATE = lib
TARGET = qmlselectors
CONFIG += staticlib

include($$PWD/build.pri)

OTHER_FILES += \
    $$PWD/css/cssselector.ll \
    $$PWD/css/cssselector.yy
