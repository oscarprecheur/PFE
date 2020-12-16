import QtQuick 2.0
import QtQuick.Controls 2.15

Button {

        id: button
        background: Rectangle {
            implicitWidth: 100
            implicitHeight: 100
            color: {button.down ? "#31BA47" : "#E85454"}
            border.color: "#00000000"
            border.width: 1
            radius: 1000
        }
}
