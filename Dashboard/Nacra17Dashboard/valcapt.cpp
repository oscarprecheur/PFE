#include "valcapt.h"

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

   //initialisation tableau de mémorisation pour le calcul dynamique de la vitesse moyenne sur nbIntervalMetreMoy;
   nbIntervalMetreMoy=1;
   nbMetreMoy=1;


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
    connect(&timerCapteur, SIGNAL(timeout()),this,SLOT(updateTangage()));//à chaque fin de période de timerCapteur on updateTangage
    connect(&timerCapteur, SIGNAL(timeout()),this,SLOT(updateGite()));//à chaque fin de période de timerCapteur on updateGite
    connect(&timerCapteur, SIGNAL(timeout()),this,SLOT(updateVitesse()));//à chaque fin de période de timerCapteur on updateVitesse
    connect(&timerCapteur, SIGNAL(timeout()),this,SLOT(updateDistance()));//à chaque fin de période de timerCapteur on updateDistance
    //connect(&timerCapteur, SIGNAL(timeout()),this,SLOT(addValueTabMoy()));

    //mise à jour des valeurs de tendance
//    connect(timerCapteur, SIGNAL(timeout()),this,SLOT(updateTendanceTangage()));
//    connect(timerCapteur, SIGNAL(timeout()),this,SLOT(updateTendanceGite()));
//    connect(timerCapteur, SIGNAL(timeout()),this,SLOT(updateTendanceVitesse()));

    connect(&timerTendance, SIGNAL(timeout()),this,SLOT(slotCalcTendance()));//à chaque fin de période de timerTendance on slotCalcTendance
    //2) ----- ajout de capteur :connect(timer, SIGNAL(timeout()),this,SLOT(update<nom_val_nouv_capt>())); -----
    //connect(timer, SIGNAL(timeout()),this,SLOT(updateCapt_Supp_2())); //A décommenter si utilisé
    //connect(timer, SIGNAL(timeout()),this,SLOT(updateCapt_Supp_1())); //A décommenter si utilisé

    //-----

    //Mémorisation des données d'entrainement dans un fichier


    //Lancement des timers
    timerCapteur.start((int)deltaTAquisition);//allumage du timer d'aquisition des capteur avec la période données par l'utilisateur
    timerMemo.start((int)deltaTMemo);// valeur en msec
    timerSimuMeter.start(200);//simualtaiton metre parcouru
    timerTendance.start((int)deltaTAquisition);//allumafe du time des Tendances
}

//<<<<<<<<<<<<<<<<<<Mise à jour des valeur des capteurs>>>>>>>>>>>>>>>>>>>

void valcapt::updateTangage()//mise à jour des données tangage
{
    MemoValTangage=valTangage;//mémorisation
    if (receiverTangage.getNbByteAvailable()>0)//s'il y a des valeur à lire dans la socket correspondant au tangage
    {

    valTangage=receiverTangage.readyRead();//on execute readyRead de receiverTangage
//    qDebug()<<"valTangage"<<valTangage;
//    qDebug()<<"valTangageMEMO"<<MemoValTangage;
//    qDebug()<<"Taille"<<sizeof(valTangage);
    }
}



void valcapt::updateGite()
{
    MemoValGite=valGite;//mémorisation
    if (receiverGite.getNbByteAvailable()>0)//s'il y a des valeur à lire dans la socket correspondant à la gite
    {

    valGite=receiverGite.readyRead();//on execute readyRead de receiverGite
//    qDebug()<<"valGite"<<valGite;
//    qDebug()<<"valGiteMEMO"<<MemoValGite;
//    qDebug()<<"Taille"<<sizeof(valGite);
    }
}


void valcapt::updateVitesse()
{

    MemoValVitesse=valVitesse;//mémorisation

    if (receiverVitesse.getNbByteAvailable()>0)//s'il y a des valeur à lire dans la socket correspondant a la vitesse
    {
    valVitesse=receiverVitesse.readyRead();//on execute readyRead de receiverVitesse
    //qDebug()<<"valVitesse"<<valVitesse;
    //qDebug()<<"valVitesseMEMO"<<MemoValVitesse;
//    qDebug()<<"Taille"<<sizeof(valVitesse);
    }
}

void valcapt::updateDistance()
{

    MemoValDistance=valDistance;//mémorisation

    if (receiverDistance.getNbByteAvailable()>0)//s'il y a des valeur à lire dans la socket correspondant a la distance
    {
    valDistance=receiverDistance.readyRead();//on execute readyRead de receiverDistance
    //qDebug()<<"valDistance"<<valDistance;
    //qDebug()<<"valDistanceMEMO"<<MemoValDistance;
    //qDebug()<<"Taille"<<sizeof(valDistance);
    }
}

//void valcapt::addValueTabMoy()
//{

//    float sommeValVitesse=0;

//        for(int cpt=tabMoy.size();cpt>0;cpt--)
//        {
//            tabMoy.insert(cpt,tabMoy[cpt-1]);
//        }
//        tabMoy.insert(0,valVitesse);

//        while(tabMoy.first()-tabMoy.last()>nbMetreMoy)
//        {
//            tabMoy.erase(&tabMoy.last());
//        }
//        for(int cpt=0;cpt<tabMoy.size();cpt++)
//        {
//            sommeValVitesse=sommeValVitesse+tabMoy[cpt];
//        }

//        valVitesseMoy=sommeValVitesse/tabMoy.size();
//        qDebug()<<"val moy  "<<valVitesseMoy;
//}




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

//Les méthode Q_INVOKABLE sont des fonctions capables d'être appélées dans des composants QML, elles sont donc utilisées dans le programme de décription graphique

//ces méthode peremtte la récuperation des valeurs fourni par l'utilisateur dans l'interface de paramétrage, on initialise les variables des paramètres avec ces valeurs
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

//Q_INVOKABLE void valcapt::initNbMetreMoy(float newval)
//{
//    nbMetreMoy=newval;
//}

//Q_INVOKABLE void valcapt::initNbIntervalMetreMoy(float newval)
//{
//    nbIntervalMetreMoy=newval;
//}

Q_INVOKABLE void valcapt::lauchStopTraining() //fonction du lancement de la mémoristion apres l'appuie de l'utilisateur sur le bouton start training ou stop training
{
    if (onTraining==false)// une mémorisation n'est pas en cours -> on lance une mémorisation
    {
           memorisation.initFile(deltaTMemo,deltaTAquisition,valTangageMin,valTangageMax,valGiteMin,valGiteMax);//initialisation du ficier
           memorisation.initTimeMemo();//initialisation de la valeur du temsp
           connect(&timerMemo, SIGNAL(timeout()),this,SLOT(slotUpdateFile()));//à cahque fin de periode du timerMemo ou met à jur le fichier
           connect(&timerMemo, SIGNAL(timeout()),&memorisation,SLOT(updateTimeMemo()));//à cahque fin de periode du timerMemo on met à jour la valeur du temps actuel
           onTraining=true;//l'entrainement est maintienant en cours
    }
    else //une mémorisation est en cours -> on stop la mémorisation
    {
           memorisation.initTimeMemo();//on reinitialise la valeur de temps
           disconnect(&timerMemo, SIGNAL(timeout()),this,SLOT(slotUpdateFile()));//deconnexion des slot
           disconnect(&timerMemo, SIGNAL(timeout()),&memorisation,SLOT(updateTimeMemo()));//deconnexion des slot
           onTraining=false; //l'entrainement ,,'est pas en cours
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


void valcapt::slotUpdateFile() //slot permetant la mise à jour de fichier
{
    memorisation.updateFile(valDistance,valGite,valTangage,valVitesse,TendanceTangage,TendanceGite,TendanceVitesse);//MAJ du fichier .csv avec les nouvelles valeurs en paramètres
    //qDebug()<<"updateFile";
}

void valcapt::slotCalcTendance()//slot permettant le calcul des trendance de chaque donées
{
    TendanceGite=tendanceGite.calcTendance(valGite);
    TendanceTangage=tendanceTangage.calcTendance(valTangage);
    TendanceVitesse=tendanceVitesse.calcTendance(valVitesse);

    //qDebug()<<TendanceGite;
}




