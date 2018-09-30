#ifndef MYSQL_H
#define MYSQL_H

#include <QtSql/qsqldatabase.h>
#include <QtSql/qtsqlglobal.h>

class MySQL
{
public:
    MySQL();
    void DbSetup();
    void DbClose();
    virtual ~MySQL();
    QSqlDatabase db;

};

#endif // MYSQL_H
