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

void MySQL::DbSetup()   //Set up connection with database
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("databases.aii.avans.nl");
    db.setDatabaseName("mnkruith_db");
    db.setUserName("mnkruith");
    db.setPassword("Ab12345");
    if(db.open() == 1){     //Error handeling
        qDebug() << "Connection Established.\n";
    }
    else{
        qDebug() << "Cannot connect to server.\n";
        qDebug() << db.lastError();
    }
}

void MySQL::DbClose()   //Close database connection
{
    db.close();
    qDebug() << "Connection Terminated.\n";
}

MySQL::~MySQL()
{
    db.close();
    qDebug() << "Connection Terminated.\n";
}
