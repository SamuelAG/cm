QT += qml quick
TEMPLATE = app
CONFIG += c++14
INCLUDEPATH += source
SOURCES += source/main.cpp
RESOURCES += views.qrc
# Additional import path used to resolve QML modules in Qt Creator's code
model
QML_IMPORT_PATH = $$PWD
