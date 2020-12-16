import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Controls.Styles 1.4

Slider
{



    anchors
    {
        horizontalCenter:parent.horizontalCenter
        verticalCenter:parent.verticalCenter

    }

    from:0
    value:0
    to:1
    stepSize: 1
    snapMode: "SnapAlways"
}
