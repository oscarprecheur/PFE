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

    function color_HA(valeurActu,seuilMax,seuilMin)
    {
        if(valeurActu<seuilMax && valeurActu>seuilMin)
        {
            eau.color="#03738C"
            ciel.color="#f29d52"

        }
        else
        {
            eau.color="#591902"
            ciel.color="#f23005"

        }
    }


}





