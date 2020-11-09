#include "valcapt.h"

#include <QDebug>

#include <QObject>
#include <QTimer>
#include "socketdatareceiver.h"
#include <QSvgWidget>
#include <QWidget>
#include <QGridLayout>
#include <QtWidgets>


valcapt::valcapt(QObject *parent):QObject(parent)
{
    auto timerCapteur = new QTimer();
    auto timerMemo = new QTimer();
    auto timerSimuMeter = new QTimer();

    //<<<<<<<<<<<<<<<<<<INITIALISATIONS>>>>>>>>>>>>>>>>>>>

    initFile();

    //<<<<<<<<<<<<<<<<<<Connexion aux serveurs>>>>>>>>>>>>>>>>>>>

    receiverBoussole.Connexion(65434);//connexion d'un capteur (boussole) sur le port 65432
    receiverAccelero.Connexion(65431);//connexion d'un capteur (accelerometre lateral) sur le port 65434
    receiverGPS_Lat.Connexion(65432);
    receiverGPS_Lon.Connexion(65433);
    receiverTime.Connexion(65435);

    receiverTangage.Connexion(65436);
    receiverGite.Connexion(65437);
    receiverVitesse.Connexion(65438);



    //1) ----- ajout de capteur :receiver<nom_val_nouv_capt>.Connexion(<port>); -----
    //receiverCapt_Supp_1.Connexion(65435); //A décommenter si utilisé
    //receiverCapt_Supp_2.Connexion(65436); //A décommenter si utilisé

    //-----


    connect(timerCapteur, SIGNAL(timeout()),this,SLOT(updateBoussole()));
    connect(timerCapteur, SIGNAL(timeout()),this,SLOT(updateGPS_Lat()));
    connect(timerCapteur, SIGNAL(timeout()),this,SLOT(updateGPS_Lon()));
    connect(timerCapteur, SIGNAL(timeout()),this,SLOT(updateTime()));
    connect(timerCapteur, SIGNAL(timeout()),this,SLOT(updateAccelero()));

    connect(timerCapteur, SIGNAL(timeout()),this,SLOT(updateTangage()));
    connect(timerCapteur, SIGNAL(timeout()),this,SLOT(updateGite()));
    connect(timerCapteur, SIGNAL(timeout()),this,SLOT(updateVitesse()));


    //2) ----- ajout de capteur :connect(timer, SIGNAL(timeout()),this,SLOT(update<nom_val_nouv_capt>())); -----
    //connect(timer, SIGNAL(timeout()),this,SLOT(updateCapt_Supp_2())); //A décommenter si utilisé
    //connect(timer, SIGNAL(timeout()),this,SLOT(updateCapt_Supp_1())); //A décommenter si utilisé

    //-----

    //Mémorisation des données d'entrainement dans un fichier
    connect(timerMemo, SIGNAL(timeout()),this,SLOT(updateFile()));
    connect(timerMemo, SIGNAL(timeout()),this,SLOT(updateTimeMemo()));
    //Lancement des timers
    timerCapteur->start();
    timerMemo->start(deltaTMemo);// valeur en msec
    timerSimuMeter->start(200);//simualtaiton metre parcouru
}

//<<<<<<<<<<<<<<<<<<Mise à jour des valeur des capteurs>>>>>>>>>>>>>>>>>>>

void valcapt::updateGPS_Lat()
{
    if (receiverGPS_Lat.getNbByteAvailable()>0)
    {
    valGPS_Lat=receiverGPS_Lat.readyRead();
//    qDebug()<<"valGPS_Lat"<<valGPS_Lat;
//    qDebug()<<"Taille"<<sizeof(valGPS_Lat);
    }

}

void valcapt::updateGPS_Lon()
{
    if (receiverGPS_Lon.getNbByteAvailable()>0)
    {
    valGPS_Lat=receiverGPS_Lon.readyRead();
//    qDebug()<<"valGPS_Lon"<<valGPS_Lon;
//    qDebug()<<"Taille"<<sizeof(valGPS_Lon);
    }

}

void valcapt::updateTime()
{
    if (receiverTime.getNbByteAvailable()>0)
    {
    valGPS_Lat=receiverTime.readyRead();
//    qDebug()<<"valGPS_Lon"<<valTime;
//    qDebug()<<"Taille"<<sizeof(valTime);
    }

}

void valcapt::updateBoussole()
{


 if (receiverBoussole.getNbByteAvailable()>0)
 {
    valBoussole=receiverBoussole.readyRead();
//    qDebug()<<"valBoussole"<<valBoussole;
//    qDebug()<<"Taille"<<sizeof(valBoussole);
 }


}

void valcapt::updateAccelero()
{
    if (receiverAccelero.getNbByteAvailable()>0)
    {
    valAccelero=receiverAccelero.readyRead();
//    qDebug()<<"valAccelero"<<valAccelero;
//    qDebug()<<"Taille"<<sizeof(valAccelero);
    }
}





void valcapt::updateTangage()
{
    if (receiverTangage.getNbByteAvailable()>0)
    {
    valTangage=receiverTangage.readyRead();
//    qDebug()<<"valTangage"<<valTangage;
//    qDebug()<<"Taille"<<sizeof(valTangage);
    }
}



void valcapt::updateGite()
{
    if (receiverGite.getNbByteAvailable()>0)
    {
    valGite=receiverGite.readyRead();
//    qDebug()<<"valGite"<<valGite;
//    qDebug()<<"Taille"<<sizeof(valGite);
    }
}


void valcapt::updateVitesse()
{
    if (receiverVitesse.getNbByteAvailable()>0)
    {
    valVitesse=receiverVitesse.readyRead();
//    qDebug()<<"valVitesse"<<valVitesse;
//    qDebug()<<"Taille"<<sizeof(valVitesse);
    }
}





//3) ----- ajout de capteur : -----
                /*
                void valcapt::update<nom_val_nouv_capt>()
                {
                    if (receiver<nom_val_nouv_capt>.getNbByteAvailable()>0)
                    {
                    val<nom_val_nouv_capt>=receiver<nom_val_nouv_capt>.readyRead();
                    }
                qDebug()<<"<nom_val_nouv_capt> "<<val<nom_val_nouv_capt>;
                }
                */

//void valcapt::updateCapt_Supp_1() //A décommenter si utilisé
//{
//    if (receiverCapt_Supp_1.getNbByteAvailable()>0)
//    {
//    valCapt_Supp_1=receiverCapt_Supp_1.readyRead();
//    }
//qDebug()<<"Capt_Supp_1 "<<valCapt_Supp_1;
//}


//void valcapt::updateCapt_Supp_2() //A décommenter si utilisé
//{
//    if (receiverCapt_Supp_2.getNbByteAvailable()>0)
//    {
//    valCapt_Supp_2=receiverCapt_Supp_2.readyRead();
//    }
// qDebug()<<"Vitesse Vent "<<valCapt_Supp_2;
//}

//-----

void valcapt::initFile()
{
    if (memoFile.exists(fileName))
    {
        qDebug()<<"ce fichier existe deja";
        memoFile.setFileName(fileName+QString::number(cptTraining)+".txt");
    }
    else
    {
        qDebug()<<"Ce fichier n'existe pas encore";
        memoFile.setFileName(fileName+".txt");
    }

    memoWrite.setDevice(&memoFile);
    if (memoFile.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug()<<"Fichier "<<memoFile.fileName()<<" ouvert";
    else
        qDebug()<<"Erreur fichier "<<memoFile.fileName();

}

void valcapt::updateFile()
{

    memoWrite<<" T:"<<getTimeMemo()<<"//Compass:"<<getvalBoussole()<<"//Accelero:"<<getvalAccelero()<<"//LatGPS:"<<getvalGPS_Lat()<<"//LonGPS:"<<getvalGPS_Lon()<<"\n";
    cptFile++;
}

void valcapt::updateTimeMemo()
{
    valTimeMemo=cptFile*(deltaTMemo/1000);
//    qDebug()<<cptFile;
//    qDebug()<<valTimeMemo;
//    qDebug()<<deltaTMemo;
}




//<<<<<<<<<<<<<<<<<<Getter des valeurs des capteurs>>>>>>>>>>>>>>>>>>>

float valcapt::getvalGPS_Lat()
{
    return valGPS_Lat;
}

float valcapt::getvalGPS_Lon()
{
    return valGPS_Lon;
}

float valcapt::getvalTime()
{
    return valTime;
}

float valcapt::getvalAccelero()
{
    return valAccelero;
}

float valcapt::getvalBoussole()
{
    return valBoussole;
}






float valcapt::getvalTangage()
{
    return valTangage;
}

float valcapt::getvalGite()
{
    return valGite;
}

float valcapt::getvalVitesse()
{
    return valVitesse;
}


//4) ----- ajout de capteur : -----
                /*
                float valcapt::get<nom_val_nouv_capt>()
                {
                    return val<nom_val_nouv_capt>;
                }
                */

//float valcapt::getvalCapt_Supp_1() //A décommenter si utilisé
//{
//    return valCapt_Supp_1;
//}

//float valcapt::getvalCapt_Supp_2() //A décommenter si utilisé
//{
//    return valCapt_Supp_2;
//}

//-----


int valcapt::getcptFile()
{
    return cptFile;
}

float valcapt::getTimeMemo()
{
    return valTimeMemo;
}









