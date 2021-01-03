import QtQuick 2.0
import QtQuick.Controls 2.15

Button {
        id: button
        text: "+"
        height:width
        background: Rectangle
        {
            color: button.down ? "#B7282A" : "#03738C"
            border.color: "#00000000"
            border.width: 1
            radius: 1000
        }
        contentItem: Text
        {
            text: button.text
            color: "white"

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
}
