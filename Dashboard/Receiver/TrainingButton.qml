import QtQuick 2.0
import QtQuick.Controls 2.15

Button {
        id: button


        background: Rectangle {
            implicitWidth: 100
            implicitHeight: 100
            color: if(valeur.getOnTraining==false) {button.down ? "#B7282A" : "#E85454"} else {button.down ? "blue" : "green"}
            border.color: "#00000000"
            border.width: 1
            radius: 1000
        }
}
