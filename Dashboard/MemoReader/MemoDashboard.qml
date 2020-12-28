import QtQuick 2.7
import QtQuick.Controls 1.0
import READ.FILE 1.0 //registre permettant d'avoir accés à la classe readfile
import QtQuick.Layouts 1.0
import QtQuick.Dialogs 1.0




//Description de l'interface graphique de lecture des données enregistrées lors de l'execution d'un entrainement avec le Reader



ApplicationWindow
{
    id: id_MemoDashboard

    visible:false //la fenetre de l'interface ne s'affiche pas immédiateemnt
    // taille de la fenetre à définir
    width: 1080
    height: 720

    //couleur de l'arriere plan
    color:"#004B5D"

    //instanciation des variable d'interval du timer de lecture et du nombre de ligne contenu dans le fichier lu
    property real intervalTimer: 1
    property real sizeDataFile :1




    READFILE //ajour du registre READ File permet d'avoir accés aux fonction Q_INVOKABLE et aux Q_PROPERTY de la classe readfile
    {
        id:file
    }

    FileDialog //BOITE DE DIALOGUE CHOIX FICHIER
    {
        //Affichage d'une boite de dialogue de choix d'un fichier à ouvrir pour la lecture des données

        id: fileDialog

        title: "Choix fichier d'entrainement" //Nom de la fenêtre

        folder: shortcuts.home //repertoire d'ouverture de la fiche de dialogue

        onAccepted: //lorsque le bouton accepter est cliqué
        {
            //console.log("You chose: " + fileDialog.fileUrls)
            id_MemoDashboard.visible=true //Affichage de l'interface graphique

            file.setFileUrl(fileDialog.fileUrls.toString())//appel de la fonction setFileIrl de file (lecture de l'url du fichier choisi)
            file.loadAllFile()//appel de la fonction loadAllFile de file , lecture du fichier en entier
            file.initReading()//appel de la fonction initReading de file , acquisition des données relative au fonctionnement de l'enregistrement de données
            sizeDataFile=file.getNbDataLine//lecture du nombre de ligne de données avec getNbDataLine de file
            //console.log(sizeDataFile)
            id_timeline.to=sizeDataFile-1//adaptation de la taille de la timeline en fonction du nombre de ligne
            intervalTimer=file.getValMemoTempo//adaptation de l'intervald e temps du timer de lecture en fontino de l'interval de temps de memorisation



        }
        onRejected: { //lorsque le bouton annuler est cliqué
            //console.log("Canceled")
        }
        Component.onCompleted: visible = true // affichage du composant boite de dialogue
    }

    Rectangle{ // PARTIE COMMANDE------------------------------------------------------------------------------------------------

        //case incluant toute les commandes de la lecture

        id:id_command_area

        //taille du parent
        width: parent.width
        height: parent.height

        //rectangle transparent
        border.color: "#00000000"
        color: "#00000000"

        //rectange à la couche 1 (premier plan)
        z:1


        Rectangle //TIMELINE
        {
            id:id_timeline_area //case incluant la timeline

            //prend la taille de la timeline
            width: id_timeline.width
            height: id_timeline.height

            anchors
            {
                horizontalCenter:parent.horizontalCenter //allignement milieur horizotale du parent
                bottom:parent.bottom //ancrage du bas au bas du parent
                bottomMargin:parent.height/10 //marge du bas = hauteur du parent/10

            }

            //rectangle transparent
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

                    id_display_val_gite.affichageValeurAvecSeuil(file.getValGiteVal,file.getValGiteSeuilMax,file.getValGiteSeuilMin) //appel de la fonction affichageValeur de id_display_val_gite prend en paramètre la valeur du gite ainsi que le sdeux seuil
                    id_display_val_tangage.affichageValeurAvecSeuil(file.getValTangageVal,file.getValTangageSeuilMax,file.getValTangageSeuilMin) //appel de la fonction affichageValeur de id_display_val_tangage prend en paramètre la valeur du tangage ainsi que le sdeux seuil

                    id_display_val_vitesse.affichageValeur(file.getValVitesseVal)//appel de la fonctno affichageValeur de id_display_val_vitesse pour affichage de la valeur de vitesse instantannée

                    id_tendance_vitesse_augmente.tendance(file.getValVitesseTend)
                    id_tendance_vitesse_diminue.tendance(file.getValVitesseTend)



                }
            }
        }


        PlayPauseButton //BOUTON PLAY/PAUSE : Appel du composant PlayPauseButton
        {
            id:id_play_pause_button
            anchors
            {
                left: parent.left //ancrage du coté gauche au coté gauche du composant parent
                bottom: parent.bottom //ancrage du bas au bas du composant parent
                leftMargin: parent.width/20 //largeur = largeur du parent/20
                bottomMargin: parent.height/10 //hateur = hauteur du parent /20
            }
            text: "Play"//text présent dans le boutton

            onClicked: //lorque le bouton est cliqué
            {
                if (id_timer.running==false) // lancement du timer de lecture s'il n'est pas lancé sinon arret du timer
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
            id: id_time_display_area //case incluant le texte
            anchors
            {
                verticalCenter:id_timeline_area.verticalCenter //allignement du centre vertical au centre vertical de la timeline
                left:id_timeline_area.right //ancrage du coté gauche au coté droit de la timeline
                leftMargin: parent.width/30 //marge de gauche = larguer du parent/30
            }

            //prend la taille du texte de temps
            width:  id_time_display.paintedWidth
            height: id_time_display.paintedHeight

            //rectangle transparent
            border.color: "#00000000"
            color: "#00000000"

            DigitTime //APpel du compoasant DigitTime : afficahge du temps présent correspondant à la ligne lue
            {
                id: id_time_display
                horizontalAlignment: Text.AlignHCenter

                anchors//alligné au centre du parent
                {
                    horizontalCenter: parent.horizontalCenter
                    verticalCenter: parent.verticalCenter

                }
                font.pixelSize: id_MemoDashboard.height/30 //taille de police = hauteur de id_MemoDashboard/30

            }

        }

        Timer //Creation d'un timer adapté à l'intervale de temps entre chaque donnée enregistrée
        {
            id:id_timer
            interval:intervalTimer ; running:false;repeat: true // on rafraichi l'écran toutes les 0,01 secondes
            onTriggered: //à cahque coup d'horloge
            {


                id_timeline.increase() //incrementation de la timeline à chaque coup d'horloge

                if(id_timeline.value==sizeDataFile-1)//arret automatique du timer à la fin de la timeline
                    id_timer.running=false

            }
        }

    }

    Rectangle{ // PARTIE  VISUALISATION------------------------------------------------------------------------------------------------

        //Partie visualisation : regroupe tous les composants permettant la visualisation de la lecture des données, composée de 6 cases dont trois utilisés pour le tagage la gite et la vitesse, 3 autres
        //sont prevu pour la visualisation de données suplémentaires si besoin
        //les casqe sont numérotées de 1 à 6

        id:id_interface_area

        //l'aire ou vont se positionner les cases a la meme taile que le composant parent
        width: parent.width
        height: parent.height

        //rectangle transparent
        border.color: "#00000000"
        color: "#00000000"

        //couche 0 , arriere plan
        z:0

        Rectangle //CASE 1 : VISU GITE ---------------------------------
        {
            id: id_case1_area //La case 1 est dédié à la visualisation de la gite

            color: "#f29d52" //couleur de fond

            //taille de la case = carrée de coté de longueur de hautre de parent /2
            height: parent.height/2
            width  : parent.height/2

            anchors //positionnement
            {
                left:parent.left //à gauche
                top:parent.top //en haut
            }

            HorizonArtificiel //Appel du composant horizon artificiel
            {
                id: id_HA_gite


                Text //affichage texte indication tribord
                {
                    id: id_text_tribord
                    visible: true //visibilité
                    text: qsTr("TRI")//compositino du texte
                    color: "green" //couleur du text
                    font //taille de la police
                    {
                        pixelSize:id_HA_tangage.height/10
                    }
                    anchors
                    {
                        top:parent.top //en haute
                        right:parent.right // à droite
                        rightMargin:parent.width/10 // marge de largeur de parent /10
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
                        left:parent.left //à gauche
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
                        bold:true //police en gras
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


            //DIvision de la case en 3 pour acceuillir les 3 types de données
            Rectangle
            {
                id: id_case31_area

                width: parent.width //larguer du parent
                height : parent.height/2 //hautre du parent/3

                color: "transparent" //couleur test

                anchors //placement en haut au centre
                {
                    top:parent.top
                    horizontalCenter:parent.horizontalCenter
                }

                Text
                {
                    id: id_text_instantanee
                    visible: true
                    text: qsTr("INSTANTANEE")
                    color: "#E85454"
                    font
                    {
                        pixelSize:parent.height/10
                    }
                    anchors
                    {
                        top:parent.top
                        horizontalCenter:parent.horizontalCenter
                     }
                }

                Rectangle
                {
                    id: id_case311_area

                    width: parent.width/2 //larguer du parent
                    height : parent.height //hautre du parent/3

                    color: "transparent"

                    anchors //placement en haut au centre
                    {
                        top:parent.top
                        left:parent.left
                    }

                    DisplayValeur
                    {
                        id : id_display_val_vitesse

                        color : "#E85454"

                        anchors
                        {
                            horizontalCenter: parent.horizontalCenter
                            verticalCenter: parent.verticalCenter

                        }

                        font
                        {
                            pixelSize:parent.height/5
                        }

                    }
                }

                Rectangle
                {
                    id: id_case312_area

                    width: parent.width/2 //larguer du parent
                    height : parent.height //hautre du parent/3

                    color: "transparent"

                    anchors //placement en haut au centre
                    {
                        top:parent.top
                        right:parent.right
                    }

                    FlecheHaut
                    {
                        id:id_tendance_vitesse_augmente
                    }

                    FlecheBas
                    {
                        id:id_tendance_vitesse_diminue
                    }


                }


            }

            Rectangle
            {
                id: id_case32_area


                width: parent.width/2 //larguer du parent
                height : parent.height/2 //hautre du parent/3

                color: "#0C4B5A"

                anchors //placement en haut au centre
                {
                    top:id_case31_area.bottom //ancrage haut au bas de id_case3A_area
                    left:parent.left//ancrage du coté gauche au coté gauche du parent
                }

                Text
                {
                    id: id_text_moy
                    visible: true
                    text: qsTr("MOY")
                    color: "#31BA47"
                    font
                    {
                        pixelSize:parent.height/10
                    }
                    anchors
                    {
                        top:parent.top
                        horizontalCenter:parent.horizontalCenter
                     }
                }

                DisplayValeur
                {
                    id : id_display_moy_vitesse

                    color : "#31BA47"

                    anchors
                    {
                        horizontalCenter: parent.horizontalCenter
                        verticalCenter: parent.verticalCenter

                    }

                    font
                    {
                        pixelSize:parent.height/10
                    }

                }

            }

            Rectangle
            {
                id: id_case33_area

                width: parent.width/2 //larguer du parent
                height : parent.height/2 //hautre du parent/3

                 color: "#0C4B5A" //couleur test

                anchors //placement en haut au centre
                {
                    top:id_case31_area.bottom //ancrage haut au bas de id_case3A_area
                    right:parent.right//ancrage du coté gauche au coté gauche du parent
                }

                Text
                {
                    id: id_text_max
                    visible: true
                    text: qsTr("MAX")
                    color: "#31BA47"
                    font
                    {
                        pixelSize:parent.height/10
                    }
                    anchors
                    {
                        top:parent.top
                        horizontalCenter:parent.horizontalCenter
                     }
                }

                DisplayValeur
                {
                    id : id_display_max_vitesse

                    color : "#31BA47"

                    anchors
                    {
                        horizontalCenter: parent.horizontalCenter
                        verticalCenter: parent.verticalCenter

                    }

                    font
                    {
                        pixelSize:parent.height/10
                    }

                }
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


        //Les cases suivantes sont prêtes à être complétées par la visualisation de donénes supplémentaires

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
