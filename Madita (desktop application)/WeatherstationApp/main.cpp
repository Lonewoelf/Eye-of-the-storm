#include "mainwindow.h"
#include <QApplication>
#include "mysql.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MySQL Test1;
    Test1.DbSetup();
    Test1.PrintDB();
    Test1.~MySQL();
    w.show();

    return a.exec();
}
