#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "trendwindow.h"
#include "mysql.h"
#include <QPlainTextEdit>
#include <QTimer>
#include <QTime>
#include <QtDebug>
#include <QtSql>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Test1.DbSetup();


    timer_1m = new QTimer(this);
    connect(timer_1m, SIGNAL(timeout()), this, SLOT(updateValues()));
    timer_1m->start(2000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateValues(){

    QSqlQuery tempe("SELECT Temperature FROM tblsensorvalue");
    tempe.last();
    QString temp = QString::number(tempe.value(0).toDouble());

    QSqlQuery humid("SELECT Humidity FROM tblsensorvalue");
    humid.last();
    QString humi = QString::number(humid.value(0).toInt());

    QSqlQuery windd("SELECT Wind_Direction FROM tblsensorvalue");
    windd.last();
    QString windDirection = windd.value(0).toString();

    QSqlQuery wSpeed("SELECT Wind_Speed FROM tblsensorvalue");
    wSpeed.last();
    QString speed = QString::number(wSpeed.value(0).toDouble());

    ui->temperature->setPlainText(temp + " " + "℃");
    ui->humidity->setPlainText(humi + " " + "%");
    ui->windDirection->setPlainText(windDirection);
    ui->windSpeed->setPlainText(speed + " " + "m/s");

}

void MainWindow::on_trendButton_clicked()
{
    trendwindow = new trendWindow(this);
    trendwindow->show();
}
