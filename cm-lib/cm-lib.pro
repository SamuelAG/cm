QT -= gui

TEMPLATE = lib
DEFINES += CMLIB_LIBRARY

CONFIG += c++11

include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

INCLUDEPATH += source

SOURCES += source/models/client.cpp \
    source/controllers/command_controller.cpp \
    source/controllers/master_controller.cpp \
    source/data/data_decorator.cpp \
    source/data/datetime_decorator.cpp \
    source/data/entity.cpp \
    source/data/enumerator_decorator.cpp \
    source/data/int_decorator.cpp \
    source/data/string_decorator.cpp \
    source/framework/command.cpp

HEADERS += source/cm-lib_global.h \
    source/controllers/command_controller.h \
    source/controllers/master_controller.h \
    source/controllers/navigation_controller.h \
    source/data/data_decorator.h \
    source/data/datetime_decorator.h \
    source/data/entity.h \
    source/data/enumerator_decorator.h \
    source/data/int_decorator.h \
    source/data/string_decorator.h \
    source/framework/command.h \
    source/models/client.h

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
