import QtQuick 2.0

Item {

    anchors
    {
        horizontalCenter: parent.horizontalCenter
        verticalCenter: parent.verticalCenter
    }

    Image {
        id: id_Tendance_Droite
        //clip: true

        source: "Visu/Tendance/Right.svg"
        fillMode: Image.PreserveAspectFit
    }

    function tendance(valTendance)
    {
        if (valTendance===0)
        {
            id_Tendance_Droite.visible=true
        }
        else
        {
            id_Tendance_Droite.visible=false
        }
    }



}
