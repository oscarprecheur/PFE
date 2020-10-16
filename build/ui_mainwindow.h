/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *Boussole;
    QLabel *GPS;
    QLabel *Accelero;
    QLabel *VitVent;
    QLabel *DirVEnt;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Boussole = new QLabel(centralwidget);
        Boussole->setObjectName(QString::fromUtf8("Boussole"));
        Boussole->setGeometry(QRect(270, 30, 151, 19));
        GPS = new QLabel(centralwidget);
        GPS->setObjectName(QString::fromUtf8("GPS"));
        GPS->setGeometry(QRect(270, 70, 261, 19));
        Accelero = new QLabel(centralwidget);
        Accelero->setObjectName(QString::fromUtf8("Accelero"));
        Accelero->setGeometry(QRect(270, 120, 301, 19));
        VitVent = new QLabel(centralwidget);
        VitVent->setObjectName(QString::fromUtf8("VitVent"));
        VitVent->setGeometry(QRect(270, 170, 251, 19));
        DirVEnt = new QLabel(centralwidget);
        DirVEnt->setObjectName(QString::fromUtf8("DirVEnt"));
        DirVEnt->setGeometry(QRect(270, 230, 301, 19));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 340, 68, 19));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 30));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Boussole->setText(QCoreApplication::translate("MainWindow", "Boussole : ", nullptr));
        GPS->setText(QCoreApplication::translate("MainWindow", "GPS:", nullptr));
        Accelero->setText(QCoreApplication::translate("MainWindow", "Accelero:", nullptr));
        VitVent->setText(QCoreApplication::translate("MainWindow", "VitVent :", nullptr));
        DirVEnt->setText(QCoreApplication::translate("MainWindow", "DirVent:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
