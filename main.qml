import QtQuick 2.1

Rectangle {
    width: 360
    height: 360
    objectName: "rectangle"

    MouseArea {
        objectName: "mouseArea"
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }

        function test() {
            clicked(null);
            return "hello";
        }
    }

    Text {
        objectName: "text"
        anchors.centerIn: parent
        text: "Hello World"

        Text {
            objectName: "text"
            anchors.centerIn: parent
            text: "Hello World 2"

            Text {
                objectName: "text"
                anchors.centerIn: parent
                text: "Hello World 3"
            }
        }
    }
}

