import QtQuick 2.0

//Ce composant est une iamge svg represantant un bateau vu de Face
//Commentaires explicatifs : voir BateauCote.qml

Image {


    id: id_bateau_face
    clip: true

    source: "Visu/Gite/pfe_bateau_face.svg"
    fillMode: Image.PreserveAspectFit
    height:parent.height/1.5

    anchors
    {
        horizontalCenter:parent.horizontalCenter
        verticalCenter:parent.verticalCenter
    }
}
