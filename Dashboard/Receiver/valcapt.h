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
    float getvalBoussole();
    float getvalAccelero();



    // 2) ----- ajout capteur : float get<nom_val_nouv_capt>(); -----

    //float getvalCapt_Supp_1(); //A décommenter si utilisé
    //float getvalCapt_Supp_2(); //A décommenter si utilisé

    //-----

    int getcptFile();
    QString fileName = "D:/TRAVAIL/Polytech/PFE/Memorisation/memoTraining ";
    QFile memoFile;
    QTextStream memoWrite;

    float getTimeMemo();

public slots:
   void updateGPS_Lat();
   void updateGPS_Lon();
   void updateTime();
   void updateBoussole();
   void updateAccelero();
   void initFile();
   void updateFile();
   void updateTimeMemo();

   // 3) ----- ajout capteur : void update<nom_val_nouv_capt>(); -----

   //void updateCapt_Supp_1(); //A décommenter si utilisé
   //void updateCapt_Supp_2(); //A décommenter si utilisé

   //-----




private:
   SocketDataReceiver receiverBoussole;//(65432 ) ;
   SocketDataReceiver receiverGPS_Lat;//(65431) ;
   SocketDataReceiver receiverGPS_Lon;
   SocketDataReceiver receiverTime;
   SocketDataReceiver receiverAccelero;//(65434) ;

   // 4) ----- ajout capteur : void receiver<nom_val_nouv_capt>(); -----

   //SocketDataReceiver receiverCapt_Supp_1; //A décommenter si utilisé (65435) ;
   //SocketDataReceiver receiverCapt_Supp_2; //A décommenter si utilisé (65436) ;

   //-----


   float valGPS_Lat;
   float valGPS_Lon;
   float valTime;
   float valBoussole;
   float valAccelero;


   int cptFile=0;
   int cptTraining=1;

   float valTimeMemo;

   // 5) ----- ajout capteur : val<nom_val_nouv_capt>; -----

   //float valCapt_Supp_1; //A décommenter si utilisé
   //float valCapt_Supp_2; //A décommenter si utilisé

   //-----



};






#endif // VALCAPT_H
