import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Controls.Styles 1.4

//ce composant represente la ligne de temps, c'est en réalité un slider dont les valerus vont influer sur les lignes lues du fichier et donc du temps

Slider
{



    anchors//ancrage au centre
    {
        horizontalCenter:parent.horizontalCenter
        verticalCenter:parent.verticalCenter

    }

    from:0 //début initial à 0
    value:0// valeur de départ

    stepSize: 1 // intervale initial à 1
    snapMode: "SnapAlways" //vision de tout les crans du slider
}
