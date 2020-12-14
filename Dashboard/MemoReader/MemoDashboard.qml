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

        width:  1080/2
        height: 1080/2
        color: "blue"

        Text {
            id: id_text
            x: 0
            y: 0
            width: 782
            height: 504
            text: "cul"
            font.pointSize: 27
            minimumPixelSize: 23
        }



}
    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
            id_text.text = fileDialog.fileUrls.toString()
        }
        onRejected: {
            console.log("Canceled")
        }
        Component.onCompleted: visible = true
    }


}




