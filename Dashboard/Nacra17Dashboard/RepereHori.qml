import QtQuick 2.0

Item {
    id: id_repere_hori

    anchors
    {
        horizontalCenter: parent.horizontalCenter
        verticalCenter: parent.verticalCenter
    }

    width:  parent.width
    height: parent.height

    Image {
        id: id_repere_hori_image

        anchors.fill:parent
        clip: true

        source: "Visu/Repere/RepereHori.svg"
        fillMode: Image.PreserveAspectFit
    }

}
