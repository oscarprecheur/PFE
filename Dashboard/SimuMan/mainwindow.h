#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include <QLCDNumber>
#include <QLabel>
#include <QFont>
#include <QDebug>
#include "servervitesse.h"
#include "servertangage.h"
#include "servergite.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void update_val_vitesse();
    void update_val_tangage();
    void update_val_gite();


private:
    Ui::MainWindow *ui;
//    QPushButton *m_button;
//    QSlider *m_slider;
//    QLCDNumber *m_lcd;
//    QLabel *m_text;

QSlider *slider_vitesse;
QSlider *slider_tangage;
QSlider *slider_gite;

QLabel *label_vitesse;
QLabel *label_tangage;
QLabel *label_gite;

QLCDNumber *LCD_vitesse;
QLCDNumber *LCD_tangage;
QLCDNumber *LCD_gite;

servervitesse *ValVitesse;
servertangage *ValTangage;
servergite *ValGite;

int val_vitesse=0;
int val_tangage=0;
int val_gite=0;




};
#endif // MAINWINDOW_H
