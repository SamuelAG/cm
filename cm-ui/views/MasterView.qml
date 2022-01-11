import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 1024
    height: 768
    visible: true
    title: qsTr("Client Management")

    Connections {
        target: masterController.ui_navigationController
        function onGoCreateClientView() { contentFrame.replace("qrc:/views/CreateClientView") }
        function onGoDashboardView() { contentFrame.replace("qrc:/views/DashboardView") }
        function onGoEditClientView(client) { contentFrame.replace("qrc:/views/EditClientView", {selectedClient: client}) }
        function onGoFindClientView() { contentFrame.replace("qrc:/views/FindClientView") }
    }

    StackView {
        id: contentFrame
        clip: true
        anchors {
            top: parent.top
            bottom: parent.bottom
            right: parent.right
            left: navigationBar.right
        }
        initialItem: "qrc:/views/SplashView"
    }

    Rectangle {
        id: navigationBar
        Column {
            Button {
                text: "DashBoard"
                onClicked: masterController.ui_navigationController.goDashboardView()
            }
            Button {
                text: "New Client"
                onClicked: masterController.ui_navigationController.goCreateClientView()
            }
            Button {
                text: "Find Client"
                onClicked: masterController.ui_navigationController.goFindClientView()
            }
        }

        anchors {
            top: parent.top
            bottom: parent.bottom
            left: parent.left
        }
        width: 100
        color: "#000000"
    }
}
