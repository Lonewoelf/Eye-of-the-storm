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

public slots:
    void updateValues();

private slots:
    void on_trendButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer_1m;
    MySQL Test1;
    trendWindow *trendwindow;
};


#endif // MAINWINDOW_H
