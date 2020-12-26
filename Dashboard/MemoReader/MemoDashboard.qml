import QtQuick 2.7
import QtQuick.Controls 1.0
import READ.FILE 1.0
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0








ApplicationWindow
{
    id: id_MemoDashboard

    visible:false
    width: 1080
    height: 720

    property real intervalTimer: 1
    property real sizeDataFile :1




    READFILE
    {
        id:file
    }

    FileDialog //BOITE DE DIALOGUE CHOIX FICHIER
    {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
            id_MemoDashboard.visible=true

            file.setFileUrl(fileDialog.fileUrls.toString())
            file.loadAllFile()
            file.initReading()
            sizeDataFile=file.getNbDataLine
            console.log(sizeDataFile)
            id_timeline.to=file.sizeDataFile-1
            intervalTimer=file.getValMemoTempo



        }
        onRejected: {
            console.log("Canceled")
        }
        Component.onCompleted: visible = true
    }

    Rectangle{ // PARTIE COMMANDE------------------------------------------------------------------------------------------------

        id:id_command_area
        width: parent.width
        height: parent.height
        border.color: "#00000000"
        color: "#00000000"



        Rectangle //TIMELINE
        {
            id:id_timeline_area
            width: id_timeline.width
            height: id_timeline.height

            anchors
            {
                horizontalCenter:parent.horizontalCenter
                bottom:parent.bottom
                bottomMargin:parent.height/10

            }
            border.color: "#00000000"
            color: "#00000000"


            Timeline
            {
                id:id_timeline

                implicitWidth: id_MemoDashboard.width/1.5
                to :file.getNbDataLine-1

                onMoved:
                {
                    file.readFileLineData(value)
                    id_time_display.text=file.getValTime.toFixed(2)
                }
            }
        }


        PlayPauseButton // BOUTON DEBUT/FIN ENTRAINEMENT
        {
            id:id_play_pause_button
            anchors
            {
                left: parent.left
                bottom: parent.bottom
                leftMargin: parent.width/20
                bottomMargin: parent.height/10
            }
            text: "Play"

            onClicked:
            {
                if (id_timer.running==false)
                {

                    id_timer.running=true
                }
                else
                {
                    id_timer.running=false
                }

            }
        }

        Rectangle // AFFICHAGE TEMPS
        {
            id: id_time_display_area
            anchors
            {
                verticalCenter:id_timeline_area.verticalCenter
                left:id_timeline_area.right
                leftMargin: parent.width/30
            }

            width:  id_time_display.paintedWidth
            height: id_time_display.paintedHeight
            border.color: "#00000000"
            color: "#00000000"

            DigitTime
            {
                id: id_time_display
                horizontalAlignment: Text.AlignHCenter

                anchors
                {
                    horizontalCenter: parent.horizontalCenter
                    verticalCenter: parent.verticalCenter

                }
                font.pixelSize: id_MemoDashboard.height/30

            }

        }

        Timer
        {
            id:id_timer
            interval:intervalTimer ; running:false;repeat: true // on rafraichi l'écran toutes les 0,01 secondes
            onTriggered:
            {


                id_timeline.increase()
                file.readFileLineData(id_timeline.value)
                id_time_display.text=file.getValTime.toFixed(2)
                console.log(id_timeline.value)

                if(id_timeline.value==sizeDataFile-1)
                    id_timer.running=false

            }
        }

    }

    Rectangle{ // PARTIE  VISUALISATION------------------------------------------------------------------------------------------------

        id:id_interface_area
        width: parent.width
        height: parent.height
        border.color: "#00000000"
        color: "#00000000"
    }





}
