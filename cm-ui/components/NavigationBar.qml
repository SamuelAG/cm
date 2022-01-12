import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import assets 1.0
import components 1.0

Item {
    property bool isCollapsed: true
    anchors {
        top: parent.top
        bottom: parent.bottom
        left: parent.left
    }
    width: isCollapsed ? Style.widthNavigationBarCollapsed : Style.heightNavigationBarExpanded
    Rectangle {
        anchors.fill: parent
        color: Style.colourNavigationBarBackground
        Column {
            width: parent.width
            NavigationButton {
                iconCharacter: "\uf0c9"
                description: ""
                hoverColour: "#993333"
                onNavigationButtononClicked: isCollapsed = !isCollapsed
            }
            NavigationButton {
                iconCharacter: "\uf015"
                description: "DashBoard"
                hoverColour: "#dc8a00"
                onNavigationButtononClicked: masterController.ui_navigationController.goDashboardView()
            }
            NavigationButton {
                iconCharacter: "\uf234"
                description: "New Client"
                hoverColour: "#dccd00"
                onNavigationButtononClicked: masterController.ui_navigationController.goCreateClientView()
            }
            NavigationButton {
                iconCharacter: "\uf002"
                description: "Find Client"
                hoverColour: "#8aef63"
                onNavigationButtononClicked: masterController.ui_navigationController.goFindClientView()
            }
        }
    }
}


