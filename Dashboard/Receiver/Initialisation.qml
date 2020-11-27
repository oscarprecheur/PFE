import QtQuick 2.7
import QtQuick.Controls 1.0
import VAL.CAPT 1.0
import QtQuick.Layouts 1.0

ApplicationWindow
{
    id: id_init



    property real timeAquisition:slider_aquisition.value
    property real timeMemo:slider_memo.value
    property real giteMin:slider_gite_min.value
    property real giteMax:slider_gite_max.value
    property real tangageMin:slider_tangage_min.value
    property real tangageMax:slider_tangage_max.value
    property bool test



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

    //------------------------------------BOUTON START/STOP--------------------------------------
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
            if (test==true)
            {
                var component =Qt.createComponent("qrc:/openDashboard.qml")
                component.createObject(id_start_init)
                //init
                valeur.initValGiteMax(giteMax)
                valeur.initValGiteMin(giteMin)
                valeur.initValTangageMax(tangageMax)
                valeur.initValTangageMin(tangageMin)
                valeur.initDeltaTMemo(timeMemo)
                valeur.initDeltaTAquisition(timeAquisition)
                valeur.init()

            }


        }





    }
    //----------------------------------------AQUISITION----------------------------------------
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
                //topMargin:parent.height
                left: parent.left
                leftMargin: parent.width/20
            }
        }

        Text
        {
            id: id_text_val_aquisition


            anchors
            {

                left: slider_aquisition.right
                verticalCenter:slider_aquisition.vaerticalCenter
            }
            text: qsTr("--.--")
            font.pixelSize: parent.height/2
        }
    }

    //---------------------------------------------MEMO------------------------------------------
    Rectangle
    {
        id: init_memo_area

        anchors
        {
            left:parent.left
            top:init_aquisition_area.bottom
            //topMargin:parent.height/5
        }
        width:parent.width
        height: id_text_memo.paintedHeight+slider_memo.height
        color: "#00000000"

        Text
        {
            id: id_text_memo

            //horizontalAlignment: Text.AlignHCenter
            anchors
            {
                top: parent.top
                left: parent.left
                leftMargin: parent.width/10
            }
            text: qsTr("Temps de mémorisation des données:")
            font.pixelSize: parent.height/2
        }

        SliderMemo
        {
            id: slider_memo
            anchors
            {
                top: id_text_memo.bottom
                //topMargin:parent.height
                left: parent.left
                leftMargin: parent.width/20
            }
        }

        Text
        {
            id: id_text_val_memo


            anchors
            {

                left: slider_memo.right
                verticalCenter:slider_memo.vaerticalCenter
            }
            text: qsTr("--.--")
            font.pixelSize: parent.height/2
        }
    }

    //-------------------------Slider GIte Min------------------------------------------

    Rectangle
    {
        id: seuil_gite_min_area

        anchors
        {
            left:parent.left
            top:seuil_gite_max_area.bottom
            //topMargin:parent.height/10
        }
        width:parent.width
        height: id_text_gite_min.paintedHeight+slider_gite_min.height
        color: "#00000000"

        Text
        {
            id: id_text_gite_min

            //horizontalAlignment: Text.AlignHCenter
            anchors
            {
                top: parent.top
                left: parent.left
                leftMargin: parent.width/10
            }
            text: qsTr("Seuil gite min:")
            font.pixelSize: parent.height/2
        }

        SliderSeuils
        {
            id: slider_gite_min
            anchors
            {
                top: id_text_gite_min.bottom
                //topMargin:parent.height
                left: parent.left
                leftMargin: parent.width/20
            }
            onValueChanged:
            {
                giteMin=value

            }

        }

        Text
        {
            id: id_text_val_gite_min


            anchors
            {

                left: slider_gite_min.right
                verticalCenter:slider_gite_min.vaerticalCenter
            }
            text: qsTr("--.--")
            font.pixelSize: parent.height/2
        }
    }

    //----------------------------------SEUIL GITE MAX---------------------------------


    Rectangle
    {
        id: seuil_gite_max_area

        anchors
        {
            left:parent.left
            top:init_memo_area.bottom
            topMargin:parent.height/10
        }
        width:parent.width
        height: id_text_gite_max.paintedHeight+slider_gite_max.height
        color: "#00000000"

        Text
        {
            id: id_text_gite_max

            //horizontalAlignment: Text.AlignHCenter
            anchors
            {
                top: parent.top
                left: parent.left
                leftMargin: parent.width/10
            }
            text: qsTr("Seuil gite max:")
            font.pixelSize: parent.height/2
        }

        SliderSeuils
        {
            id: slider_gite_max
            anchors
            {
                top: id_text_gite_max.bottom
                //topMargin:parent.height
                left: parent.left
                leftMargin: parent.width/20
            }
            onValueChanged:
            {
                giteMax=value

            }
        }

        Text
        {
            id: id_text_val_gite_max


            anchors
            {

                left: slider_gite_max.right
                verticalCenter:slider_gite_max.vaerticalCenter
            }
            text: qsTr("--.--")
            font.pixelSize: parent.height/2
        }
    }

    //-------------------------Slider tangage Min------------------------------------------

    Rectangle
    {
        id: seuil_tangage_min_area

        anchors
        {
            left:parent.left
            top:seuil_tangage_max_area.bottom
            //topMargin:parent.height/10
        }
        width:parent.width
        height: id_text_tangage_min.paintedHeight+slider_tangage_min.height
        color: "#00000000"

        Text
        {
            id: id_text_tangage_min

            //horizontalAlignment: Text.AlignHCenter
            anchors
            {
                top: parent.top
                left: parent.left
                leftMargin: parent.width/10
            }
            text: qsTr("Seuil tangage min:")
            font.pixelSize: parent.height/2
        }

        SliderSeuils
        {
            id: slider_tangage_min
            anchors
            {
                top: id_text_tangage_min.bottom
                //topMargin:parent.height
                left: parent.left
                leftMargin: parent.width/20
            }
            onValueChanged:
            {
                tangageMin=value

            }

        }

        Text
        {
            id: id_text_val_tangage_min


            anchors
            {

                left: slider_tangage_min.right
                verticalCenter:slider_tangage_min.vaerticalCenter
            }
            text: qsTr("--.--")
            font.pixelSize: parent.height/2
        }
    }

    //----------------------------------SEUIL tangage MAX---------------------------------


    Rectangle
    {
        id: seuil_tangage_max_area

        anchors
        {
            left:parent.left
            top:seuil_gite_min_area.bottom
            topMargin:parent.height/10
        }
        width:parent.width
        height: id_text_tangage_max.paintedHeight+slider_tangage_max.height
        color: "#00000000"

        Text
        {
            id: id_text_tangage_max

            //horizontalAlignment: Text.AlignHCenter
            anchors
            {
                top: parent.top
                left: parent.left
                leftMargin: parent.width/10
            }
            text: qsTr("Seuil tangage max:")
            font.pixelSize: parent.height/2
        }

        SliderSeuils
        {
            id: slider_tangage_max
            anchors
            {
                top: id_text_tangage_max.bottom
                //topMargin:parent.height
                left: parent.left
                leftMargin: parent.width/20
            }
            onValueChanged:
            {
                tangageMax=value

            }
        }

        Text
        {
            id: id_text_val_tangage_max


            anchors
            {

                left: slider_tangage_max.right
                verticalCenter:slider_tangage_max.vaerticalCenter
            }
            text: qsTr("--.--")
            font.pixelSize: parent.height/2
        }
    }


    //FONCTIONNMENT DYNAMIQUE///////////////////////////////////////////////////////////////////////////////////////////////////////

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

    Timer//Seuils
    {
        id:timerseuil
        interval:1; running:true;repeat: true // on rafraichi l'écran toutes les 0,01 secondes
        onTriggered:
        {
            id_text_val_gite_max.text=giteMax.toFixed(3)+"°"
            id_text_val_gite_min.text=giteMin.toFixed(3)+"°"

            id_text_val_tangage_max.text=tangageMax.toFixed(3)+"°"
            id_text_val_tangage_min.text=tangageMin.toFixed(3)+"°"

            if (giteMax<giteMin)
            {
                id_text_val_gite_max.color="#e95454"
                id_text_val_gite_min.color="#e95454"
            }
            else
            {
                id_text_val_gite_max.color="black"
                id_text_val_gite_min.color="black"
            }

            if (tangageMax<tangageMin)
            {
                id_text_val_tangage_max.color="#e95454"
                id_text_val_tangage_min.color="#e95454"
            }
            else
            {
                id_text_val_tangage_max.color="black"
                id_text_val_tangage_min.color="black"
            }

            if (tangageMax<tangageMin || giteMax<giteMin)
                test=false
            else
                test=true

        }
    }


}
