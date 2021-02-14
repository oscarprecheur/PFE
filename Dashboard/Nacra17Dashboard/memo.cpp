#include "memo.h"

memo::memo(QObject *parent):QObject(parent)
{

}

void memo::initFile(float deltaTime, float deltaAquisition, float TangMin, float TangMax, float GiteMin, float GiteMax)
{
    //delta ecriture

    if (memoDir.exists(dirName))//on cherche si le repertoire training_saves existe
    {
        qDebug()<<"Ce dossier existe";//si oui on ne fait rien
    }
    else
    {
        qDebug()<<"Ce dossier n'existe pas encore, création du dossier...";
        memoDir.mkdir(dirName);//si non on le crée
    }

    fileName = dirName+"/memoTraining"; //memoTraining est le suffixe de tous les fochiers de memorisation venant du programme



    deltaTMemo=deltaTime;

    //les valeurs de temps serviront à nommer le fichier pour le differencier des autres , cette valeurs sera le suffixe du nom du fichier
    time = time.currentTime();//on recupere l'heure
    date = date.currentDate();//on recupere la date



    if (memoFile.exists(fileName+QString::number(date.day())+"_"+QString::number(date.month())+"_"+QString::number(date.year())+"_"+QString::number(time.hour())+"h"+QString::number(time.minute())+"m"+QString::number(time.second())+"s"+".csv"))//on cherche si le ficheir à la date actuelle existe
    {
        qDebug()<<"ce fichier existe deja"; //si oui on l'ouvre (normalement impossible mais au cas ou)
        memoFile.setFileName(fileName+QString::number(date.day())+"_"+QString::number(date.month())+"_"+QString::number(date.year())+"_"+QString::number(time.hour())+"h"+QString::number(time.minute())+"m"+QString::number(time.second())+"s"+".csv");
    }
    else
    {
        qDebug()<<"Ce fichier n'existe pas encore";//si non on le crée (seul cas possible)
        memoFile.setFileName(fileName+QString::number(date.day())+"_"+QString::number(date.month())+"_"+QString::number(date.year())+"_"+QString::number(time.hour())+"h"+QString::number(time.minute())+"m"+QString::number(time.second())+"s"+".csv");
    }

    memoWrite.setDevice(&memoFile);//on affilie la méthode memoWrite au fichier aisin crée, les actions effectuées par memoWrite interviendront sur le fichier dans memoFile



    //Ecriture des pareamètres du fichier____________________________________________________________
    memoFile.open(QIODevice::WriteOnly |QIODevice::Text);//on ouvlre le fichier
    //Date
    memoWrite<<"Date: "<<";"<<QString::number(date.day())<<";"<<QString::number(date.month())<<";"<<QString::number(date.year())<<"\n";//on inscit sur la premiere ligne les paramètre de dates
    //Heure
    memoWrite<<"Heure: "<<";"<<QString::number(time.hour())<<";"<<QString::number(time.minute())<<";"<<QString::number(time.second())<<"\n";//on inscit sur la deuxieme ligne les paramètre de temps
    //Paramètre d'initialisation
    memoWrite<<" Param Temps: "<<";"<<QString::number(deltaTime)<<";"<<QString::number(deltaAquisition)<<"\n";//troisieme ligne : paramètre période mémorisation et aquisition
    //Paramètres de seuils
    memoWrite<<"Param Seuils: "<<";"<<QString::number(TangMin)<<";"<<QString::number(TangMax)<<";"<<QString::number(GiteMin)<<";"<<QString::number(GiteMax)<<"\n";//quatrieme: paramètre de seuils de la gite et du tangage
    //format de la trame
    memoWrite<<"T (s); Distance parcourue (m); Valeur Tangage (degres) ; Tendance Tangage  ; Valeur Gite (degres) ; Tendance Gite  ; Valeur Vitesse (nd) ; Tendance Vitesse ; Vitesse Moyenne 500M ; Vitesse Moyenne 10 SEC ; Direction (degres) ; Latitude (degres) ; Longitude (degres)"<<"\n";//5eme : ligne d'indication des données affichées sur les prochaines lignes


    memoFile.close();//on ferme le fichier


}

void memo::initTimeMemo() //initialisation de la mémoriation
{
    cptFile=0;
    valTimeMemo=0;
}

void memo::updateFile(float distance,float gite, float tangage, float vitesse, int tendanceTang, int tendanceGit, int tendanceVit)//ecriture dans le ficiheir des données
{
    memoFile.open(QIODevice::WriteOnly |QIODevice::Append| QIODevice::Text); //on ouvre le fichier en mode ecriture
    memoWrite<<getTimeMemo()<<";"<<distance<<";"<<tangage<<";"<<tendanceTang<<";"<<gite<<";"<<tendanceGit<<";"<<vitesse<<";"<<tendanceVit<<";"<<"vit moy 500"<<";"<<"vit moy 10s"<<";"<<"direction"<<";"<<"lat"<<";"<<"long"<<";";//ecriture de la ligne de données
    memoWrite<<"\n";//on change de ligne
    cptFile++;//incrementation du compteur du fichier
    memoFile.close();//on ferme le fichier
}

void memo::updateTimeMemo()
{
    valTimeMemo=cptFile*(deltaTMemo/1000); //calcul de la valeur de temps en fonctino du numéro de la ligne avec cptFile et de la période de mémorisation deltaTMemo en seconde
//    qDebug()<<cptFile;
//    qDebug()<<valTimeMemo;
//    qDebug()<<deltaTMemo;
}

int memo::getcptFile()
{
    return cptFile;
}

float memo::getTimeMemo()
{
    return valTimeMemo;
}
