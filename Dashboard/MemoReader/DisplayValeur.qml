import QtQuick 2.0

        Text {
            id: id_digit_tang
            width: parent.width/10
            height: parent.height/10
            //color: "#e95454"
            font.bold:true
            text: qsTr("---.---")
            font.pixelSize: parent.height/10
            horizontalAlignment: Text.AlignHCenter

            function affichageValeur(valeur,valeurMax,valeurMin)
            {
                if(valeur>valeurMax)
                {
                  id_digit_tang.text=qsTr(valeur.toFixed(2)+"°\n"+"(+"+(valeur-valeurMax).toFixed(2)+"°)")
                  id_digit_tang.color="red"
                }
                else if (valeur<valeurMin)
                {
                    id_digit_tang.text=qsTr(valeur.toFixed(2)+"°\n"+"("+(valeur-valeurMin).toFixed(2)+"°)")
                    id_digit_tang.color="red"
                }
                else
                {
                    id_digit_tang.text=qsTr(valeur.toFixed(2)+"°")
                    id_digit_tang.color="black"
                }




            }
        }
