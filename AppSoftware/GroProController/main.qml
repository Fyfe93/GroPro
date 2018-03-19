import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("GroProControllerWindow")

    Text {
        id: text1
        x: 56
        y: 17
        width: 257
        height: 38
        color: "#34c52c"
        text: qsTr("GroPro Controller")
        anchors.horizontalCenter: parent.horizontalCenter
        font.italic: false
        font.bold: true
        textFormat: Text.AutoText
        wrapMode: Text.NoWrap
        font.pixelSize: 30
    }

    Slider {
        id: vBrightnessSlider
        x: 70
        y: 74
        width: 372
        height: 40
        anchors.horizontalCenter: parent.horizontalCenter
        value: 0.5
    }

    Slider {
        id: uvBrightnessSlider
        x: 70
        y: 133
        width: 372
        height: 40
        anchors.horizontalCenter: parent.horizontalCenter
        value: 0.5
    }

    Slider {
        id: irBrightnessSlider
        x: 70
        y: 190
        width: 372
        height: 40
        anchors.horizontalCenter: parent.horizontalCenter
        value: 0.5
    }

    Button {
        id: connectButton
        x: 221
        y: 313
        width: 198
        height: 40
        text: "Connect"
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        highlighted: false
        font.pointSize: 18
    }

    Button {
        id: disconnectButton
        x: 94
        y: 380
        width: 198
        height: 40
        text: qsTr("Disconnect")
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        font.pointSize: 18
    }

    TextField {
        id: textField
        x: 221
        y: 243
        text: qsTr("Port No.")
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
