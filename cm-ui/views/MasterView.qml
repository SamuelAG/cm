import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import assets 1.0
import components 1.0

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

    NavigationBar {
        id: navigationBar
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
}
