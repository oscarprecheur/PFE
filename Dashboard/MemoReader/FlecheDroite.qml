import QtQuick 2.0

Rectangle {

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

    Rectangle
    {
       id:id_Tendance_Droite_Area

       clip:false
       border.color: "#00000000"
       color: "#00000000"

       height:parent.height
       width:parent.width
    Image {
        id: id_Tendance_Droite

        height:parent.height

        source: "Visu/Tendance/Droite.svg"
        fillMode: Image.PreserveAspectFit
    }
    }

    function tendance(valTendance)
    {

        if (valTendance===2)
        {

            id_Tendance_Droite_Area.visible=true
        }
        else
        {

            id_Tendance_Droite_Area.visible=false
        }
    }

}
