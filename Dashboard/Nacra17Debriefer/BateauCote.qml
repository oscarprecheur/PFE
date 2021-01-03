import QtQuick 2.0

    //ce composant est une image svg representant un bateau vu de coté

Image {

    clip: true //image visible

    source: "Visu/Tangage/pfe_bateau_cote.svg" //chemin d'accés à l'image
    fillMode: Image.PreserveAspectFit // l'image preserve ses dimensions
    height:parent.height/1.5// la hauteur de l'image (adaptation de la largeur en conséquence) = auteur du parent/1.5

    anchors //ancrage au centre du parent
    {
        horizontalCenter:parent.horizontalCenter
        verticalCenter:parent.verticalCenter
    }
}
