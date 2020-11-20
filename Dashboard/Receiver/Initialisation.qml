import QtQuick 2.7
import QtQuick.Controls 1.0
import VAL.CAPT 1.0
import QtQuick.Layouts 1.0

ApplicationWindow
{
    id: id_init

     property var timeAquisition
     property var timeMemo



    VALCAPT//appel de valcapt directement dans le programme qml sous le nom de "valeur"
    {
        id:valeur
    }

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

        onClicked:
        {
            var component =Qt.createComponent("qrc:/openDashboard.qml")
            win = component.createObject(id_init)

        }



     }

    Rectangle
    {
        id: init_aquisition_area

        anchors
        {
            left:parent.left
            top:parent.top
        }
        width:parent.width
        height: id_text_aquisition.paintedHeight+slider_aquisition.height
        color: "#00000000"

        Text//moy 500M
        {
            id: id_text_aquisition

            //horizontalAlignment: Text.AlignHCenter
            anchors
            {
                top: parent.top
                left: parent.left
                leftMargin: parent.width/10
            }
            text: qsTr("Temps d'aquisition des données:")
            font.pixelSize: parent.height/2
        }

        SliderAquisition
        {
            id: slider_aquisition
            anchors
            {
                top: id_text_aquisition.bottom
                topMargin:parent.height
                left: parent.left
                leftMargin: parent.width/20
            }
        }

        Text//moy 500M
        {
            id: id_text_val_aquisition

            //horizontalAlignment: Text.AlignHCenter
            anchors
            {

                left: slider_aquisition.right
                verticalCenter:slider_aquisition.vaerticalCenter
            }
            text: qsTr("--.--")
            font.pixelSize: parent.height/2
        }
    }


    Rectangle
    {
        id: init_memo_area

        anchors
        {
            left:parent.left
            top:init_aquisition_area.bottom
            topMargin:parent.height/5
        }
        width:parent.width
        height: id_text_memo.paintedHeight+slider_memo.height
        color: "#00000000"

        Text//moy 500M
        {
            id: id_text_memo

            //horizontalAlignment: Text.AlignHCenter
            anchors
            {
                top: parent.top
                left: parent.left
                leftMargin: parent.width/10
            }
            text: qsTr("Temps d'aquisition des données:")
            font.pixelSize: parent.height/2
        }

        SliderMemo
        {
            id: slider_memo
            anchors
            {
                top: id_text_memo.bottom
                topMargin:parent.height
                left: parent.left
                leftMargin: parent.width/20
            }
        }

        Text//moy 500M
        {
            id: id_text_val_memo

            //horizontalAlignment: Text.AlignHCenter
            anchors
            {

                left: slider_memo.right
                verticalCenter:slider_memo.vaerticalCenter
            }
            text: qsTr("--.--")
            font.pixelSize: parent.height/2
        }
    }




//FONCTIONNMENT DYNAMIQUE

    Timer//Aquisition
        {
            id:timeraquisition
            interval:1; running:true;repeat: true // on rafraichi l'écran toutes les 0,01 secondes
            onTriggered:
            {
                switch(slider_aquisition.value)
                {
                case 0:
                    id_text_val_aquisition.text="1 ms"
                    timeAquisition=1
                    break
                case 25:
                    id_text_val_aquisition.text="10 ms"
                    timeAquisition=10
                    break
                case 50:
                    id_text_val_aquisition.text="100 ms"
                    timeAquisition=100
                    break
                case 75:
                    id_text_val_aquisition.text="1000 ms"
                    timeAquisition=1000
                    break
                default:
                    id_text_val_aquisition.text="10000 ms"
                    timeAquisition=10000
                    break


                }
            }
        }

    Timer//Memo
        {
            id:timermemo
            interval:1; running:true;repeat: true // on rafraichi l'écran toutes les 0,01 secondes
            onTriggered:
            {
                switch(slider_memo.value)
                {
                case 0:
                    id_text_val_memo.text="1 ms"
                    timeMemo=1
                    break
                case 25:
                    id_text_val_memo.text="10 ms"
                    timeMemo=10
                    break
                case 50:
                    id_text_val_memo.text="100 ms"
                    timeMemo=100
                    break
                case 75:
                    id_text_val_memo.text="1000 ms"
                    timeMemo=1000
                    break
                default:
                    id_text_val_memo.text="10000 ms"
                    timeMemo=10000
                    break


                }
            }
        }
}
