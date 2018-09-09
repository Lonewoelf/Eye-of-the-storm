#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPlainTextEdit>
#include <QTimer>
#include <QTime>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer_1m = new QTimer(this);
    connect(timer_1m, SIGNAL(timeout()), this, SLOT(updateValues()));
    timer_1m->start(60000);
    qDebug() << "Timer started!";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateValues(){
    qDebug() << "Update";
    QString temp = QString::number(testTemp[value]);
    QString humi = QString::number(testHumi[value]);
    QString wind(testWind[value]);
    QString speed = QString::number(testSpeed[value]);
    ui->temperature->setPlainText(temp + " " + "℃");
    ui->humidity->setPlainText(humi + " " + "%");
    ui->windDirection->setPlainText(wind);
    ui->windSpeed->setPlainText(speed);
    if(value < 8){
        value++;
    }
    else{
        value = 0;
    }
}
