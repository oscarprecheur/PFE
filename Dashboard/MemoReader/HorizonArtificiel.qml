import QtQuick 2.7
import QtQuick.Controls 1.0
import READ.FILE 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0

Rectangle
{
    width:  parent.width
    height: parent.height
    color: "#00000000"

    Rectangle
    {
        id: eau
        x: 0
        y: ciel.height
        color: "black"

        width: parent.width
        height: parent.height/2
    }

    Rectangle
    {
        id: ciel
        x: 0
        y: 0
        width: parent.width
        height: parent.height/2
    }


    Timer//TIMER TANGAGE
        {
            id:timertangage
            interval:1; running:true;repeat: true // on rafraichi l'écran toutes les 0,01 secondes
            onTriggered:
            {

                //mouvmeent de l'horizon artificiel
                id_horizon_area.y=-((id_horizon_area.height-parent.height)/2)-(file.getValTangageVal*(id_interface_area.height/270))//translation -> tangage

            }

        }
    Timer//TIMER GITE
        {
            id:timergite
            interval:1; running:true;repeat: true // on rafraichi l'écran toutes les 0,01 secondes
            onTriggered:
            {

                //mouvmeent de l'horizon artificiel
                id_horizon_area.rotation=file.getValGiteVal //rotation -> gite

            }

        }
}





