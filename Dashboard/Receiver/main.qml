import QtQuick 2.7
import QtQuick.Controls 1.0
import VAL.CAPT 1.0
import QtQuick.Layouts 1.0







ApplicationWindow{
    id: applicationWindow
    visible: true
    //visibility: "Maximized"
    width: 1080
    height: 720
    title: qsTr("Dashboard_v1")







    GridLayout
    {
        anchors.fill:parent
        columns: 1
        Image {
            id: fond
            Layout.fillWidth: true
            Layout.fillHeight: true

            clip: true
            source: "Visu/Fond.svg"


        }
    }



    Item
    {

        id: tableaudebord
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent
        Layout.preferredWidth: -1

        Layout.fillHeight: true
        Layout.fillWidth: true

        Item {
            id: vent
            x: 351
            y: 610

            anchors.verticalCenterOffset: 10
            anchors.horizontalCenterOffset: -230
            anchors.horizontalCenter: boussole.horizontalCenter
            anchors.verticalCenter: boussole.verticalCenter

            Image {
                id: aiguille_vent
                x: 52
                y: 13
                width: 116
                height: 108
                anchors.top: cadran_vent.bottom
                anchors.right: parent.right
                anchors.bottom: cadran_vent.top
                anchors.left: cadran_vent.right
                anchors.bottomMargin: -125
                anchors.leftMargin: -165
                anchors.rightMargin: 52
                anchors.topMargin: -212
                source: "Visu/Vent/aiguille.svg"
                fillMode: Image.PreserveAspectFit
            }

            Image {
                id: cadran_vent
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.left: parent.left
                anchors.bottom: parent.bottom
                anchors.top: parent.top
                source: "Visu/Vent/cadran.svg"
                fillMode: Image.PreserveAspectFit
            }

            Text {
                id: point
                x: 108
                y: 159
                text: qsTr(":")
                font.pixelSize: 12
            }

            Text {
                id: minute
                x: 113
                y: 149
                width: 43
                height: 34
                color: "#040000"
                text:"00"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 10
                lineHeight: 1.5
            }

            Text {
                id: heure
                x: 64
                y: 149
                width: 43
                height: 34
                color: "#100000"
                text:"00"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 10
                lineHeight: 1.5
            }



        }

        Item {
            id: accelero
            x: 741
            y: 313
            width: 220
            height: 220
            anchors.verticalCenterOffset: 10
            anchors.horizontalCenterOffset: 230
            anchors.horizontalCenter: boussole.horizontalCenter
            anchors.verticalCenter: boussole.verticalCenter


            Image {
                id: aiguille_accelero
                anchors.fill: parent
                clip: true
                source: "Visu/Accelero/aiguille2.svg"
                fillMode: Image.PreserveAspectFit
            }

            Image {
                id: cadran_accelero
                width: 500
                anchors.rightMargin: 0
                anchors.fill: parent
                clip: true
                source: "Visu/Accelero/cadran2.svg"
                fillMode: Image.PreserveAspectFit
            }
        }

        Item {
            id: boussole// creation du cadran de la boussole
            x: 330//position en x
            y: 222//position en y
            width: 300//largeur
            height: 300//hauteur
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter

            Image {
                id: cadran_boussole //ajout du cadran
                anchors.fill: parent//affilié à la boussole
                clip: true//visible
                source: "Visu/Boussole/cadran2.svg"//choix de l'image
                fillMode: Image.PreserveAspectFit//preserve l'aspect de l'image
            }

            Image {
                id: aiguille_boussole//ajout de l'aiguille
                anchors.rightMargin: 0
                anchors.bottomMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0
                anchors.fill: parent//affilié à la boussole
                sourceSize.height: 0
                sourceSize.width: 0
                scale: 1

                Layout.fillWidth: true
                Layout.fillHeight: true
                clip: true


                source: "Visu/Boussole/aiguille2.svg"
                fillMode: Image.PreserveAspectFit
            }


        }

        /*Ajout d'un nouveau : privilegier QtDesigner rubrique Design
        Ajouter les image souhaitées et les positionner selon l'envie
        La modification dans cette interface générera automatiquement le code QML il n'est donc pas utiles
        de modifier la partie au dessus de ce commentaire/
        Nommez vous image pour les retrouver  pour l'animation de certaines image il sera utile de se rappeler de leur nom

        Conseil: pour les image utilisez un foramt .svg pour eviter la pixélisation des images
        */



        Text {
            id: txt_lon
            x: 212
            y: 120
            color: "#ffffff"
            text: qsTr("Long :")
            font.pixelSize: 12
        }

        Text {
            id: txt_lat
            x: 212
            y: 140
            color: "#ffffff"
            text: qsTr("Lat    :")
            font.pixelSize: 12
        }

        Text {
            id: longitude
            x: 266
            y: 120
            width: 96
            height: 14
            color: "#ffffff"
            text: qsTr("Long..")
            font.pixelSize: 12
        }

        Text {
            id: latitude
            x: 266
            y: 140
            width: 96
            height: 14
            color: "#ffffff"
            text: qsTr("Lat..")
            font.pixelSize: 12
        }







    }



    VALCAPT//appel de valcapt directement dans le programme qml sous le nom de "valeur"
    {
        id:valeur
    }



    // Partie à modifier pour ajouter un capteur
    Timer
    {
        property real rot: 0
        id:timer
        interval:100; running:true;repeat: true // on rafraichi l'écran toutes les 0,1 secondes
        onTriggered:
        {
            aiguille_boussole.rotation=valeur.getvalBoussole//animation du cadran de la boussole en influant sur la rotation de son aiguille
            aiguille_accelero.rotation=valeur.getvalAccelero
            heure.text=(valeur.getvalTime/10).toFixed(0)
            minute.text=((valeur.getvalTime-(valeur.getvalTime/10))*10).toFixed(0)
            latitude.text=valeur.getvalGPS_Lat.toFixed(5)
            longitude.text=text=valeur.getvalGPS_Lon.toFixed(5)

            //ajout de capteur : faire évoluer les paramètres du dessins en fonction de valeur.get<nom_val_nouv_capt>
        }

    }





}

/*##^##
Designer {
    D{i:0;autoSize:true;height:540;width:960}D{i:1;invisible:false}D{i:7;anchors_y:313}
D{i:10;anchors_height:559;anchors_width:557;anchors_x:672;anchors_y:502}D{i:3;anchors_y:850}
}
##^##*/
