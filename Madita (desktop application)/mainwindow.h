#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "trendwindow.h"
#include "mysql.h"
#include <QtSql/qsqldatabase.h>
#include <QtSql/qtsqlglobal.h>
#include <QtSql>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    //test
    int testTemp[9] ={20, 30, 15, -4, 3, 2, 45, 99, 23};
    int testHumi[9] ={1, 2, 3, 4, 5, 6, 7, 8, 9};
    char testWind[9] ={'W', 'S', 'N', 'E', 'S', 'W', 'N', 'S', 'E'};
    int testSpeed[9] ={3, 4, 3, 4, 5, 7, 8, 1, 2};


public slots:
    void updateValues();

private slots:
    void on_trendButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer_1m;
    int value = 0;
    MySQL Test1;
    trendWindow *trendwindow;
};


#endif // MAINWINDOW_H
