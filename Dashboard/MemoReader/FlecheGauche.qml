import QtQuick 2.0

Item {

    anchors
    {
        horizontalCenter: parent.horizontalCenter
        verticalCenter: parent.verticalCenter
    }

    Image {
        id: id_Tendance_Gauche
        //clip: true

        source: "Visu/Tendance/Left.svg"
        fillMode: Image.PreserveAspectFit
    }

    function tendance(valTendance)
    {
        if (valTendance===2)
        {
            id_Tendance_Gauche.visible=true
        }
        else
        {
            id_Tendance_Gauche.visible=false
        }
    }



}
