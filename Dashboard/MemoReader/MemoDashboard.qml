import QtQuick 2.7
import QtQuick.Controls 1.0

import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0







ApplicationWindow
{
    id: id_dashboard

    //<<<<<<<<<<<<<<<<<<<<<<<DESCRIPTION STATIQUE>>>>>>>>>>>>>>>>>>>>>>>>>>

    //-----------HORIZON ARTIFICIEL------------------
    width:  1080
    height: 1080
    visible: true
    Rectangle//zone horizon artificiel
    {
        id: id_horizon_area
        y: -(id_horizon_area.height-parent.height)/2
        x: -(id_horizon_area.width-parent.width)/2

        width:  1080*4
        height: 1080*4
        color: "blue"



}
    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
        }
        onRejected: {
            console.log("Canceled")
        }
        Component.onCompleted: visible = true
    }


}




