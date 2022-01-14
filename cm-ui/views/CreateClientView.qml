import QtQuick 2.15
import QtQuick.Controls 2.15
import assets 1.0
import components 1.0
import CM 1.0

Item {
    property Client newClient: masterController.ui_newClient
    Rectangle {
        anchors.fill: parent
        color: Style.colourBackGround
    }

    ScrollView {
        id: scrollView
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
            bottom: commandBar.top
            margins: Style.sizeScreenMargin
        }
        clip: true
        Column {
            spacing: Style.sizeScreenMargin
            width: scrollView.width
            StringEditorSingleLine {
                stringDecorator: newClient.ui_name
                anchors {
                    left: parent.left
                    right: parent.right
                }
            }
        }
    }

    CommandBar {
        id: commandBar
        commandList: masterController.ui_commandcontroller.ui_createClientViewContextCommands
    }
}
