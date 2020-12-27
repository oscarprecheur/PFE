import QtQuick 2.0

Rectangle {

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

    Rectangle
    {
       id:id_Tendance_Gauche_Area

       clip:false
       border.color: "#00000000"
       color: "#00000000"

       height:parent.height
       width:parent.width
    Image {
        id: id_Tendance_Gauche

        height:parent.height

        source: "Visu/Tendance/Gauche.svg"
        fillMode: Image.PreserveAspectFit
    }
    }

    function tendance(valTendance)
    {

        if (valTendance===0)
        {

            id_Tendance_Gauche_Area.visible=true
        }
        else
        {

            id_Tendance_Gauche_Area.visible=false
        }
    }



}
