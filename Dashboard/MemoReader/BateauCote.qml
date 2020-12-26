import QtQuick 2.0

Image {
    clip: true

    source: "Visu/Tangage/pfe_bateau_cote.svg"
    fillMode: Image.PreserveAspectFit
    height:parent.height/1.5

    anchors
    {
        horizontalCenter:parent.horizontalCenter
        verticalCenter:parent.verticalCenter
    }
}
