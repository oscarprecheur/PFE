import QtQuick 2.7
import QtQuick.Controls 1.0
import VAL.CAPT 1.0
import QtQuick.Layouts 1.0

ApplicationWindow
{
    id: id_init

    //background
    Rectangle
    {
        id: id_background
        x: 0
        y: 0
        width: parent.width
        height: parent.height
        color:"#f29d52"
    }


    StartInitButton
    {
        id:id_start_button

        anchors
        {
            left:parent.left
            bottom:parent.bottom

            leftMargin:parent.width/20
            bottomMargin:parent.height/20

        }

        onClicked: {

            var component =Qt.createComponent("qrc:/openDashboard.qml")
            win = component.createObject(id_init)
            ApplicationWindow.close()
        }

    }



}
