import QtQuick 2.1
import QtQuick.Controls 1.0


ApplicationWindow {
    id: appWnd
    visible: true
    width: 640
    height: 480
    title: qsTr(" ")


    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();


            }
        }
    }

    Connections {
        target: okBtn
        onClicked: Qt.quit();
    }

    Grid {
        id: infogrid
        x: 12
        y: 16
        width: 616
        height: 448
        z: -1
        Label {
            id: lblsysInfo
            color: "#030518"
            text: qsTr("System Information")
            anchors.right: parent.right
            anchors.rightMargin: 233
            anchors.left: parent.left
            anchors.leftMargin: 241
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 444
            anchors.top: parent.top
            anchors.topMargin: 13
            font.pointSize: 19
        }

        TextField {
            id: lstview
            width: 500
            height: 351
            text: "Could not get System information"
            font.pointSize: 14
            echoMode: TextInput.NoEcho
            anchors.right: parent.right
            anchors.rightMargin: 41
            anchors.left: parent.left
            anchors.leftMargin: 44
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 49
            anchors.top: infoImage.bottom
            anchors.topMargin: 12
            font.bold: false
            readOnly: true

            placeholderText: qsTr("Could not get System information")
            objectName: "lstview"
        }

        Image {
            id: infoImage
            x: 200
            y: 11
            width: 31
            height: 31
            source: "Infoicon.png"
        }
        Connections {
            target: okBtn
            onClicked: Qt.quit();
        }


    }

    Button {
        id: okBtn
        x: 530
        y: 432
        text: qsTr("OK")
        z: 1
    }


}
