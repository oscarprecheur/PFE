#include "memo.h"

memo::memo(QObject *parent):QObject(parent)
{

}

void memo::initFile(float deltaTime, float deltaAquisition, float TangMin, float TangMax, float GiteMin, float GiteMax)
{
    //delta ecriture

    if (memoDir.exists(dirName))
    {
        qDebug()<<"Ce dossier existe";
    }
    else
    {
        qDebug()<<"Ce dossier n'existe pas encore, création du dossier...";
        memoDir.mkdir(dirName);
    }

    fileName = dirName+"/memoTraining";



    deltaTMemo=deltaTime;
    time = time.currentTime();
    date = date.currentDate();



    if (memoFile.exists(fileName+QString::number(date.day())+"_"+QString::number(date.month())+"_"+QString::number(date.year())+"_"+QString::number(time.hour())+"h"+QString::number(time.minute())+"m"+QString::number(time.second())+"s"+".csv"))
    {
        qDebug()<<"ce fichier existe deja";
        memoFile.setFileName(fileName+QString::number(date.day())+"_"+QString::number(date.month())+"_"+QString::number(date.year())+"_"+QString::number(time.hour())+"h"+QString::number(time.minute())+"m"+QString::number(time.second())+"s"+".csv");
    }
    else
    {
        qDebug()<<"Ce fichier n'existe pas encore";
        memoFile.setFileName(fileName+QString::number(date.day())+"_"+QString::number(date.month())+"_"+QString::number(date.year())+"_"+QString::number(time.hour())+"h"+QString::number(time.minute())+"m"+QString::number(time.second())+"s"+".csv");
    }

    memoWrite.setDevice(&memoFile);
//    if (memoFile.open(QIODevice::WriteOnly | QIODevice::Text))
//        qDebug()<<"Fichier "<<memoFile.fileName()<<" ouvert";
//    else
//        qDebug()<<"Erreur fichier "<<memoFile.fileName();


    //Ecriture des pareamètres du fichier____________________________________________________________
    memoFile.open(QIODevice::WriteOnly |QIODevice::Text);
    //Date
    memoWrite<<"Date: "<<";"<<QString::number(date.day())<<";"<<QString::number(date.month())<<";"<<QString::number(date.year())<<"\n";
    //Heure
    memoWrite<<"Heure: "<<";"<<QString::number(time.hour())<<";"<<QString::number(time.minute())<<";"<<QString::number(time.second())<<"\n";
    //Paramètre d'initialisation
    memoWrite<<" Param Temps: "<<";"<<QString::number(deltaTime)<<";"<<QString::number(deltaAquisition)<<"\n";
    //Paramètres de seuils
    memoWrite<<"Param Seuils: "<<";"<<QString::number(TangMin)<<";"<<QString::number(TangMax)<<";"<<QString::number(GiteMin)<<";"<<QString::number(GiteMax)<<"\n";
    //format de la trame
    memoWrite<<"T (s); Distance parcourue (m); Valeur Tangage (degres) ; Tendance Tangage  ; Valeur Gite (degres) ; Tendance Gite  ; Valeur Vitesse (nd) ; Tendance Vitesse ; Vitesse Moyenne 500M ; Vitesse Moyenne 10 SEC ; Direction (degres) ; Latitude (degres) ; Longitude (degres)"<<"\n";

    memoFile.close();


}

void memo::initTimeMemo()
{
    cptFile=0;
    valTimeMemo=0;
}

void memo::updateFile(float distance,float gite, float tangage, float vitesse, int tendanceTang, int tendanceGit, int tendanceVit)
{
    memoFile.open(QIODevice::WriteOnly |QIODevice::Append| QIODevice::Text);
    memoWrite<<getTimeMemo()<<";"<<distance<<";"<<tangage<<";"<<tendanceTang<<";"<<gite<<";"<<tendanceGit<<";"<<vitesse<<";"<<tendanceVit<<";"<<"vit moy 500"<<";"<<"vit moy 10s"<<";"<<"direction"<<";"<<"lat"<<";"<<"long"<<";";
    memoWrite<<"\n";
    cptFile++;
    memoFile.close();
}

void memo::updateTimeMemo()
{
    valTimeMemo=cptFile*(deltaTMemo/1000);
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
