import QtQuick 2.15
import assets 1.0
import components 1.0

Item {
    Rectangle {
        anchors.fill: parent
        color: Style.colourBackGround
        Text {
            anchors.centerIn: parent
            text: "Find Client View"
        }
    }
    CommandBar {
        commandList: masterController.ui_commandcontroller.ui_findClientViewContextCommands
    }
}
