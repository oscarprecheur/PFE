import QtQuick 2.7

//Ce composant permet d'affiche un horizon artificiel en deux partie : partie eau (bas) partie ciel (haut)

Rectangle
{

    width:  parent.width
    height: parent.height
    color: "#00000000"

    Rectangle //rectange representant l'eau
    {
        id: eau
        x: 0
        y: ciel.height
        color:"#03738C"



        width: parent.width
        height: parent.height/2
    }

    Rectangle
    {
        id: ciel
        x: 0
        y: 0
        color:"#f29d52"


        width: parent.width
        height: parent.height/2
    }

    function color_HA(valeurActu,seuilMax,seuilMin) //fonction permettant le changement de couleur de l'horizon en foncitno de la valeur en paramètre et des seuils en paramètre
    {
        if(valeurActu<seuilMax && valeurActu>seuilMin) //seuils dépassés
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





