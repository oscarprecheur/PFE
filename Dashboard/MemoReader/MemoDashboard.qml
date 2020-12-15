import QtQuick 2.7
import QtQuick.Controls 1.0
import READ.FILE 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0








ApplicationWindow
{
    id: id_MemoDashboard

    visible:false

    READFILE
    {
        id:file
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
            id_MemoDashboard.visible=true


        }
        onRejected: {
            console.log("Canceled")
        }
        Component.onCompleted: visible = true
    }

    Rectangle
    {
        id:id_rectangle_test
        width: 1080
        height: 720
        visible: true
        color:"blue"
    }



}
