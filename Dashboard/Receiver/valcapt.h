#ifndef VALCAPT_H
#define VALCAPT_H

#include <QMainWindow>
#include <QObject>
#include <QtWidgets>

#include <QPushButton>
#include "socketdatareceiver.h"
#include <QSvgWidget>
#include <QGraphicsScene>

#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDate>
#include <QTime>

class valcapt:public QObject
{
    Q_OBJECT

    Q_PROPERTY(float getvalBoussole READ getvalBoussole )
    Q_PROPERTY(float getvalGPS_Lat READ getvalGPS_Lat )
    Q_PROPERTY(float getvalGPS_Lon READ getvalGPS_Lon )
    Q_PROPERTY(float getvalTime READ getvalTime )
    Q_PROPERTY(float getvalAccelero READ getvalAccelero )

    Q_PROPERTY(float getvalTangage READ getvalTangage )
    Q_PROPERTY(float getvalGite READ getvalGite )

    // 1) ----- ajout capteur : Q_PROPERTY(float get<nom_val_nouv_capt> READ <getnom_val_nouv_capt> ) -----

    //Q_PROPERTY(float getvalCapt_Supp_1 READ getvalCapt_Supp_1 ) //A décommenter si utilisé
    //Q_PROPERTY(float getvalCapt_Supp_2 READ getvalCapt_Supp_2 ) //A décommenter si utilisé

    //-----



public:
    valcapt(QObject *parent = nullptr);

    float deltaTMemo=500; //fréquence de memorisation en ms

    float getvalGPS_Lat();
    float getvalGPS_Lon();
    float getvalTime();
    float getvalBoussole();//gite
    float getvalAccelero();//tangage
    
    float getvalTangage();
    float getvalGite();



    // 2) ----- ajout capteur : float get<nom_val_nouv_capt>(); -----

    //float getvalCapt_Supp_1(); //A décommenter si utilisé
    //float getvalCapt_Supp_2(); //A décommenter si utilisé

    //-----

    int getcptFile();
    QString fileName = "./memoTraining";
    QFile memoFile;
    QTextStream memoWrite;

    float getTimeMemo();

public slots:
   void updateGPS_Lat();
   void updateGPS_Lon();
   void updateTime();
   void updateBoussole();
   void updateAccelero();

   void updateTangage();
   void updateGite();
   
   
   

   // 3) ----- ajout capteur : void update<nom_val_nouv_capt>(); -----

   //void updateCapt_Supp_1(); //A décommenter si utilisé
   //void updateCapt_Supp_2(); //A décommenter si utilisé

   //-----

   void initFile();
   void updateFile();
   void updateTimeMemo();



private:
   SocketDataReceiver receiverBoussole;
   SocketDataReceiver receiverGPS_Lat;//(65431) ;
   SocketDataReceiver receiverGPS_Lon;
   SocketDataReceiver receiverTime;
   SocketDataReceiver receiverAccelero;//(65434) ;

   SocketDataReceiver receiverTangage;//(65432 )
   SocketDataReceiver receiverGite;//(65434) ;
   

   // 4) ----- ajout capteur : void receiver<nom_val_nouv_capt>(); -----

   //SocketDataReceiver receiverCapt_Supp_1; //A décommenter si utilisé (65435) ;
   //SocketDataReceiver receiverCapt_Supp_2; //A décommenter si utilisé (65436) ;

   //-----


   float valGPS_Lat=0;
   float valGPS_Lon=0;
   float valTime=0;
   float valBoussole=0;
   float valAccelero=0;

   float valTangage=0;
   float valGite=0;


   int cptFile=0;
   int cptTraining=1;

   float valTimeMemo;

   // 5) ----- ajout capteur : val<nom_val_nouv_capt>; -----

   //float valCapt_Supp_1; //A décommenter si utilisé
   //float valCapt_Supp_2; //A décommenter si utilisé

   //-----



};






#endif // VALCAPT_H
