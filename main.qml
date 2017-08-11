import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ListView {
        anchors.fill: parent
        model: mymodel
        delegate: Text { text: "Animal: " + onerole + ", " + tworole }
    }
}
