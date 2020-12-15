import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Controls.Styles 1.4

Slider
{

    implicitWidth: parent.width/1.5
    anchors
    {
        horizontalCenter:parent.horizontalCenter
        bottom:parent.bottom
        bottomMargin:parent.height/10

    }

    from:0
    value:0
    to:100
    stepSize: 25
    snapMode: "SnapAlways"
}
