#include <QCoreApplication>
#include "mysql.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MySQL Test1;
    Test1.DbSetup();
    Test1.PrintDB();
    Test1.~MySQL();

    return a.exec();
}
