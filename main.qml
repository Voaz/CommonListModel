import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Item {
        id: root
        anchors.fill: parent
        Item {
            id: listview
            anchors.topMargin: 0
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.rightMargin: 0
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.right: tableview.left
            ListView {
                anchors.fill: parent
                model: mymodel
                delegate: Text { text: "Data: " + onerole + ", " + tworole }
            }
        }
        Item {
            id: tableview
            width: parent.width / 2
            anchors.leftMargin: 640
            anchors.bottomMargin: 0
            anchors.topMargin: 0
            anchors.rightMargin: 0
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            TableView {
                anchors.fill: parent
                model: mymodel
                TableViewColumn {
                    width: 180
                    role: "onerole"
                    title: "One Role"
                }
                TableViewColumn {
                    width: 180
                    role: "tworole"
                    title: "Two Role"
                }
            }
        }
    }
}
