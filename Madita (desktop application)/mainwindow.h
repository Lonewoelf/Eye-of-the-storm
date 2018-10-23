#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <iostream>
#include "trendwindow.h"
#include "mysql.h"
#include "compass.h"
#include "errorwindow.h"

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
    void setBackgroundImage(QString weather);
    void setUpCompass();
    void updateCompass(QString direction);


public slots:
    void updateValues();

private slots:
    void on_trendButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer_1m;
    MySQL Test1;
    Compass comp;
    trendWindow *trendwindow;
    errorwindow *errorwindow;
    int init;
};


#endif // MAINWINDOW_H
