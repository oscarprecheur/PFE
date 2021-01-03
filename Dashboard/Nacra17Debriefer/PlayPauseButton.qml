import QtQuick 2.0
import QtQuick.Controls 2.15

//Ce composant est un bouton permetant la mise en marche ou l'arret de la lecture des données du fichier

Button {

        id: button

        //déscription de l'arriere plan du bouton
        background: Rectangle {
            //taille du bouton
            implicitWidth: 100
            implicitHeight: 100

            //couleur du bouton appuyé et relaché
            color: {button.down ? "#31BA47" : "#E85454"}

            //couler des bord
            border.color: "#00000000"

            //épaisseur des bords
            border.width: 1

            //rayon de courbure des sommet (0 bouton carré - 1000 bouton rond)
            radius: 1000
        }
}
