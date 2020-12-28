import QtQuick 2.0

Rectangle {

    id: tendance_area
    anchors
    {
        left:parent.left
        verticalCenter:parent.verticalCenter
        leftMargin:parent.width/10
        verticalCenterOffset:-parent.height/10
    }
    height:parent.height/10
    border.color: "#00000000"
    color: "#00000000"
    width:parent.width/10

    Image {
        id: id_Tendance_Gauche

        height:parent.height

        source: "Visu/Tendance/Gauche.svg"
        fillMode: Image.PreserveAspectFit
    }

    function tendance(valTendance)
    {

        if (valTendance===0)
        {

            tendance_area.visible=true
        }
        else
        {

            tendance_area.visible=false
        }
    }



}
