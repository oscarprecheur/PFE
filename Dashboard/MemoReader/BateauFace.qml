import QtQuick 2.0

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
