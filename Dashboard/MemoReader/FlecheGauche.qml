import QtQuick 2.0

//commentaire indicatifs : voir FlecheDroite.qml

Rectangle
{

    id: tendance_area

    visible: false

    anchors
    {
        left:parent.left
        verticalCenter:parent.verticalCenter
        leftMargin:parent.width/10
        verticalCenterOffset:-parent.height/10
    }

    width:parent.width/10
    height:parent.height/10

    border.color: "#00000000"
    color: "#00000000"


    Image {
        id: id_Tendance_Gauche

        height:parent.height

        source: "Visu/Tendance/Gauche.svg"
        fillMode: Image.PreserveAspectFit
    }

    function tendance(valTendance)
    {

        if (valTendance===0)//le bateau penche vers la gauche
        {

            tendance_area.visible=true
        }
        else
        {

            tendance_area.visible=false
        }
    }



}
