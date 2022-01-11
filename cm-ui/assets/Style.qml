pragma Singleton
import QtQuick 2.15

Item {
    property alias fontAwesome: fontAwesomeLoader.name
    readonly property color colourBackGround: "#efefef"
    FontLoader {
        id: fontAwesomeLoader
        source: "qrc:/assets/fontawesome.ttf"
    }
}
