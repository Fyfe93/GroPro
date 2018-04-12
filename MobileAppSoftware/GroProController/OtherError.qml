import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Dialogs 1.1


Item {
    width: 360
    height: 640

    MessageDialog {
        id: messageDialog
        title: "Error"
        text: "There's been an error, try restarting"
        visible: false
        onAccepted: {
            Qt.quit()
        }
        Component.onCompleted: visible = true

    }

}
