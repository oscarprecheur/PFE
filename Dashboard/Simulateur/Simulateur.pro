QT  += core
QT  += network
QT  -= gui

TARGET = QTcpSocket
CONFIG  += console
CONFIG  -= app_bundle

TEMPLATE = app

SOURCES += \
        ServerAccelero.cpp \
        ServerBoussole.cpp \
        ServerDirVent.cpp \
        ServerGPS.cpp \
        ServerVitVent.cpp \
        main.cpp


HEADERS += \
    ServerAccelero.h \
    ServerBoussole.h \
    ServerDirVent.h \
    ServerGPS.h \
    ServerVitVent.h
