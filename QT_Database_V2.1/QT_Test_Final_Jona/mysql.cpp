#include "mysql.h"
#include <QDebug>
#include <iostream>
#include <QtSql/qsqldatabase.h>
#include <QtSql/qtsqlglobal.h>
#include <QtSql>
#include <qtextstream.h>
#include <QtCore/QCoreApplication>
#include <string>

MySQL::MySQL()
{
}

void MySQL::DbSetup()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("Jonathan-Laptop");
    db.setDatabaseName("dweerstation_db");
    db.setUserName("Test");
    db.setPassword("1234");
    if(db.open() == 1){
        std::cout << "Connection Established.\n";
    }
    else{
        std::cout << "Cannot conntect to server.\n";
        qDebug() << db.lastError();
    }
}

void MySQL::PrintDB(){
    QSqlQuery query( "SELECT * FROM tblsensorvalue");
    while (query.next()) {
        int Id = query.value(0).toInt();
        std::cout << Id << " | ";
        Id = query.value(1).toInt();
        std::cout << Id << " | ";
        Id = query.value(2).toInt();
        std::cout << Id << " | ";
        double temp = query.value(3).toDouble();
        std::cout << temp << " | ";
        Id = query.value(4).toInt();
        std::cout << Id << " | ";
        double windspeed = query.value(5).toDouble();
        std::cout << windspeed << " | ";
        QString windDirection = query.value(6).toString();
        qDebug() << windDirection << endl;
        //String word = query.value(1).toString();
       // std::cout << (QString( "%1\t%2\n").arg(Id).arg( word));
    }

}

MySQL::~MySQL()
{
    db.close();
    std::cout << "Connection Terminated.\n";
}
