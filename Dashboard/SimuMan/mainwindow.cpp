#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    //boutton test
//    m_button = new QPushButton("Test",this);
//    m_button->setFont(QFont("Comic Sans MS", 14));
//    m_button->setCursor(Qt::PointingHandCursor);
//    m_button->move(60, 50);

//    //test slide
//    m_slider = new QSlider(Qt::Horizontal, this);
//    m_slider->setGeometry(800, 60, 150, 20);

//    //test LCD
//    m_lcd = new QLCDNumber(this);
//    m_lcd->setSegmentStyle(QLCDNumber::Flat);
//    m_lcd->move(800, 20);

//    QObject::connect(m_slider, SIGNAL(valueChanged(int)), m_lcd, SLOT(display(int))) ;

//    //test text
//    m_text = new QLabel("Test",this);
//    m_text->move(800,30);

    //Envoie de données
ValVitesse = new servervitesse(65431,this);
ValTangage = new servertangage(65434,this);
ValGite = new servergite(65435,this);

    //Simu vitesse
label_vitesse = new QLabel("Vitesse",this);
label_vitesse->setGeometry(0, 0,50,50);

slider_vitesse = new QSlider(Qt::Horizontal, this);
slider_vitesse->setGeometry(0, 50, 300, 40);
slider_vitesse->setMaximum(120);

LCD_vitesse = new QLCDNumber(this);
LCD_vitesse->setSegmentStyle(QLCDNumber::Flat);
LCD_vitesse->move(200, 20);

QObject::connect(slider_vitesse, SIGNAL(valueChanged(int)), LCD_vitesse, SLOT(display(int))) ;
QObject::connect(slider_vitesse, SIGNAL(valueChanged(int)), this, SLOT(update_val_vitesse())) ;

//Simu tangage
label_tangage = new QLabel("Tangage",this);
label_tangage->setGeometry(0, 100,50,50);

slider_tangage = new QSlider(Qt::Horizontal, this);
slider_tangage->setGeometry(0, 150, 300, 40);
slider_tangage->setMaximum(360);

LCD_tangage = new QLCDNumber(this);
LCD_tangage->setSegmentStyle(QLCDNumber::Flat);
LCD_tangage->move(200, 120);

QObject::connect(slider_tangage, SIGNAL(valueChanged(int)), LCD_tangage, SLOT(display(int))) ;
QObject::connect(slider_tangage, SIGNAL(valueChanged(int)), this, SLOT(update_val_tangage())) ;

//Simu gite
label_gite = new QLabel("Gite",this);
label_gite->setGeometry(0, 200,50,50);

slider_gite = new QSlider(Qt::Horizontal, this);
slider_gite->setGeometry(0, 250, 300, 40);
slider_gite->setMaximum(360);

LCD_gite = new QLCDNumber(this);
LCD_gite->setSegmentStyle(QLCDNumber::Flat);
LCD_gite->move(200, 220);

QObject::connect(slider_gite, SIGNAL(valueChanged(int)), LCD_gite, SLOT(display(int))) ;
QObject::connect(slider_gite, SIGNAL(valueChanged(int)), this, SLOT(update_val_gite())) ;

//envoie des valeurs
connect(slider_vitesse, SIGNAL(valueChanged(int)), ValVitesse, SLOT(update(int))) ;
connect(slider_tangage, SIGNAL(valueChanged(int)), ValTangage, SLOT(update(int))) ;
connect(slider_gite, SIGNAL(valueChanged(int)), ValGite, SLOT(update(int))) ;

}



void MainWindow::update_val_vitesse()
{
    val_vitesse=slider_vitesse->value();
    qDebug()<<"VITESSE "<<val_vitesse;
}

void MainWindow::update_val_tangage()
{
    val_tangage=slider_tangage->value();
    qDebug()<<"TANGAGE "<<val_tangage;
}

void MainWindow::update_val_gite()
{
    val_gite=slider_gite->value();
    qDebug()<<"GITE "<<val_gite;
}



MainWindow::~MainWindow()
{
    delete ui;
}
