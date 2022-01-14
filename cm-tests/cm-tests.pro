QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TARGET = client-tests
TEMPLATE = app

include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

INCLUDEPATH += source \
    ../cm-lib/source

SOURCES +=  source/models/tst_clienttests.cpp \
    source/controllers/master_controller_tests.cpp \
    source/data/datetime_decorator_tests.cpp \
    source/data/enumerator_decorator_tests.cpp \
    source/data/int_decorator_tests.cpp \
    source/data/string_decorator_tests.cpp \
    source/main.cpp \
    source/test_suite.cpp

HEADERS += \
    source/controllers/master_controller_tests.h \
    source/data/datetime_decorator_tests.h \
    source/data/enumerator_decorator_tests.h \
    source/data/int_decorator_tests.h \
    source/data/string_decorator_tests.h \
    source/test_suite.h

LIBS += -L$$PWD/../binaries/$$DESTINATION_PATH -lcm-lib
