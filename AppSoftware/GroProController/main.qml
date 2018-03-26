import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Dialogs 1.1

Window {
    id: window
    visible: true
    width: 360
    height: 640
    color: "#1bbf64"
    title: qsTr("GroProControllerWindow")

    Image {
        id: groProImage
        y: 426
        height: 140
        anchors.right: parent.right
        anchors.rightMargin: 193
        anchors.left: parent.left
        anchors.leftMargin: 12
        clip: false
        fillMode: Image.PreserveAspectFit
        sourceSize.height: -7
        sourceSize.width: 0
        opacity: 1
        source: "GroProLogo"
    }

    Text {
        id: text1
        x: 56
        y: 16
        width: 323
        height: 44
        color: "#ffffff"
        text: qsTr("GroPro Controller")
        anchors.horizontalCenterOffset: 1
        font.strikeout: false
        font.underline: false
        anchors.horizontalCenter: parent.horizontalCenter
        font.italic: false
        font.bold: false
        textFormat: Text.AutoText
        wrapMode: Text.NoWrap
        font.pixelSize: 42
    }

    Slider {
        id: vBrightnessSlider
        y: 235
        height: 40
        anchors.right: parent.right
        anchors.rightMargin: 22
        anchors.left: parent.left
        anchors.leftMargin: 135
        font.pointSize: 13
        font.bold: false
        font.family: "Courier"
        font.weight: Font.Normal
        font.wordSpacing: 0
        from: 0
        to: 100
        value: 50
        property int sliderIndicator: 0

        onValueChanged: {

            groProController.sendMessage(sliderIndicator, value)
        }

    }

    Slider {
        id: uvBrightnessSlider
        y: 295
        height: 40
        anchors.right: parent.right
        anchors.rightMargin: 22
        anchors.left: parent.left
        anchors.leftMargin: 135
        from: 0
        to: 100
        value: 50

        property int sliderIndicator: 1

        onValueChanged: {

            groProController.sendMessage(sliderIndicator, value)
        }
    }

    Slider {
        id: irBrightnessSlider
        y: 356
        height: 40
        anchors.right: parent.right
        anchors.rightMargin: 22
        anchors.left: parent.left
        anchors.leftMargin: 135
        from: 0
        to: 100
        value: 50

        property int sliderIndicator: 2

        onValueChanged: {

            groProController.sendMessage(sliderIndicator, value)
        }
    }

    Button {
        id: connectButton
        x: 43
        y: 143
        width: 109
        height: 40
        text: "Connect"
        highlighted: false
        font.pointSize: 18

        onClicked: {
            groProController.test()
            groProController.connectToDevice(textFieldIp.text)
            groProController.sendMessage(height, textFieldIp.text)

        }

    }

    Button {
        id: disconnectButton
        x: 215
        y: 143
        width: 108
        height: 40
        text: qsTr("Disconnect")
        font.pointSize: 18

        onClicked: {
            groProController.test()
            groProController.disconnectFromDevice()

        }
    }

    TextField {
        id: textFieldIp
        x: 43
        y: 90
        width: 280
        height: 40
        text: "192.168.1.97"
        placeholderText: "I.P Address"

    }

    Button {
        id: warmButton
        x: 130
        y: 412
        text: qsTr("Warm Light")
        anchors.horizontalCenterOffset: 57
        anchors.horizontalCenter: parent.horizontalCenter
        wheelEnabled: false
        highlighted: false
        property int warmButtonIndicator: 3

        onClicked: {
            groProController.sendMessage(warmButtonIndicator, "1")
        }
    }

    Button {
        id: coldButton
        x: 130
        y: 476
        text: qsTr("Cold Light")
        anchors.horizontalCenterOffset: 57
        anchors.horizontalCenter: parent.horizontalCenter
        wheelEnabled: false
        highlighted: false

        property int coldButtonIndicator: 4

        onClicked: {
            groProController.sendMessage(coldButtonIndicator, "1")
        }
    }

    Button {
        id: whiteButton
        x: 130
        y: 542
        width: 100
        height: 40
        text: qsTr("White Light")
        anchors.horizontalCenterOffset: 57
        anchors.horizontalCenter: parent.horizontalCenter
        wheelEnabled: false
        highlighted: false

        property int whiteButtonIndicator: 5

        onClicked: {
            groProController.sendMessage(whiteButtonIndicator, "1")
        }
    }

    Text {
        id: visibleText
        x: 25
        y: 245
        width: 105
        height: 21
        color: "#ffffff"
        text: qsTr("Visible Light")
        horizontalAlignment: Text.AlignLeft
        wrapMode: Text.WordWrap
        font.italic: false
        font.bold: true
        font.pixelSize: 16
    }

    Text {
        id: uvText
        x: 25
        y: 306
        width: 86
        height: 19
        color: "#7212ce"
        text: qsTr("UV Light")
        font.bold: true
        font.italic: false
        font.pixelSize: 16
    }

    Text {
        id: irText
        x: 25
        y: 367
        width: 86
        height: 19
        color: "#ae2121"
        text: qsTr("IR Light")
        font.bold: true
        font.italic: false
        font.pixelSize: 16
    }

    Text {
        id: brightnessLevelText
        x: 150
        y: 206
        width: 173
        height: 21
        color: "#ffffff"
        text: qsTr("Brightness Level")
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
        font.italic: false
        font.pixelSize: 18
        wrapMode: Text.WordWrap
    }

//    MessageDialog {
//        id: messageDialog
//        title: "May I have your attention please"
//        text: "It's so cool that you are using Qt Quick."
//        onAccepted: {
//            console.log("And of course you could only agree.")
//            Qt.quit()
//        }
//        Component.onCompleted: visible = true

//    }

}
