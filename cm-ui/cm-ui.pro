QT += qml quick
TEMPLATE = app
CONFIG += c++14

include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

INCLUDEPATH += source \
    ../cm-lib/source
SOURCES += source/main.cpp
RESOURCES += views.qrc \
    assets.qrc
LIBS += -L$$PWD/../binaries/$$DESTINATION_PATH -lcm-lib
# Additional import path used to resolve QML modules in Qt Creator's code
model
QML_IMPORT_PATH = $$PWD

