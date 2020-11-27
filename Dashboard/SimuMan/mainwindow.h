#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include <QLCDNumber>
#include <QLabel>
#include <QFont>
#include <QDebug>
#include <QTimer>
#include "servervitesse.h"
#include "servertangage.h"
#include "servergite.h"
#include "serverdistance.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTimer timer;

public slots:
    void update_val_vitesse();
    void update_val_tangage();
    void update_val_gite();
    void update_val_distance();


private:
    Ui::MainWindow *ui;

QSlider *slider_vitesse;
QSlider *slider_tangage;
QSlider *slider_gite;

QLabel *label_vitesse;
QLabel *label_tangage;
QLabel *label_gite;
QLabel *label_distance;

QLCDNumber *LCD_vitesse;
QLCDNumber *LCD_tangage;
QLCDNumber *LCD_gite;
QLCDNumber *LCD_distance;

servervitesse *ValVitesse;
servertangage *ValTangage;
servergite *ValGite;
serverdistance *ValDist;

float val_vitesse=0;
float val_tangage=0;
float val_gite=0;
float val_distance=0;





};
#endif // MAINWINDOW_H
