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


    // 1) ----- ajout capteur : Q_PROPERTY(float get<nom_val_nouv_capt> READ <getnom_val_nouv_capt> ) -----

    //Q_PROPERTY(float getvalCapt_Supp_1 READ getvalCapt_Supp_1 ) //A décommenter si utilisé
    //Q_PROPERTY(float getvalCapt_Supp_2 READ getvalCapt_Supp_2 ) //A décommenter si utilisé

    //-----



public:
    valcapt(QObject *parent = nullptr);

    float deltaTMemo=250; //fréquence de memorisation en ms
    
    float getvalTangage();
    float getvalGite();
    float getvalVitesse();


    float getMemoValTangage();
    float getMemoValGite();
    float getMemoValVitesse();

    int getTendanceTangage();
    int getTendanceGite();
    int getTendanceVitesse();

    memo memorisation;
    tendance tendanceGite;
    tendance tendanceTangage;
    tendance tendanceVitesse;

    // 2) ----- ajout capteur : float get<nom_val_nouv_capt>(); -----

    //float getvalCapt_Supp_1(); //A décommenter si utilisé
    //float getvalCapt_Supp_2(); //A décommenter si utilisé

    //-----



public slots:

   void updateTangage();
   void updateGite();
   void updateVitesse();

   //tendances
   void updateTendanceTangage();
   void updateTendanceGite();
   void updateTendanceVitesse();

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

   float valTangage=0;
   float valGite=0;
   float valVitesse=0;

   float MemoValTangage=0;
   float MemoValGite=0;
   float MemoValVitesse=0;

   int TendanceTangage=1;
   int TendanceGite=1;
   int TendanceVitesse=1;





   // 5) ----- ajout capteur : val<nom_val_nouv_capt>; -----

   //float valCapt_Supp_1; //A décommenter si utilisé
   //float valCapt_Supp_2; //A décommenter si utilisé

   //-----



};






#endif // VALCAPT_H
