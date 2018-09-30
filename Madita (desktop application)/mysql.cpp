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
    db.setHostName("databases.aii.avans.nl");
    db.setDatabaseName("_db");
    db.setUserName("mnkruith");
    db.setPassword("Ab12345");
    if(db.open() == 1){
        qDebug() << "Connection Established.\n";
    }
    else{
        qDebug() << "Cannot conntect to server.\n";
        qDebug() << db.lastError();
    }
}

void MySQL::DbClose()
{
    db.close();
    qDebug() << "Connection Terminated.\n";
}

MySQL::~MySQL()
{
    db.close();
    qDebug() << "Connection Terminated.\n";
}
