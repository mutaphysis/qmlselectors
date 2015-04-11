import QtQuick 2.1

Rectangle {
    id: root
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

    Timer {
        interval: 1000
        running: true
        repeat: true
        triggeredOnStart: true

        property var obj: null
        property int count: 0

        onTriggered: {
            if (obj) {
                print("destroying ", count - 1);
                obj.destroy();
                obj = null;
            } else {
                print("creating ", count);
                obj = creator.createObject(root, {index: count++});
            }
        }
    }

    Component {
        id: creator
        Other {
            objectName: "createdObject" + index
            property int index: 0
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

            Text {
                objectName: "text2"
                anchors.centerIn: parent
                text: "Hello World 3"
            }
        }

        Other {
            YetAnother {
                Loader {
                    sourceComponent: YetAnother {
                        objectName: "loaderInstance1"
                    }
                }
                Loader {
                    sourceComponent: YetAnother {
                        objectName: "loaderInstance2"
                        property int dynamicThree: 12345
                    }
                }
                Loader {
                    sourceComponent: Rectangle {
                        objectName: "loaderInstance3"
                        property int text: 12345
                    }
                }
            }
        }

        Rectangle {
            objectName: "notext1"
            anchors.centerIn: parent
            property string text: "Hello World 3"
        }

        QtObject {
            objectName: "notext2"
            property var text: "Hello World 3"
        }
    }
}

