#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Envoie de données
    ValTangage = new servertangage(65430,this);
    ValGite = new servergite(65431,this);
    ValVitesse = new servervitesse(65432,this);
    ValDist = new serverdistance(65433,this);



    //Simu vitesse
    label_vitesse = new QLabel("Vitesse (en nd) :",this);
    label_vitesse->setGeometry(0, 0,150,50);

    slider_vitesse = new QSlider(Qt::Horizontal, this);
    slider_vitesse->setGeometry(0, 50, 300, 40);
    slider_vitesse->setMinimum(0);
    slider_vitesse->setMaximum(120000);

    LCD_vitesse = new QLCDNumber(this);
    LCD_vitesse->setSegmentStyle(QLCDNumber::Flat);
    LCD_vitesse->move(200, 20);

    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(update_val_vitesse())) ;

    //Simu tangage
    label_tangage = new QLabel("Tangage (en °) :",this);
    label_tangage->setGeometry(0, 100,150,50);

    slider_tangage = new QSlider(Qt::Horizontal, this);
    slider_tangage->setGeometry(0, 150, 300, 40);
    slider_tangage->setMinimum(-180000);
    slider_tangage->setMaximum(180000);
    slider_tangage->setSingleStep(1);

    LCD_tangage = new QLCDNumber(this);
    LCD_tangage->setSegmentStyle(QLCDNumber::Flat);
    LCD_tangage->move(200, 120);

    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(update_val_tangage())) ;

    //Simu gite
    label_gite = new QLabel("Gite (en °) :",this);
    label_gite->setGeometry(0, 200,150,50);

    slider_gite = new QSlider(Qt::Horizontal, this);
    slider_gite->setGeometry(0, 250, 300, 40);
    slider_gite->setMinimum(-180000);
    slider_gite->setMaximum(180000);
    slider_gite->setSingleStep(1);

    LCD_gite = new QLCDNumber(this);
    LCD_gite->setSegmentStyle(QLCDNumber::Flat);
    LCD_gite->move(200, 220);

    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(update_val_gite())) ;

    //simu disatnce
    LCD_distance = new QLCDNumber(this);
    LCD_distance->setSegmentStyle(QLCDNumber::Flat);
    LCD_distance->move(200, 320);

    label_distance = new QLabel("Distance (en m) :",this);
    label_distance->setGeometry(0, 300,150,50);

    QObject::connect(&timer, SIGNAL(timeout()),this, SLOT(update_val_distance()));


    //envoie des valeurs

    timer.start(1);

}

void MainWindow::update_val_distance()
{
    float vit_kmpms=0.539957*val_vitesse/3600;
    val_distance= vit_kmpms+val_distance;
    //qDebug()<<"DISTANCE "<<val_distance;
    LCD_distance->display(val_distance);
    ValDist->update(val_distance);
}


void MainWindow::update_val_vitesse()
{
    val_vitesse=((float)slider_vitesse->value())/1000;
    //qDebug()<<"VITESSE "<<val_vitesse;
    LCD_vitesse->display(val_vitesse);
    ValVitesse->update(val_vitesse);
}

void MainWindow::update_val_tangage()
{
    val_tangage=((float)slider_tangage->value())/1000;
    //qDebug()<<"TANGAGE "<<val_tangage;
    LCD_tangage->display(val_tangage);
    ValTangage->update(val_tangage);
}

void MainWindow::update_val_gite()
{
    val_gite=((float)slider_gite->value())/1000;
    //qDebug()<<"GITE "<<val_gite;

    LCD_gite->display(val_gite);
    ValGite->update(val_gite);
}



MainWindow::~MainWindow()
{
    delete ui;
}
