import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Dialogs 1.1


Item {
    width: 360
    height: 640

    MessageDialog {
        id: messageDialog
        title: "ConnectionRefusedError"
        text: "The connection was refused by the peer. Make sure the fortune server is running, and check that the host name and port settings are correct."
        visible: false
        onAccepted: {
            Qt.quit()
        }
        Component.onCompleted: visible = true

    }

}
