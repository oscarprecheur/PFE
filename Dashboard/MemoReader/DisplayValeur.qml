import QtQuick 2.0

//ce composant est un texte permetant d'afficher les valeurs de données mise en paramètre de la focntino affichageValeur

Text {


    id: id_display_val

    //prend la taille du parent /10
    width: parent.width/10
    height: parent.height/10


    font.bold:true//police en gras

    text: qsTr("---.---")//texte d'initialisation

    font.pixelSize: parent.height/15 //police prend la hauteur du parent/15

    horizontalAlignment: Text.AlignHCenter//Texte aligné au centre

    function affichageValeurAvecSeuil(valeur,valeurMax,valeurMin)
    //cette foncntion peret d'afficher les valeurs prises en paramètre. Elle recupère de plus
    //les valeurs des seuils et affiche de combien ils sont dépassé lorsque c'est le cas

    {
        if(valeur>valeurMax) //si la valeur dépasse le seuil max
        {
            id_display_val.text=qsTr(valeur.toFixed(2)+"°"+"(+"+(valeur-valeurMax).toFixed(2)+"°)") // le texte change
            id_display_val.color="red" //couleur du texte
        }
        else if (valeur<valeurMin) //si la valeur dépasse le seuil min
        {
            id_display_val.text=qsTr(valeur.toFixed(2)+"°"+"("+(valeur-valeurMin).toFixed(2)+"°)") //le texte change
            id_display_val.color="red"//couleur du texte
        }
        else
        {
            id_display_val.text=qsTr(valeur.toFixed(2)+"°") //le texte change
            id_display_val.color="black" // couleur du texte
        }

    }

    function affichageValeur (valeur)
    {
        id_display_val.text=qsTr(valeur.toFixed(2)+"°") //le texte change
    }
}
