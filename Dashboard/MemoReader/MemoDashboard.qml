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

    READFILE
    {
        id:file
    }

    FileDialog {
        id: fileDialog
        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
            id_MemoDashboard.visible=true

            file.setFileUrl(fileDialog.fileUrls.toString())
            console.log(file.getNbDataLine)
            id_timeline.to=file.getNbDataLine
            intervalTimer=file.getValMemoTempo


        }
        onRejected: {
            console.log("Canceled")
        }
        Component.onCompleted: visible = true
    }

    Rectangle
    {
        id:id_timeline_area
        width: parent.width
        height: parent.height


        Timeline
        {
            id:id_timeline

            onMoved:
            {
                file.readFileLineData(value)
            }
        }
    }


    PlayPauseButton
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

    Timer
    {
      id:id_timer
      interval:intervalTimer ; running:false;repeat: true // on rafraichi l'écran toutes les 0,01 secondes
      onTriggered:
      {
           id_timeline.increase()
      }
    }





}
