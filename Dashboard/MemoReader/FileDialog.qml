import QtQuick 2.7
import QtQuick.Controls 1.0
import READ.FILE 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0







ApplicationWindow
{
    id: id_dashboard

    READFILE
    {
        id:file
    }

    //<<<<<<<<<<<<<<<<<<<<<<<DESCRIPTION STATIQUE>>>>>>>>>>>>>>>>>>>>>>>>>>
    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
            file.setFileUrl(fileDialog.fileUrls.toString())
        }
        onRejected: {
            console.log("Canceled")
        }
        Component.onCompleted: visible = true
    }




}
