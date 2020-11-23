#ifndef VALCAPT_H
#define VALCAPT_H

#include <QMainWindow>
#include <QObject>
#include <QtWidgets>

#include <QPushButton>
#include "socketdatareceiver.h"
#include "memo.h"
#include "tendance.h"
#include <QSvgWidget>
#include <QGraphicsScene>

#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDate>
#include <QTime>

#include <QMatrix>

class valcapt:public QObject
{
    Q_OBJECT


    Q_PROPERTY(float getvalTangage READ getvalTangage )
    Q_PROPERTY(float getvalGite READ getvalGite )
    Q_PROPERTY(float getvalVitesse READ getvalVitesse )

    Q_PROPERTY(int getTendanceTangage READ getTendanceTangage )
    Q_PROPERTY(int getTendanceGite READ getTendanceGite )
    Q_PROPERTY(int getTendanceVitesse READ getTendanceVitesse )

    Q_PROPERTY(float getvalTangageMax READ getvalTangageMax )
    Q_PROPERTY(float getvalTangageMin READ getvalTangageMin )
    Q_PROPERTY(float getvalGiteMax READ getvalGiteMax )
    Q_PROPERTY(float getvalGiteMin READ getvalGiteMin )


    // 1) ----- ajout capteur : Q_PROPERTY(float get<nom_val_nouv_capt> READ <getnom_val_nouv_capt> ) -----

    //Q_PROPERTY(float getvalCapt_Supp_1 READ getvalCapt_Supp_1 ) //A décommenter si utilisé
    //Q_PROPERTY(float getvalCapt_Supp_2 READ getvalCapt_Supp_2 ) //A décommenter si utilisé

    //-----



public:
    valcapt(QObject *parent = nullptr);

    float deltaTMemo; //fréquence de memorisation en ms
    float deltaTAquisition;
    
    float getvalTangage();
    float getvalGite();
    float getvalVitesse();


    float getMemoValTangage();
    float getMemoValGite();
    float getMemoValVitesse();

    int getTendanceTangage();
    int getTendanceGite();
    int getTendanceVitesse();

    float getvalTangageMax();
    float getvalTangageMin();
    float getvalGiteMax();
    float getvalGiteMin();

    memo memorisation;
    tendance tendanceGite;
    tendance tendanceTangage;
    tendance tendanceVitesse;

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


public slots:

   void init();
   void start();

   void updateTangage();
   void updateGite();
   void updateVitesse();


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



   

   // 4) ----- ajout capteur : void receiver<nom_val_nouv_capt>(); -----

   //SocketDataReceiver receiverCapt_Supp_1; //A décommenter si utilisé (65435) ;
   //SocketDataReceiver receiverCapt_Supp_2; //A décommenter si utilisé (65436) ;

   //-----

   float valTangage;
   float valGite;
   float valVitesse;

   float MemoValTangage;
   float MemoValGite;
   float MemoValVitesse;

   int TendanceTangage;
   int TendanceGite;
   int TendanceVitesse;


    float valTangageMax;
    float valTangageMin;
    float valGiteMax;
    float valGiteMin;


   // 5) ----- ajout capteur : val<nom_val_nouv_capt>; -----

   //float valCapt_Supp_1; //A décommenter si utilisé
   //float valCapt_Supp_2; //A décommenter si utilisé

   //-----



};






#endif // VALCAPT_H
