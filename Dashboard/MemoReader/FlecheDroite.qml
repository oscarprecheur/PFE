import QtQuick 2.0

Rectangle {
    id:tendance_area
    anchors
    {
        right:parent.right
        verticalCenter:parent.verticalCenter
        rightMargin:parent.width/10
        verticalCenterOffset:-parent.height/10
    }
    height:parent.height/10
    border.color: "#00000000"
    color: "#00000000"
    width:parent.width/10

    Image {
        id: id_Tendance_Droite

        height:parent.height

        source: "Visu/Tendance/Droite.svg"
        fillMode: Image.PreserveAspectFit
    }


    function tendance(valTendance)
    {

        if (valTendance===2)
        {

            tendance_area.visible=true
        }
        else
        {

            tendance_area.visible=false
        }
    }
}


