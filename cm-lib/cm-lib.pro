QT -= gui

TEMPLATE = lib
DEFINES += CMLIB_LIBRARY

CONFIG += c++11

INCLUDEPATH += source

SOURCES += source/models/client.cpp

HEADERS += source/cm-lib_global.h \
    source/models/client.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
