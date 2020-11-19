import QtQuick 2.7
import QtQuick.Controls 1.0
import VAL.CAPT 1.0
import QtQuick.Layouts 1.0







ApplicationWindow
{
    id: id_dashboard

    //<<<<<<<<<<<<<<<<<<<<<<<DESCRIPTION STATIQUE>>>>>>>>>>>>>>>>>>>>>>>>>>

    //-----------HORIZON ARTIFICIEL------------------

    Rectangle//zone horizon artificiel
    {
        id: id_horizon_area
        y: -(id_horizon_area.height-parent.height)/2
        x: -(id_horizon_area.width-parent.width)/2

        width:  1080*4
        height: 1080*4
        color: "#00000000"


        //description statique horizon artificiel
        Rectangle
        {
            id: eau
            x: 0
            y: ciel.height

            width: parent.width
            height: parent.height/2
        }

        Rectangle
        {
            id: ciel
            x: 0
            y: 0
            width: parent.width
            height: parent.height/2
        }

    }

    //-----------REPERE BATEAU------------------

    Rectangle//repert verticale
    {
        id: id_repereVert_bateau_area

        anchors
        {
            horizontalCenter: parent.horizontalCenter
            verticalCenter: parent.verticalCenter
        }

        width:  parent.width
        height: parent.height
        color: "#00000000"
        transformOrigin: Item.Center
        anchors.horizontalCenterOffset: 0

        RepereVert
        {

            anchors
            {
                horizontalCenter: parent.horizontalCenter
                verticalCenter: parent.verticalCenter
            }

        }
    }

    Rectangle//repert horizontal
    {
        id: id_repereHori_bateau_area

        anchors
        {
            horizontalCenter: parent.horizontalCenter
            verticalCenter: parent.verticalCenter
        }

        width:  parent.width
        height: parent.height
        color: "#00000000"
        transformOrigin: Item.Center
        anchors.horizontalCenterOffset: 0

        RepereHori
        {

            anchors
            {
                horizontalCenter: parent.horizontalCenter
                verticalCenter: parent.verticalCenter
            }

        }
    }

    //-----------Cadran digital Tangage------------------
    Rectangle
    {
        id: id_digit_tangage
        x: 48
        y: 176
        transformOrigin: Item.Center
        //x:parent.width/3,5
        //y:parent.height/2.6

        anchors
        {
            bottom: parent.verticalCenter
        }

        width:  parent.width*0.3
        height: parent.height*0.1
        border.color: "#00000000"
        anchors.bottomMargin: 16
        color: "#00000000"

        DigitTangage
        {
            id: id_text_digit_tangage
            horizontalAlignment: Text.AlignLeft

            anchors
            {
                //left: id_Tendance_Tangage_Up.right

                //leftMargin: id_text_digit_tangage.paintedWidth/2
                verticalCenter: parent.verticalCenter
                horizontalCenter:parent.horizontalCenter
            }


        }

    }

    //-----------Tendance Tangage------------------
   Rectangle
   {
       id: id_Tendance_Tangage_Up
       transformOrigin: Item.Center



       anchors
       {
           top : id_digit_tangage.verticalCenter
           left: id_dashboard.left
       }
       border.color: "#00000000"
       color: "#00000000"

       TendanceUpTangage
       {
           id: id_Tangage_Up


           anchors
           {
               horizontalCenter: parent.horizontalCenter
               verticalCenter: parent.verticalCenter
           }

       }
   }


   Rectangle
   {
       id: id_Tendance_Tangage_Down
       transformOrigin: Item.Center
      //x:(parent.width-width)/2
      //y:parent.height/200


       anchors
       {
           top : id_digit_tangage.verticalCenter
           left: id_dashboard.left

       }
       border.color: "#00000000"
       color: "#00000000"

       TendanceDownTangage
       {
           id: id_Tangage_Down


           anchors
           {
               horizontalCenter: parent.horizontalCenter
               verticalCenter: parent.verticalCenter
               topMargin: parent.height*0.3
           }

       }
   }


    //-----------Cadran digital Gite------------------
    Rectangle
    {
        id: id_digit_gite
        transformOrigin: Item.Center
       //x:(parent.width-width)/2
       //y:parent.height/200

        anchors
        {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
        }

        width:  parent.width*0.3
        height: parent.height*0.1
        border.color: "#00000000"
        color: "#00000000"

        DigitGite
        {
            id: id_text_digit_gite
            horizontalAlignment: Text.AlignHCenter

            anchors
            {
                horizontalCenter: parent.horizontalCenter
                verticalCenter: parent.verticalCenter
            }

        }

    }

     //-----------Tendance Gite------------------
    Rectangle
    {
        id: id_Tendance_Gite_Droite
        transformOrigin: Item.Center
       //x:(parent.width-width)/2
       //y:parent.height/200


        anchors
        {
            left: id_digit_gite.right
            leftMargin:id_text_digit_gite.paintedWidth/2
            top: parent.top
        }
        border.color: "#00000000"
        color: "#00000000"

        TendanceRightGite
        {
            id: id_Gite_Droite


            anchors
            {
                horizontalCenter: parent.horizontalCenter
                verticalCenter: parent.verticalCenter
                topMargin: parent.height*0.3
            }

        }
    }


    Rectangle
    {
        id: id_Tendance_Gite_Gauche
        transformOrigin: Item.Center
       //x:(parent.width-width)/2
       //y:parent.height/200


        anchors
        {
            right: id_digit_gite.left
            rightMargin:id_text_digit_gite.paintedWidth/2
            top: parent.top
        }
        border.color: "#00000000"
        color: "#00000000"

        TendanceLeftGite
        {
            id: id_Gite_Gauche


            anchors
            {
                horizontalCenter: parent.horizontalCenter
                verticalCenter: parent.verticalCenter
                topMargin: parent.height*0.3
            }

        }
    }


    //-----------Cadran digital Vitesse (Instantanee+10sec+500m)------------------
    Rectangle
    {
        id: id_cadran_vitesse
        transformOrigin: Item.Center
        //x:(parent.width-width)/2
        //y:parent.height*0.6

        anchors
        {
            horizontalCenter: parent.horizontalCenter
            bottom: parent.bottom
        }

        width: id_digit_vitesse_instant.width
        height:id_digit_vitesse_instant.height*3.5
        border.color: "#00000000"
        color: "#00000000"

        Rectangle//vitesse istantanée
        {
            id: id_digit_vitesse_instant

            width:id_text_digit_vitesse_instant.paintedWidth
            height:id_text_digit_vitesse_instant.paintedHeight
            border.color: "#00000000"
            color: "#00000000"


            anchors
            {
                top: parent.top
                horizontalCenter: parent.horizontalCenter
            }

            DigitVitInst
            {
                id: id_text_digit_vitesse_instant
                horizontalAlignment: Text.AlignHCenter

                anchors
                {
                    horizontalCenter: parent.horizontalCenter
                    verticalCenter: parent.verticalCenter
                }
                font.pixelSize: id_dashboard.height/10

            }
        }



        //-----------Tendance Vitesse Instantanée------------------
       Rectangle
       {
           id: id_Tendance_Vitesse_Up
           transformOrigin: Item.Center
          //x:(parent.width-width)/2
          //y:parent.height/200


           anchors
           {
               left: id_digit_vitesse_instant.right
               leftMargin:id_text_digit_vitesse_instant.paintedWidth/3
               top: id_digit_vitesse_instant.top
           }
           border.color: "#00000000"
           color: "#00000000"

           TendanceVItesseUp
           {
               id: id_Vitesse_Up


               anchors
               {
                   horizontalCenter: parent.horizontalCenter
                   verticalCenter: parent.verticalCenter
                   topMargin: parent.height*0.3
               }

           }
       }


       Rectangle
       {
           id: id_Tendance_Vitesse_Down
           transformOrigin: Item.Center
          //x:(parent.width-width)/2
          //y:parent.height/200


           anchors
           {
               left: id_digit_vitesse_instant.right
               leftMargin:id_text_digit_vitesse_instant.paintedWidth/3
               bottom: id_digit_vitesse_instant.bottom
               bottomMargin:id_text_digit_vitesse_instant.paintedHeight/2
           }
           border.color: "#00000000"
           color: "#00000000"

           TendanceVitesseDown
           {
               id: id_Vitesse_Down


               anchors
               {
                   horizontalCenter: parent.horizontalCenter
                   verticalCenter: parent.verticalCenter
                   topMargin: parent.height*0.3
               }

           }
       }


        Rectangle//Unité noeud
        {
            id: id_digit_vitesse_unit

            width:id_text_digit_vitesse_instant.paintedWidth
            height:id_text_digit_vitesse_instant.paintedHeight
            border.color: "#00000000"
            color: "#00000000"
            anchors
            {
                horizontalCenter: parent.horizontalCenter
                top: id_digit_vitesse_instant.bottom
            }
            Text
            {
                id: id_text_unite

                horizontalAlignment: Text.AlignHCenter
                anchors
                {
                    top: parent.top
                    horizontalCenter: parent.horizontalCenter
                }


                width: parent.width
                height: parent.height
                text: qsTr("nd")
                font.pixelSize: id_dashboard.height/9
            }
        }

        Rectangle//vitesse max 10 sec
        {
            id: id_digit_vitesse_max_10sec

            anchors
            {
                top:id_digit_vitesse_unit.bottom
                right:parent.horizontalCenter
                rightMargin : id_dashboard.height/15
            }

            width:  id_text_digit_vitesse_max_10sec.paintedWidth
            height: id_text_digit_vitesse_max_10sec.paintedHeight
            border.color: "#00000000"
            color: "#00000000"

            DigitVitMax10
            {
                id: id_text_digit_vitesse_max_10sec
                horizontalAlignment: Text.AlignHCenter

                anchors
                {
                    horizontalCenter: parent.horizontalCenter
                    verticalCenter: parent.verticalCenter

                }
                font.pixelSize: id_dashboard.height/15

            }
        }


        Rectangle//vitesse moy 500 m
        {
            id: id_digit_vitesse_moy_500m

            anchors
            {
                top:id_digit_vitesse_unit.bottom
                left:parent.horizontalCenter
                leftMargin : id_dashboard.height/15
            }

            width:  id_text_digit_vitesse_max_10sec.paintedWidth
            height: id_text_digit_vitesse_max_10sec.paintedHeight
            border.color: "#00000000"
            color: "#00000000"

            DigitVitMoy500
            {
                id: id_text_digit_vitesse_moy_500m
                horizontalAlignment: Text.AlignHCenter

                anchors
                {
                    horizontalCenter: parent.horizontalCenter
                    verticalCenter: parent.verticalCenter

                }
                font.pixelSize: id_dashboard.height/15

            }
        }

        Text//moy 500M
        {
            id: id_text_500m

            horizontalAlignment: Text.AlignHCenter
            anchors
            {
                top: id_digit_vitesse_moy_500m.bottom
                horizontalCenter: id_digit_vitesse_moy_500m.horizontalCenter
            }
            text: qsTr("moy 500m")
            font.pixelSize: id_dashboard.height/20
        }

        Text//max 10sec
        {
            id: id_text_10sec

            horizontalAlignment: Text.AlignHCenter
            anchors
            {
                top: id_digit_vitesse_max_10sec.bottom
                horizontalCenter: id_digit_vitesse_max_10sec.horizontalCenter
            }
            text: qsTr("max 10sec")
            font.pixelSize: id_dashboard.height/20
        }


    }



    //<<<<<<<<<<<<<<<<<<<<<<<DESCRIPTION DYNAMIQUE>>>>>>>>>>>>>>>>>>>>>>>>>>

    //-----------RECUPERATION VALEURS CAPTEUR------------------

    VALCAPT//appel de valcapt directement dans le programme qml sous le nom de "valeur"
    {
        id:valeur
    }

    //-----------FCT DYNAMIQUE DU SYSTEME------------------

    Timer//COULEUR HORIZON
        {
            id:timercolor
            interval:10; running:true;repeat: true // on rafraichi l'écran toutes les 0,01 secondes
            onTriggered:
            {
                //changement de couleur selon les valeur de gite et de tangage
                if(valeur.getvalGite<50 && valeur.getvalGite>-50 && valeur.getvalTangage<50 && valeur.getvalTangage>-50)
                {
                    eau.color="#03738C"
                    ciel.color="#f29d52"
                }
                else
                {
                    eau.color="#591902"
                    ciel.color="#f23005"

                }

            }

        }

    Timer//TANGAGE
        {
            id:timertangage
            interval:1; running:true;repeat: true // on rafraichi l'écran toutes les 0,01 secondes
            onTriggered:
            {

                //mouvmeent de l'horizon artificiel
                id_horizon_area.y=-((id_horizon_area.height-parent.height)/2)-(valeur.getvalTangage*(id_dashboard.height/270))//translation -> tangage

                //cadran digital
                id_text_digit_tangage.text=valeur.getvalTangage.toFixed(3)+"°"

                if(valeur.getTendanceTangage==2)
                {
                    id_Tendance_Tangage_Up.clip=false
                    id_Tendance_Tangage_Down.clip=true
                }
                else if(valeur.getTendanceTangage==0)
                {
                    id_Tendance_Tangage_Up.clip=true
                    id_Tendance_Tangage_Down.clip=false
                }
                else
                {
                    id_Tendance_Tangage_Down.clip=true
                    id_Tendance_Tangage_Up.clip=true
                }

            }

        }
    Timer//GITE
        {
            id:timergite
            interval:1; running:true;repeat: true // on rafraichi l'écran toutes les 0,01 secondes
            onTriggered:
            {

                //mouvmeent de l'horizon artificiel
                id_horizon_area.rotation=valeur.getvalGite //rotation -> gite
                //cadran digital
                id_text_digit_gite.text=valeur.getvalGite.toFixed(3)+"°"

                if(valeur.getTendanceGite==2)
                {
                    id_Tendance_Gite_Droite.clip=false
                    id_Tendance_Gite_Gauche.clip=true
                }
                else if(valeur.getTendanceGite==0)
                {
                    id_Tendance_Gite_Droite.clip=true
                    id_Tendance_Gite_Gauche.clip=false
                }
                else
                {
                    id_Tendance_Gite_Gauche.clip=true
                    id_Tendance_Gite_Droite.clip=true
                }


            }

        }

    Timer//VITESSE
        {
            id:timervitesse
            interval:1; running:true;repeat: true // on rafraichi l'écran toutes les 0,01 secondes
            onTriggered:
            {

                //cadran digital vitesse instantannée
                id_text_digit_vitesse_instant.text=valeur.getvalVitesse.toFixed(3)

                //cadran digital vitesse max 10sec

                //cadran digital vitesse moy 500M

                //adaptation couleur
                if(valeur.getvalGite<valeur.getvalGiteMax && valeur.getvalGite>valeur.getvalGiteMin && valeur.getvalTangage<valeur.getvalTangageMax && valeur.getvalTangage>valeur.getvalTangageMin)
                {
                    id_text_digit_vitesse_instant.color="#e95454"
                    id_text_unite.color="#C07680"
                    id_text_digit_vitesse_max_10sec.color="#e95454"
                    id_text_digit_vitesse_moy_500m.color="#e95454"
                    id_text_500m.color="#C07680"
                    id_text_10sec.color="#C07680"

                }
                else
                {
                    id_text_digit_vitesse_instant.color="#77C7D9"
                    id_text_unite.color="#03738C"
                    id_text_digit_vitesse_max_10sec.color="#77C7D9"
                    id_text_digit_vitesse_moy_500m.color="#77C7D9"
                    id_text_500m.color="#03738C"
                    id_text_10sec.color="#03738C"

                }

                if(valeur.getTendanceVitesse==2)
                {

                    id_Tendance_Vitesse_Down.clip=true
                    id_Tendance_Vitesse_Up.clip=false
                }
                else if(valeur.getTendanceVitesse==0)
                {
                    id_Tendance_Vitesse_Down.clip=false
                    id_Tendance_Vitesse_Up.clip=true
                }
                else
                {
                    id_Tendance_Vitesse_Down.clip=true
                    id_Tendance_Vitesse_Up.clip=true
                }

            }

        }




}































//    GridLayout
//    {
//        anchors.fill:parent
//        columns: 1
//        Image {
//            id: fond
//            Layout.fillWidth: true
//            Layout.fillHeight: true

//            clip: true
//            source: "Visu/Fond.svg"


//        }
//    }



//    Item
//    {

//        id: tableaudebord
//        anchors.rightMargin: 0
//        anchors.bottomMargin: 0
//        anchors.leftMargin: 0
//        anchors.topMargin: 0
//        anchors.fill: parent
//        Layout.preferredWidth: -1

//        Layout.fillHeight: true
//        Layout.fillWidth: true

//        Item {
//            id: vent
//            x: 351
//            y: 610

//            anchors.verticalCenterOffset: 10
//            anchors.horizontalCenterOffset: -230
//            anchors.horizontalCenter: boussole.horizontalCenter
//            anchors.verticalCenter: boussole.verticalCenter

//            Image {
//                id: aiguille_vent
//                x: 52
//                y: 13
//                width: 116
//                height: 108
//                anchors.top: cadran_vent.bottom
//                anchors.right: parent.right
//                anchors.bottom: cadran_vent.top
//                anchors.left: cadran_vent.right
//                anchors.bottomMargin: -125
//                anchors.leftMargin: -165
//                anchors.rightMargin: 52
//                anchors.topMargin: -212
//                source: "Visu/Vent/aiguille.svg"
//                fillMode: Image.PreserveAspectFit
//            }

//            Image {
//                id: cadran_vent
//                anchors.horizontalCenter: parent.horizontalCenter
//                anchors.left: parent.left
//                anchors.bottom: parent.bottom
//                anchors.top: parent.top
//                source: "Visu/Vent/cadran.svg"
//                fillMode: Image.PreserveAspectFit
//            }

//            Text {
//                id: point
//                x: 108
//                y: 159
//                text: qsTr(":")
//                font.pixelSize: 12
//            }

//            Text {
//                id: minute
//                x: 113
//                y: 149
//                width: 43
//                height: 34
//                color: "#040000"
//                text:"00"
//                verticalAlignment: Text.AlignVCenter
//                horizontalAlignment: Text.AlignHCenter
//                font.pointSize: 10
//                lineHeight: 1.5
//            }

//            Text {
//                id: heure
//                x: 64
//                y: 149
//                width: 43
//                height: 34
//                color: "#100000"
//                text:"00"
//                verticalAlignment: Text.AlignVCenter
//                horizontalAlignment: Text.AlignHCenter
//                font.pointSize: 10
//                lineHeight: 1.5
//            }



//        }

//        Item {
//            id: accelero
//            x: 741
//            y: 313
//            width: 220
//            height: 220
//            anchors.verticalCenterOffset: 10
//            anchors.horizontalCenterOffset: 230
//            anchors.horizontalCenter: boussole.horizontalCenter
//            anchors.verticalCenter: boussole.verticalCenter


//            Image {
//                id: aiguille_accelero
//                anchors.fill: parent
//                clip: true
//                source: "Visu/Accelero/aiguille2.svg"
//                fillMode: Image.PreserveAspectFit
//            }

//            Image {
//                id: cadran_accelero
//                width: 500
//                anchors.rightMargin: 0
//                anchors.fill: parent
//                clip: true
//                source: "Visu/Accelero/cadran2.svg"
//                fillMode: Image.PreserveAspectFit
//            }
//        }

//        Item {
//            id: boussole// creation du cadran de la boussole
//            x: 330//position en x
//            y: 222//position en y
//            width: 300//largeur
//            height: 300//hauteur
//            anchors.horizontalCenter: parent.horizontalCenter
//            anchors.verticalCenter: parent.verticalCenter

//            Image {
//                id: cadran_boussole //ajout du cadran
//                anchors.fill: parent//affilié à la boussole
//                clip: true//visible
//                source: "Visu/Boussole/cadran2.svg"//choix de l'image
//                fillMode: Image.PreserveAspectFit//preserve l'aspect de l'image
//            }

//            Image {
//                id: aiguille_boussole//ajout de l'aiguille
//                anchors.rightMargin: 0
//                anchors.bottomMargin: 0
//                anchors.leftMargin: 0
//                anchors.topMargin: 0
//                anchors.fill: parent//affilié à la boussole
//                sourceSize.height: 0
//                sourceSize.width: 0
//                scale: 1

//                Layout.fillWidth: true
//                Layout.fillHeight: true
//                clip: true


//                source: "Visu/Boussole/aiguille2.svg"
//                fillMode: Image.PreserveAspectFit
//            }


//        }

//        /*Ajout d'un nouveau : privilegier QtDesigner rubrique Design
//        Ajouter les image souhaitées et les positionner selon l'envie
//        La modification dans cette interface générera automatiquement le code QML il n'est donc pas utiles
//        de modifier la partie au dessus de ce commentaire/
//        Nommez vous image pour les retrouver  pour l'animation de certaines image il sera utile de se rappeler de leur nom

//        Conseil: pour les image utilisez un foramt .svg pour eviter la pixélisation des images
//        */



//        Text {
//            id: txt_lon
//            x: 212
//            y: 120
//            color: "#ffffff"
//            text: qsTr("Long :")
//            font.pixelSize: 12
//        }

//        Text {
//            id: txt_lat
//            x: 212
//            y: 140
//            color: "#ffffff"
//            text: qsTr("Lat    :")
//            font.pixelSize: 12
//        }

//        Text {
//            id: longitude
//            x: 266
//            y: 120
//            width: 96
//            height: 14
//            color: "#ffffff"
//            text: qsTr("Long..")
//            font.pixelSize: 12
//        }

//        Text {
//            id: latitude
//            x: 266
//            y: 140
//            width: 96
//            height: 14
//            color: "#ffffff"
//            text: qsTr("Lat..")
//            font.pixelSize: 12
//        }







//    }



//    VALCAPT//appel de valcapt directement dans le programme qml sous le nom de "valeur"
//    {
//        id:valeur
//    }



//    // Partie à modifier pour ajouter un capteur
//    Timer
//    {
//        property real rot: 0
//        id:timer
//        interval:100; running:true;repeat: true // on rafraichi l'écran toutes les 0,1 secondes
//        onTriggered:
//        {
//            aiguille_boussole.rotation=valeur.getvalBoussole//animation du cadran de la boussole en influant sur la rotation de son aiguille
//            aiguille_accelero.rotation=valeur.getvalAccelero
//            heure.text=(valeur.getvalTime/10).toFixed(0)
//            minute.text=((valeur.getvalTime-(valeur.getvalTime/10))*10).toFixed(0)
//            latitude.text=valeur.getvalGPS_Lat.toFixed(5)
//            longitude.text=text=valeur.getvalGPS_Lon.toFixed(5)

//            //ajout de capteur : faire évoluer les paramètres du dessins en fonction de valeur.get<nom_val_nouv_capt>
//        }

//    }





//}

/*##^##
Designer {
    D{i:0;autoSize:true;formeditorZoom:0.25;height:480;width:640}D{i:1;invisible:false}
}
##^##*/













































