#include "readfile.h"
#include <QDebug>
#include <QApplication>

readfile::readfile(QObject *parent):QObject(parent)
{

}

bool readfile::openFile() //méthode permettant l'ouverture du fichier
{
    memoFile.setFileName(FileUrl);//indication du nom du fichier grace à son url
   if (!memoFile.open(QIODevice::ReadOnly | QIODevice::Text)) //ouverture du fichier en mode lecture de texte
   {
       //qDebug()<<"File"<<FileUrl<<"Not Opened";
       return false;
   }
   else
   {
       //qDebug()<<"File"<<FileUrl<<" Opened";
       return true;
   }
}

void readfile::closeFile()//méthode de fermeture du fichier
{
    memoFile.close();
}

void readfile::setFileUrl(QString NewFileUrl)//méthode permettant la conversion d'un url de fichier en chemin
{
    if (NewFileUrl.contains("file:///"))
            NewFileUrl.replace("file:///","");//suppression du prefixe file:///
    //qDebug()<<"Debug SetFileUrl1"<<NewFileUrl;
    FileUrl=NewFileUrl;
    //qDebug()<<"Debug SetFileUrl2"<<FileUrl;


}

void readfile::initReading() //initialisation de la lecture du fichier
{
    //nombre de ligne de données
    openFile();
    int cpt=0;
    while(!memoFile.atEnd())
    {
        memoFile.readLine();
        cpt++;
    }
    nbDataLine=cpt-5;//on retire les 5 lignes utilisée pour le paramétrage de la lecture du fichier
    closeFile();


    //qDebug()<<"nombre ligne de donénes"<<nbDataLine;


    //date
    fileDate.setDate(readDataFile(3,0).toInt(),readDataFile(2,0).toInt(),readDataFile(2,0).toInt());//recuperation de la date inscrite sur le fichier

    //qDebug()<<"Date :"<<fileDate;

    //heure
    fileTime.setHMS(readDataFile(1,1).toInt(),readDataFile(2,1).toInt(),readDataFile(3,1).toInt());//recuperation de l'heure inscrite sur le fichier

    //qDebug()<<"Heure :"<<fileTime;

    //tempo memo (ms)

    memoTempo=readDataFile(1,2).toFloat();//recuperation de l'interval de temps entre 2 enregistrements

    //qDebug()<<"memoTempo (ms) :"<<memoTempo;

    //seuils

    //recuperation des seuils choisi par l'utilisateurs inscrits dans le fichier
    tangageSeuilMin=readDataFile(1,3).toFloat();
    tangageSeuilMax=readDataFile(2,3).toFloat();
    giteSeuilMin=readDataFile(3,3).toFloat();
    giteSeuilMax=readDataFile(4,3).toFloat();

    //qDebug()<<"min tang :"<<tangageSeuilMin;
    //qDebug()<<"max tang :"<<tangageSeuilMax;
    //qDebug()<<"min gite :"<<giteSeuilMin;
    //qDebug()<<"max gite:"<<giteSeuilMax;
}

void readfile::readFileLineData(int nLine) //méthode de récupération des données par ligne (en paramètre) avec la méthode readDataFile (on ajoute +5 à nLine pour sauter les ligne de paramétrage)
{

        //temps
    time=readDataFile(0,nLine+5).toFloat();
    //qDebug()<<"time rvrv:"<<time;
        //distance
    distance=readDataFile(1,nLine+5).toFloat();
    //qDebug()<<"distance :"<<distance;
        //tangage
    tangageVal=readDataFile(2,nLine+5).toFloat();
    //qDebug()<<"tangageVal :"<<tangageVal;
        //tend tangage
    tangageTend=readDataFile(3,nLine+5).toFloat();
    //qDebug()<<"tangageTend :"<<tangageTend;
        //gite
    giteVal=readDataFile(4,nLine+5).toFloat();
    //qDebug()<<"giteVal :"<<giteVal;
        //tend gite
    giteTend=readDataFile(5,nLine+5).toFloat();
    //qDebug()<<"giteTend :"<<giteTend;
        //vitesse
    vitesseVal=readDataFile(6,nLine+5).toFloat();
    //qDebug()<<"vitesseVal :"<<vitesseVal;
        //tend vitesse
    vitesseTend=readDataFile(7,nLine+5).toFloat();
    //qDebug()<<"vitesseTend :"<<vitesseTend;



}

void readfile::loadAllFile()//lecture du fichier en entier
{
    openFile();
    DataFile = memoFile.readAll();//lecture entier du fichier dans un QString
    closeFile();
}

QString readfile::readDataFile(int line, int colomn)//lecture des valeurs des caes du fichier
{
    listLineDataFile = DataFile.split("\n");//décomposition du QString en QStringList par ligne
    listCaseDataFile=listLineDataFile.at(colomn).split(";"); //décompostion deu QStringList en QStringList en focniton du numero de la colonne
    return listCaseDataFile.at(line);//retourne la chain de caractère correspondant au numero de la ligne
}



//------getter


float readfile::getValMemoTempo()
{
    return memoTempo;
}

float readfile::getValTangageSeuilMax()
{
    return tangageSeuilMax;
}

float readfile::getValTangageSeuilMin()
{
    return tangageSeuilMin;
}

float readfile::getValGiteSeuilMax()
{
    return giteSeuilMax;
}

float readfile::getValGiteSeuilMin()
{
    return giteSeuilMin;
}

float readfile::getValTime()
{
    return time;
}

float readfile::getValDistance()
{
    return distance;
}

float readfile::getValTangageVal()
{
    return tangageVal;
}

float readfile::getValTangageTend()
{
    return tangageTend;
}

float readfile::getValGiteVal()
{
    return giteVal;
}

float readfile::getValGiteTend()
{
    return giteTend;
}

float readfile::getValVitesseVal()
{
    return vitesseVal;
}

float readfile::getValVitesseTend()
{
    return vitesseTend;
}

int readfile::getNbDataLine()
{
    return nbDataLine;

}






