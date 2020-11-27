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
#include <QDebug>


valcapt::valcapt(QObject *parent):QObject(parent)
{
    init();
}

void valcapt::init()
{

   //initialisation des valeurs capteurs
   valTangage=0;
   valGite=0;
   valVitesse=0;
   valDistance=0;

   //inititialisation des valeurs de mémorisation
   MemoValTangage=0;
   MemoValGite=0;
   MemoValVitesse=0;
   MemoValDistance=0;

   //initialisation des tendances (1= aucune évolution)
   TendanceTangage=1;
   TendanceGite=1;
   TendanceVitesse=1;

   //initialisation du fichier de mémorisation
   memorisation.initTimeMemo();

   //initialisation de l'etat d'entrainement
   onTraining=false;

   //connexion aux serveurs des données capteurs

   receiverTangage.Connexion(65430);
   receiverGite.Connexion(65431);
   receiverVitesse.Connexion(65432);
   receiverDistance.Connexion(65433);
   start();


}

void valcapt::start()
{



    //1) ----- ajout de capteur :receiver<nom_val_nouv_capt>.Connexion(<port>); -----
    //receiverCapt_Supp_1.Connexion(65435); //A décommenter si utilisé
    //receiverCapt_Supp_2.Connexion(65436); //A décommenter si utilisé

    //-----

    //mise à jour des valeurs capteurs
    connect(&timerCapteur, SIGNAL(timeout()),this,SLOT(updateTangage()));
    connect(&timerCapteur, SIGNAL(timeout()),this,SLOT(updateGite()));
    connect(&timerCapteur, SIGNAL(timeout()),this,SLOT(updateVitesse()));
    connect(&timerCapteur, SIGNAL(timeout()),this,SLOT(updateDistance()));

    //mise à jour des valeurs de tendance
//    connect(timerCapteur, SIGNAL(timeout()),this,SLOT(updateTendanceTangage()));
//    connect(timerCapteur, SIGNAL(timeout()),this,SLOT(updateTendanceGite()));
//    connect(timerCapteur, SIGNAL(timeout()),this,SLOT(updateTendanceVitesse()));

    connect(&timerTendance, SIGNAL(timeout()),this,SLOT(slotCalcTendance()));
    //2) ----- ajout de capteur :connect(timer, SIGNAL(timeout()),this,SLOT(update<nom_val_nouv_capt>())); -----
    //connect(timer, SIGNAL(timeout()),this,SLOT(updateCapt_Supp_2())); //A décommenter si utilisé
    //connect(timer, SIGNAL(timeout()),this,SLOT(updateCapt_Supp_1())); //A décommenter si utilisé

    //-----

    //Mémorisation des données d'entrainement dans un fichier


    //Lancement des timers
    timerCapteur.start((int)deltaTAquisition);
    timerMemo.start((int)deltaTMemo);// valeur en msec
    timerSimuMeter.start(200);//simualtaiton metre parcouru
    timerTendance.start((int)deltaTAquisition);
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
//    qDebug()<<"valGiteMEMO"<<MemoValGite;
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
    //qDebug()<<"valVitesseMEMO"<<MemoValVitesse;
//    qDebug()<<"Taille"<<sizeof(valVitesse);
    }
}

void valcapt::updateDistance()
{

    MemoValDistance=valDistance;//mémorisation

    if (receiverDistance.getNbByteAvailable()>0)
    {
    valDistance=receiverDistance.readyRead();
    //qDebug()<<"valDistance"<<valDistance;
    //qDebug()<<"valDistanceMEMO"<<MemoValDistance;
    //qDebug()<<"Taille"<<sizeof(valDistance);
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
float valcapt::getvalDistance()
{
    return valDistance;
}

//<<<<<<<<<<<<<<<<<<<<<<<Getter des valeurs des tendances>>>>>>>>>>>>>>>>>>>>>>>>>

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

bool valcapt:: getOnTraining()
{
    return onTraining;
}



Q_INVOKABLE void valcapt::initDeltaTAquisition(float newval)
{
    deltaTAquisition=newval;
    qDebug()<<deltaTAquisition;
}

Q_INVOKABLE void valcapt::initDeltaTMemo(float newval)
{
    deltaTMemo=newval;
    qDebug()<<deltaTMemo;
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

Q_INVOKABLE void valcapt::lauchStopTraining()
{
    if (onTraining==false)
    {
           memorisation.initFile(deltaTMemo);
           memorisation.initTimeMemo();
           connect(&timerMemo, SIGNAL(timeout()),this,SLOT(slotUpdateFile()));
           connect(&timerMemo, SIGNAL(timeout()),&memorisation,SLOT(updateTimeMemo()));
           onTraining=true;
    }
    else
    {
           memorisation.initTimeMemo();
           disconnect(&timerMemo, SIGNAL(timeout()),this,SLOT(slotUpdateFile()));
           disconnect(&timerMemo, SIGNAL(timeout()),&memorisation,SLOT(updateTimeMemo()));
           onTraining=false;
    }




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
    memorisation.updateFile(valDistance,valGite,valTangage,valVitesse);
    qDebug()<<"updateFile";
}

void valcapt::slotCalcTendance()
{
    TendanceGite=tendanceGite.calcTendance(valGite);
    TendanceTangage=tendanceTangage.calcTendance(valTangage);
    TendanceVitesse=tendanceVitesse.calcTendance(valVitesse);

    //qDebug()<<TendanceGite;
}




