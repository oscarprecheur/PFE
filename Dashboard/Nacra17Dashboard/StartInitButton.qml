import QtQuick.Controls 2.15
import QtQuick 2.0

Button
{
        id: button

        text: "START"
        background: Rectangle {
            implicitWidth: 100
            implicitHeight: 100
            color: button.down ? "#B7282A" : "#E85454"
            border.color: "#00000000"
            border.width: 1
            radius: 1000
        }
}
