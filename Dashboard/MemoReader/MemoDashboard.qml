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
    color:"#004B5D"

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
            id_timeline.to=sizeDataFile-1
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
        z:1


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


            Timeline //ligne de temps permet la mamnipulation du temps de l'entrainement
            {
                id:id_timeline

                implicitWidth: id_MemoDashboard.width/1.5 //largeur = largeur de id_MemoDashboard/1.5

                onValueChanged: // lorsque l'evenement onValueChanged est vrai ( la valeur de la timeline change)
                {
                    file.readFileLineData(id_timeline.value) //lecture de la ligne de données correspondant à la valeur de la timeline (en prenant en compte les premiere ligne du fichier)
                    id_time_display.text=file.getValTime.toFixed(2) //Affichage du temps correspondant à la ligne lue

                    id_bateau_face.rotation=file.getValGiteVal //acquisition de la valeur de gite -> rotation id_ateau_face
                    id_bateau_cote.rotation=file.getValTangageVal //acquisition de la valeur de tanagage -> rotation id_bateau_cote

                    id_HA_gite.color_HA(file.getValGiteVal,file.getValGiteSeuilMax,file.getValGiteSeuilMin) //appel de la fonction color_HA de id_HA_gite prend en paramètre la valeur du gite ainsi que le sdeux seuil
                    id_HA_tangage.color_HA(file.getValTangageVal,file.getValTangageSeuilMax,file.getValTangageSeuilMin) //appel de la fonction color_HA de id_HA_tangage prend en paramètre la valeur du tangage ainsi que le sdeux seuil

                    id_fleche_gite_gauche.tendance(file.getValGiteTend) //appel de la fonction tendance de id_fleche_gite_gauche prend en paramètre la valeur de la tendance du gite (0 1 ou 2)
                    id_fleche_gite_droite.tendance(file.getValGiteTend) //appel de la fonction tendance de id_fleche_gite_droite prend en paramètre la valeur de la tendance du gite (0 1 ou 2)

                    id_fleche_tangage_gauche.tendance(file.getValTangageTend) //appel de la fonction tendance de id_fleche_tangage_gauche prend en paramètre la valeur de la tendance du gite (0 1 ou 2)
                    id_fleche_tangage_droite.tendance(file.getValTangageTend) //appel de la fonction tendance de id_fleche_tangage_droite prend en paramètre la valeur de la tendance du gite (0 1 ou 2)

                    id_display_val_gite.affichageValeur(file.getValGiteVal,file.getValGiteSeuilMax,file.getValGiteSeuilMin) //appel de la fonction affichageValeur de id_display_val_gite prend en paramètre la valeur du gite ainsi que le sdeux seuil
                    id_display_val_tangage.affichageValeur(file.getValTangageVal,file.getValTangageSeuilMax,file.getValTangageSeuilMin) //appel de la fonction affichageValeur de id_display_val_tangage prend en paramètre la valeur du tangage ainsi que le sdeux seuil
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

        Timer //Creation d'un timer adapté à l'intervale de temps entre chaque donnée enregistrée
        {
            id:id_timer
            interval:intervalTimer ; running:false;repeat: true // on rafraichi l'écran toutes les 0,01 secondes
            onTriggered:
            {


                id_timeline.increase() //incrementation de la timeline à chaque coup d'horloge

                if(id_timeline.value==sizeDataFile-1)//arret automatique du timer à la fin de la timeline
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
        z:0

        Rectangle //CASE 1 : VISU GITE ---------------------------------
        {
            id: id_case1_area

            color: "#f29d52"

            height: parent.height/2
            width  : parent.height/2

            anchors
            {
                left:parent.left
                top:parent.top
            }

            HorizonArtificiel //Appel du composant horizon artificiel
            {
                id: id_HA_gite


                Text //affichage texte indication tribord
                {
                    id: id_text_tribord
                    visible: true
                    text: qsTr("TRI")
                    color: "green"
                    font
                    {
                        pixelSize:id_HA_tangage.height/10
                    }
                    anchors
                    {
                        top:parent.top
                        right:parent.right
                        rightMargin:parent.width/10
                    }
                }

                Text //affichage texte indication babord
                {
                    id: id_text_babord
                    visible: true
                    text: qsTr("BAB")
                    color: "red"
                    font
                    {
                        pixelSize:id_HA_tangage.height/10
                    }
                    anchors
                    {
                        top:parent.top
                        left:parent.left
                        leftMargin:parent.width/10
                    }
                }



                DisplayValeur //Appel du composant DisplayValeur (affichage des valeurs)
                {
                    id:id_display_val_gite

                    anchors
                    {
                        bottom:id_text_gite.top
                        horizontalCenter:parent.horizontalCenter
                        bottomMargin:parent.width/20
                    }
                }

                Text //NOM CASE
                {
                    id: id_text_gite
                    visible: true
                    text: qsTr("GITE")
                    color: "white"
                    font
                    {
                        pixelSize:id_HA_tangage.height/10
                        bold:true
                    }
                    anchors
                    {
                        bottom:parent.bottom
                        horizontalCenter:parent.horizontalCenter
                    }

                }

                FlecheGauche //appel composant FlecheGauche (fleche de tendance)
                {
                    id: id_fleche_gite_gauche

                }

                FlecheDroite //appel composant FlecheDroite (fleche de tendance)
                {
                    id: id_fleche_gite_droite
                }

            }

           BateauFace // Appel du composant BateauFace (afficahge de l'icone bateau de face et gestion de l'oriention de l'image)
           {
               id:id_bateau_face
           }



        }

        Rectangle //CASE 2: VISU TANGAGE-------------------------------
        {
            id: id_case2_area

            color: "#f29d52"

            height: parent.height/2
            width  : parent.height/2

            anchors
            {
                horizontalCenter:parent.horizontalCenter
                top:parent.top
            }



            HorizonArtificiel //Appel du composant horizon artificiel
            {
                id: id_HA_tangage

                Text //AFFICHAGE TEXT INDICATION PROUE
                {
                    id: id_text_proue
                    visible: true
                    text: qsTr("PROUE")
                    color: "black"
                    font
                    {
                        pixelSize:id_HA_tangage.height/10
                    }
                    anchors
                    {
                        top:parent.top
                        right:parent.right
                        rightMargin:parent.width/10
                    }
                }

                Text //AFFICHAGE TEXT INDICATION POUPE
                {
                    id: id_text_poupe
                    visible: true
                    text: qsTr("POUPE")
                    color: "black"
                    font
                    {
                        pixelSize:id_HA_tangage.height/10
                    }
                    anchors
                    {
                        top:parent.top
                        left:parent.left
                        leftMargin:parent.width/10
                    }
                }

                Text //NOM CASE
                {
                    id: id_text_tangage
                    visible: true
                    text: qsTr("TANGAGE")
                    color: "white"
                    font
                    {
                        pixelSize:id_HA_tangage.height/10
                        bold:true
                    }
                    anchors
                    {
                        bottom:parent.bottom
                        horizontalCenter:parent.horizontalCenter
                    }
                }


                DisplayValeur //Appel du composant DisplayValeur (affichage des valeurs)
                {
                    id:id_display_val_tangage

                    anchors
                    {
                        bottom:id_text_tangage.top
                        horizontalCenter:parent.horizontalCenter
                        bottomMargin:parent.width/20
                    }
                }
            }

            FlecheGauche //appel composant FlecheGauche (fleche de tendance)
            {
                id: id_fleche_tangage_gauche

            }

            FlecheDroite //appel composant FlecheDroite (fleche de tendance)
            {
                id: id_fleche_tangage_droite
            }

            BateauCote //appel du composant BAteauCote (afficahge de l'icone bateau de cote et gestion de l'oriention de l'image)
            {
                id:id_bateau_cote
            }
        }

        Rectangle // CASE 3: VISU VITESSE ------------------------------
        {

            id: id_case3_area

            color: "#0F596A"

            height: parent.height/2
            width  : parent.height/2

            anchors
            {
                right:parent.right
                top:parent.top
            }

            Text //NOM CASE
            {
                id: id_text_vitesse
                visible: true
                text: qsTr("VITESSE")
                color: "white"
                font
                {
                    pixelSize:id_HA_tangage.height/10
                    bold:true
                }
                anchors
                {
                    bottom:parent.bottom
                    horizontalCenter:parent.horizontalCenter
                 }
            }


        }

        Rectangle //CASE 4: ? -----------------------------------
        {
            id: id_case4_area

            color: "#f29d52"

            height: parent.height/2
            width  : parent.height/2

            anchors
            {
                left:parent.left
                bottom:parent.bottom
            }

            Text //NOM CASE
            {
                id: id_text_case4
                visible: true
                text: qsTr("<CASE 4>")
                color: "white"
                font
                {
                    pixelSize:id_HA_tangage.height/10
                    bold:true
                }
                anchors
                {
                    bottom:parent.bottom
                    horizontalCenter:parent.horizontalCenter
                }

            }





        }

        Rectangle //CASE 5: ? ---------------------------
        {
            id: id_case5_area

            color: "#f29d52"

            height: parent.height/2
            width  : parent.height/2

            anchors
            {
                horizontalCenter:parent.horizontalCenter
                bottom:parent.bottom
            }
            Text //NOM CASE
            {
                id: id_text_case5
                visible: true
                text: qsTr("<CASE 5>")
                color: "white"
                font
                {
                    pixelSize:id_HA_tangage.height/10
                    bold:true
                }
                anchors
                {
                    bottom:parent.bottom
                    horizontalCenter:parent.horizontalCenter
                }

            }




        }

        Rectangle //CASE 6: ?---------------------------
        {
            id: id_case6_area

            color: "#f29d52"

            height: parent.height/2
            width  : parent.height/2

            anchors
            {
                right:parent.right
                bottom:parent.bottom
            }

            Text //NOM CASE
            {
                id: id_text_case6
                visible: true
                text: qsTr("<CASE 6>")
                color: "white"
                font
                {
                    pixelSize:id_HA_tangage.height/10
                    bold:true
                }
                anchors
                {
                    bottom:parent.bottom
                    horizontalCenter:parent.horizontalCenter
                }

            }



        }

    }





}
