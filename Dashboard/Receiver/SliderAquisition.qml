import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Controls.Styles 1.4

Slider
{

    implicitWidth: parent.width/1.5

    value:0
    from:0
    to:100
    stepSize: 25
    snapMode: "SnapAlways"
}
