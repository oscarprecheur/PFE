import QtQuick 2.0

    //Ce composant permet l'affichage ou nom d'une image svg representant une flêche de tendance (vers le haut)

Rectangle
{

    id:tendance_area //aire contenant l'image celle ci peut etre visibile ou non

    visible: false //à l'ouverture les fleche ne sont pas visibles

    anchors
    {
        horizontalCenter:parent.horizontalCenter
        verticalCenter:parent.verticalCenter//allignement au centre vertical

    }

    //prend la taille du parent/10
    width:parent.width/10
    height:parent.height/10

    //Rectangle transparent
    border.color: "#00000000"
    color: "#00000000"


    Image
    {
        //Image .svg de la flèche droite
        id: id_Tendance_Droite

        source: "Visu/Tendance/Up.svg"

        fillMode: Image.PreserveAspectFit// preserve les dimension de l'image


        height:parent.height // hauteur = haute du parent (largeur adaptée en conséquence)
    }


    function tendance(valTendance) // Cette fonctino permet de determiner si la fleche s'affiche ou non en focntion de la valeur paramètre valTendance
    {

        if (valTendance===2)//monte
        {

            tendance_area.visible=true
        }
        else
        {

            tendance_area.visible=false
        }
    }
}
