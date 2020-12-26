import QtQuick 2.7
import QtQuick.Controls 1.0
import READ.FILE 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0

Rectangle
{
    width:  parent.width
    height: parent.height
    color: "#00000000"

    Rectangle
    {
        id: eau
        x: 0
        y: ciel.height
        color: "blue"

        width: parent.width
        height: parent.height/2
    }

    Rectangle
    {
        id: ciel
        x: 0
        y: 0

        color: "sky blue"
        width: parent.width
        height: parent.height/2
    }
}





