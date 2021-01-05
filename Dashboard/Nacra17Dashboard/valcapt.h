#ifndef VALCAPT_H
#define VALCAPT_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QTimer>

#include <QDate>
#include <QTime>

#include "socketdatareceiver.h"
#include "memo.h"
#include "tendance.h"


class valcapt:public QObject
{
    Q_OBJECT


    Q_PROPERTY(float getvalTangage READ getvalTangage CONSTANT)
    Q_PROPERTY(float getvalGite READ getvalGite CONSTANT)
    Q_PROPERTY(float getvalVitesse READ getvalVitesse CONSTANT)

    Q_PROPERTY(int getTendanceTangage READ getTendanceTangage CONSTANT)
    Q_PROPERTY(int getTendanceGite READ getTendanceGite CONSTANT)
    Q_PROPERTY(int getTendanceVitesse READ getTendanceVitesse CONSTANT)

    Q_PROPERTY(float getvalTangageMax READ getvalTangageMax CONSTANT)
    Q_PROPERTY(float getvalTangageMin READ getvalTangageMin CONSTANT)
    Q_PROPERTY(float getvalGiteMax READ getvalGiteMax CONSTANT)
    Q_PROPERTY(float getvalGiteMin READ getvalGiteMin CONSTANT)

    Q_PROPERTY(bool getOnTraining READ getOnTraining CONSTANT)
    // 1) ----- ajout capteur : Q_PROPERTY(float get<nom_val_nouv_capt> READ <getnom_val_nouv_capt> ) -----

    //Q_PROPERTY(float getvalCapt_Supp_1 READ getvalCapt_Supp_1 ) //A décommenter si utilisé
    //Q_PROPERTY(float getvalCapt_Supp_2 READ getvalCapt_Supp_2 ) //A décommenter si utilisé

    //-----



public:
    valcapt(QObject *parent = nullptr);

    QTimer timerCapteur;
    QTimer timerMemo ;
    QTimer timerSimuMeter;
    QTimer timerTendance ;



    float deltaTMemo; //fréquence de memorisation en ms
    float deltaTAquisition;
    
    float getvalTangage();
    float getvalGite();
    float getvalVitesse();
    float getvalDistance();


    float getMemoValTangage();
    float getMemoValGite();
    float getMemoValVitesse();
    float getMemoValDistance();

    int getTendanceTangage();
    int getTendanceGite();
    int getTendanceVitesse();

    float getvalTangageMax();
    float getvalTangageMin();
    float getvalGiteMax();
    float getvalGiteMin();

    bool getOnTraining();

    memo memorisation;
    tendance tendanceGite;
    tendance tendanceTangage;
    tendance tendanceVitesse;

    bool onTraining; // variable détailant si un entraienement est en cours ou non

    // 2) ----- ajout capteur : float get<nom_val_nouv_capt>(); -----

    //float getvalCapt_Supp_1(); //A décommenter si utilisé
    //float getvalCapt_Supp_2(); //A décommenter si utilisé

    //-----

    Q_INVOKABLE void initValTangageMax(float);
    Q_INVOKABLE void initValTangageMin(float);
    Q_INVOKABLE void initValGiteMax(float);
    Q_INVOKABLE void initValGiteMin(float);

    Q_INVOKABLE void initDeltaTMemo(float);//temps de mémorisation des données en ms[A PARAMETER]
    Q_INVOKABLE void initDeltaTAquisition(float);//temps d'aquisition des données en ms[A PARAMETER]

    //Q_INVOKABLE void initNbMetreMoy(float);
    //Q_INVOKABLE void initNbIntervalMetreMoy(float);
//    Q_INVOKABLE void initNbCaseTabMoy(float, float);

    Q_INVOKABLE void lauchStopTraining();//lancement du programme d'entrainement (mémorisation des données)


public slots:

   void init();
   void start();

   void updateTangage();
   void updateGite();
   void updateVitesse();
   void updateDistance();

   //void addValueTabMoy();


   void slotUpdateFile();
   void slotCalcTendance();
   
   

   // 3) ----- ajout capteur : void update<nom_val_nouv_capt>(); -----

   //void updateCapt_Supp_1(); //A décommenter si utilisé
   //void updateCapt_Supp_2(); //A décommenter si utilisé

   //-----

private:

   SocketDataReceiver receiverTangage;
   SocketDataReceiver receiverGite;
   SocketDataReceiver receiverVitesse;
   SocketDataReceiver receiverDistance;



   

   // 4) ----- ajout capteur : void receiver<nom_val_nouv_capt>(); -----

   //SocketDataReceiver receiverCapt_Supp_1; //A décommenter si utilisé (65435) ;
   //SocketDataReceiver receiverCapt_Supp_2; //A décommenter si utilisé (65436) ;

   //-----

   float valTangage;
   float valGite;
   float valVitesse;
   float valDistance;

   float MemoValTangage;
   float MemoValGite;
   float MemoValVitesse;
   float MemoValDistance;

   int TendanceTangage;
   int TendanceGite;
   int TendanceVitesse;


    float valTangageMax;
    float valTangageMin;
    float valGiteMax;
    float valGiteMin;

    float nbMetreMoy;
    float nbIntervalMetreMoy;

    float valVitesseMoy;

   // 5) ----- ajout capteur : val<nom_val_nouv_capt>; -----

   //float valCapt_Supp_1; //A décommenter si utilisé
   //float valCapt_Supp_2; //A décommenter si utilisé

   //-----



};






#endif // VALCAPT_H
