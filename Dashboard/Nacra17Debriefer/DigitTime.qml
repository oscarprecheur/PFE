import QtQuick 2.0

    //ce composant represente le texte d'affochage du temps de la timeline

Text
{

    id: id_digit_time

    //prend la taille du parent
    width: parent.width
    height: parent.height

    //couelur noire
    color: "#000000"

    //texte d'initialisation
    text: qsTr("---.---")

    //la police prend la taille du parent
    font.pixelSize: parent.height

    //texte alligné à gauche
    horizontalAlignment: Text.AlignLeft
}
