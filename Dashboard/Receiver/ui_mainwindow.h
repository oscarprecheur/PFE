/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        Boussole = new QLabel(centralwidget);
        Boussole->setObjectName(QStringLiteral("Boussole"));
        Boussole->setGeometry(QRect(270, 30, 151, 19));
        GPS = new QLabel(centralwidget);
        GPS->setObjectName(QStringLiteral("GPS"));
        GPS->setGeometry(QRect(270, 70, 261, 19));
        Accelero = new QLabel(centralwidget);
        Accelero->setObjectName(QStringLiteral("Accelero"));
        Accelero->setGeometry(QRect(270, 120, 301, 19));
        VitVent = new QLabel(centralwidget);
        VitVent->setObjectName(QStringLiteral("VitVent"));
        VitVent->setGeometry(QRect(270, 170, 251, 19));
        DirVEnt = new QLabel(centralwidget);
        DirVEnt->setObjectName(QStringLiteral("DirVEnt"));
        DirVEnt->setGeometry(QRect(270, 230, 301, 19));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 340, 68, 19));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 30));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        Boussole->setText(QApplication::translate("MainWindow", "Boussole : ", Q_NULLPTR));
        GPS->setText(QApplication::translate("MainWindow", "GPS:", Q_NULLPTR));
        Accelero->setText(QApplication::translate("MainWindow", "Accelero:", Q_NULLPTR));
        VitVent->setText(QApplication::translate("MainWindow", "VitVent :", Q_NULLPTR));
        DirVEnt->setText(QApplication::translate("MainWindow", "DirVent:", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
