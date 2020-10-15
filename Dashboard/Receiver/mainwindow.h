#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QtWidgets>
#include <QPushButton>
#include "socketdatareceiver.h"
#include <QSvgWidget>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    float getvalGPS();
    float getvalBoussole();
    float getvalVitVent();
    float getvalDirVent();
    float getvalAccelero();

public slots:
   void updateGPS();
   void updateBoussole();
   void updateVitVent();
   void updateDirVent();
   void updateAccelero();

   void showvalueGPS();
   void showvalueBoussole();
   void showvalueVitVent();
   void showvalueDirVent();
   void showvalueAccelero();

   void annonce();




private:
    Ui::MainWindow *ui;

    QPushButton *boutonBoussole;
    QPushButton *boutonGPS;
    QPushButton *boutonVitVent;
    QPushButton *boutonDirVent;
    QPushButton *boutonAccelero;
    //QLabel *valshowGPS;

    SocketDataReceiver receiverBoussole;//(65432 ) ;
    SocketDataReceiver receiverGPS;//(65433) ;
    SocketDataReceiver receiverAccelero;//(65434) ;
    SocketDataReceiver receiverDirVent;//(65435) ;
    SocketDataReceiver receiverVitVent;//(65436) ;

    QSvgWidget *cadran_boussole;
    QSvgWidget *aiguille_boussole;
    QSvgWidget *cadran_vent;
    QSvgWidget *aiguille_vent;
    QSvgWidget *bateau_vent;
    QSvgWidget *cadran_accelero;
    QSvgWidget *fond_accelero;

    QGraphicsScene *scene_aiguille_boussole;

    QGridLayout *layout ;


    float valGPS;
    float valBoussole;
    float valAccelero;
    float valDirVent;
    float valVitVent;






};
#endif // MAINWINDOW_H
