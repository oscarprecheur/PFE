import QtQuick 2.0

Item
{
    id: id_repere_vert

    anchors
    {
        horizontalCenter: parent.horizontalCenter
        verticalCenter: parent.verticalCenter
    }
    width:  parent.width
    height: parent.height


    Image
    {
        id: id_repere_vert_image

        anchors.fill:parent
        clip: true

        source: "Visu/Repere/RepereVert.svg"
        fillMode: Image.PreserveAspectFit
    }

}
