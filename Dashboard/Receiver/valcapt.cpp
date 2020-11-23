#include "valcapt.h"

#include <QDebug>

#include <QObject>
#include <QTimer>
#include "socketdatareceiver.h"
#include "memo.h"
#include <QSvgWidget>
#include <QWidget>
#include <QGridLayout>
#include <QtWidgets>
#include <initialisation.h>
#include <QDebug>


valcapt::valcapt(QObject *parent):QObject(parent)
{
    init();
}

void valcapt::init()
{



   deltaTMemo=250;//temps de mémorisation des données en ms[A PARAMETER]
   deltaTAquisition=1;//temps d'aquisition des données en ms[A PARAMETER]

   //initialisation des valeurs capteurs
   valTangage=0;
   valGite=0;
   valVitesse=0;

   //inititialisation des valeurs de mémorisation
   MemoValTangage=0;
   MemoValGite=0;
   MemoValVitesse=0;

   //initialisation des tendances (1= aucune évolution)
   TendanceTangage=1;
   TendanceGite=1;
   TendanceVitesse=1;

   //initialisation des seuils de tangage et gite [A PARAMETER]
   valTangageMax=50;
   valTangageMin=-50;
   valGiteMax=50;
   valGiteMin=-50;

   //initialisation du fichier de mémorisation
   memorisation.initFile(deltaTMemo);

   //connexion aux serveurs des données capteurs

   receiverTangage.Connexion(65430);
   receiverGite.Connexion(65431);
   receiverVitesse.Connexion(65432);



}

void valcapt::start()
{

    auto timerCapteur = new QTimer();
    auto timerMemo = new QTimer();
    auto timerSimuMeter = new QTimer();
    auto timerTendance = new QTimer();

    //1) ----- ajout de capteur :receiver<nom_val_nouv_capt>.Connexion(<port>); -----
    //receiverCapt_Supp_1.Connexion(65435); //A décommenter si utilisé
    //receiverCapt_Supp_2.Connexion(65436); //A décommenter si utilisé

    //-----

    //mise à jour des valeurs capteurs
    connect(timerCapteur, SIGNAL(timeout()),this,SLOT(updateTangage()));
    connect(timerCapteur, SIGNAL(timeout()),this,SLOT(updateGite()));
    connect(timerCapteur, SIGNAL(timeout()),this,SLOT(updateVitesse()));

    //mise à jour des valeurs de tendance
//    connect(timerCapteur, SIGNAL(timeout()),this,SLOT(updateTendanceTangage()));
//    connect(timerCapteur, SIGNAL(timeout()),this,SLOT(updateTendanceGite()));
//    connect(timerCapteur, SIGNAL(timeout()),this,SLOT(updateTendanceVitesse()));

    connect(timerTendance, SIGNAL(timeout()),this,SLOT(slotCalcTendance()));
    //2) ----- ajout de capteur :connect(timer, SIGNAL(timeout()),this,SLOT(update<nom_val_nouv_capt>())); -----
    //connect(timer, SIGNAL(timeout()),this,SLOT(updateCapt_Supp_2())); //A décommenter si utilisé
    //connect(timer, SIGNAL(timeout()),this,SLOT(updateCapt_Supp_1())); //A décommenter si utilisé

    //-----

    //Mémorisation des données d'entrainement dans un fichier
    connect(timerMemo, SIGNAL(timeout()),this,SLOT(slotUpdateFile()));
    connect(timerMemo, SIGNAL(timeout()),&memorisation,SLOT(updateTimeMemo()));

    //Lancement des timers
    timerCapteur->start((int)deltaTAquisition);
    timerMemo->start((int)deltaTMemo);// valeur en msec
    timerSimuMeter->start(200);//simualtaiton metre parcouru
    timerTendance->start((int)deltaTAquisition);
}

//<<<<<<<<<<<<<<<<<<Mise à jour des valeur des capteurs>>>>>>>>>>>>>>>>>>>

void valcapt::updateTangage()
{
    MemoValTangage=valTangage;//mémorisation
    if (receiverTangage.getNbByteAvailable()>0)
    {

    valTangage=receiverTangage.readyRead();
//    qDebug()<<"valTangage"<<valTangage;
//    qDebug()<<"valTangageMEMO"<<MemoValTangage;
//    qDebug()<<"Taille"<<sizeof(valTangage);
    }
}



void valcapt::updateGite()
{
    MemoValGite=valGite;//mémorisation
    if (receiverGite.getNbByteAvailable()>0)
    {

    valGite=receiverGite.readyRead();
//    qDebug()<<"valGite"<<valGite;
//    qDebug()<<"valTangageGITE"<<MemoValGite;
//    qDebug()<<"Taille"<<sizeof(valGite);
    }
}


void valcapt::updateVitesse()
{

    MemoValVitesse=valVitesse;//mémorisation

    if (receiverVitesse.getNbByteAvailable()>0)
    {
    valVitesse=receiverVitesse.readyRead();
    //qDebug()<<"valVitesse"<<valVitesse;
    //qDebug()<<"valTangageVITESSE"<<MemoValVitesse;
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






//<<<<<<<<<<<<<<<<<<Getter des valeurs des capteurs>>>>>>>>>>>>>>>>>>>

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



int valcapt::getTendanceTangage()
{
    return TendanceTangage;
}

int valcapt::getTendanceGite()
{
    return TendanceGite;
}

int valcapt::getTendanceVitesse()
{
    return TendanceVitesse;
}



float valcapt::getvalGiteMax()
{
    return valGiteMax;
}

float valcapt::getvalGiteMin()
{
    return valGiteMin;
}

float valcapt::getvalTangageMax()
{
    return valTangageMax;
}

float valcapt::getvalTangageMin()
{
    return valTangageMin;
}




Q_INVOKABLE void valcapt::initDeltaTAquisition(float newval)
{
    deltaTAquisition=newval;
}

Q_INVOKABLE void valcapt::initDeltaTMemo(float newval)
{
    deltaTMemo=newval;
}

Q_INVOKABLE void valcapt::initValGiteMax(float newval)
{
    valGiteMax=newval;
}


Q_INVOKABLE void valcapt::initValGiteMin(float newval)
{
    valGiteMin=newval;
}


Q_INVOKABLE void valcapt::initValTangageMax(float newval)
{
    valTangageMax=newval;
}


Q_INVOKABLE void valcapt::initValTangageMin(float newval)
{
    valTangageMin=newval;
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

//<<<<<<<<<<<<<<<<<<Deviation des slots avec paramètres>>>>>>>>>>>>>>>>>>>


void valcapt::slotUpdateFile()
{
    memorisation.updateFile(valGite,valTangage,valVitesse);
    qDebug()<<"updateFile";
}

void valcapt::slotCalcTendance()
{
    TendanceGite=tendanceGite.calcTendance(valGite);
    TendanceTangage=tendanceTangage.calcTendance(valTangage);
    TendanceVitesse=tendanceVitesse.calcTendance(valVitesse);

    //qDebug()<<TendanceGite;
}




