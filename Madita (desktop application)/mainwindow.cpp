#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "trendwindow.h"
#include "compass.h"

#include "mysql.h"
#include <QPlainTextEdit>
#include <QTimer>
#include <QTime>
#include <QtDebug>
#include <QtSql>

#include <QGraphicsView>
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Test1.DbSetup();
    setUpCompass();
    init = 0;

    timer_1m = new QTimer(this);
    connect(timer_1m, SIGNAL(timeout()), this, SLOT(updateValues()));
    timer_1m->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setBackgroundImage(QString weather){
    QString path = ":/Images/images/";
    path += weather;
    QPixmap bkgnd(path);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

void MainWindow::updateValues(){

    QSqlQuery tempe("SELECT Temperature FROM tblsensorvalue");  //Select last known temperature value
    tempe.last();
    QString temp = QString::number(tempe.value(0).toDouble());

    QSqlQuery humid("SELECT Humidity FROM tblsensorvalue");    //Select last known humidity value
    humid.last();
    QString humi = QString::number(humid.value(0).toInt());

    QSqlQuery windd("SELECT Wind_Direction FROM tblsensorvalue");  //Select last known wind direction value
    windd.last();
    QString windDirection = windd.value(0).toString();

    QSqlQuery wSpeed("SELECT Wind_Speed FROM tblsensorvalue");  //Select last known wind speed value
    wSpeed.last();
    QString speed = QString::number(wSpeed.value(0).toDouble());

    if(((temp == nullptr) || (humi == nullptr) || (windDirection == nullptr) || (speed == nullptr)) && (init == 0)){  //If there is a NULL value give an error prompt
        errorwindow = new class errorwindow(this);
        errorwindow->show();
        init = 1;
    }

    ui->temp->setText(temp + " " + "℃");   //Show values in gui
    ui->humi->setText(humi + " " + "%");
    ui->windspeed->setText(speed + " " + "m/s");

    if(temp > 20){
       setBackgroundImage("sunny.jpg");
    }
    else if(speed > 4){
        setBackgroundImage("cold.jpg");
    }
    else if(humi > 50){
        setBackgroundImage("rainy.jpg");
    }
    else{
        setBackgroundImage("cold.jpg");
    }

    if(windDirection != nullptr){
        updateCompass(windDirection);
    }

}

void MainWindow::on_trendButton_clicked()   //Open trend window
{
    trendwindow = new trendWindow(this);
    trendwindow->show();
}

void MainWindow::setUpCompass(){
    QGraphicsScene* scene = new QGraphicsScene(0,0,190,190,ui->graphicsView);
    Compass* comp = new Compass;

    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(Qt::black);
    scene->addItem(comp);

    ui->graphicsView->show();
}

void MainWindow::updateCompass(QString direction){
    QGraphicsScene* scene = new QGraphicsScene(0,0,190,190,ui->graphicsView);
    Compass* comp = new Compass;
    QPen pen;

    pen.setWidth(6);

    scene->setBackgroundBrush(Qt::black);
    scene->addItem(comp);
    pen.setBrush(Qt::red);
    QGraphicsLineItem* item = scene->addLine(96,95,80,30,pen);
    item->setTransformOriginPoint(QPoint(96,95));

    if(direction == "N"){
        item->setRotation(13);
    }
    if(direction == "NW"){
        item->setRotation(58);
    }
    if(direction == "W"){
        item->setRotation(103);
    }
    if(direction == "SW"){
        item->setRotation(148);
    }
    if(direction == "S"){
        item->setRotation(193);
    }
    if(direction == "SE"){
        item->setRotation(238);
    }
    if(direction == "E"){
        item->setRotation(282);
    }
    if(direction == "NE"){
        item->setRotation(327);
    }

    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();

}
