#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "trendwindow.h"
#include "compass.h"
#include "mysql.h"

#include <QPlainTextEdit>
#include <QTimer>
#include <QTime>
#include <QtSql>

#include <QGraphicsView>
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Test1.DbSetup();    //Connect to the database
    setUpCompass();     //Draw the compass on the window
    init = 0;           //Variable to make sure some functions are only used once

    timer_1s = new QTimer(this);     //Update the values once every minute
    connect(timer_1s, SIGNAL(timeout()), this, SLOT(updateValues()));
    timer_1s->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
    Test1.DbClose();
}

void MainWindow::setBackgroundImage(QString weather){   //Sets the background image for the mainWindow
    QString path = ":/Images/images/";
    path += weather;
    QPixmap bkgnd(path);
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

void MainWindow::updateValues(){    //Updates all values on the mainWindow

    QSqlQuery Temperature;
    Temperature.prepare("SELECT Temperature FROM tblsensorvalue WHERE IDWeatherStation = :location");  //Select last known temperature value
    Temperature.bindValue(":location", (ui->Location->currentIndex() + 1));
    Temperature.exec();
    Temperature.last();
    QString temperature = QString::number(Temperature.value(0).toDouble());     //Updates the temperature variable

    QSqlQuery Humidity;
    Humidity.prepare("SELECT Humidity FROM tblsensorvalue WHERE IDWeatherStation = :location");    //Select last known humidity value
    Humidity.bindValue(":location", (ui->Location->currentIndex() + 1));
    Humidity.exec();
    Humidity.last();
    QString humidity = QString::number(Humidity.value(0).toInt());       //Updates the humidity variable

    QSqlQuery WindDirection;
    WindDirection.prepare("SELECT Wind_Direction FROM tblsensorvalue WHERE IDWeatherStation = :location");  //Select last known wind direction value
    WindDirection.bindValue(":location", (ui->Location->currentIndex() + 1));
    WindDirection.exec();
    WindDirection.last();
    QString windDirection = WindDirection.value(0).toString();           //Updates the wind direction variable

    QSqlQuery WindSpeed;
    WindSpeed.prepare("SELECT Wind_Speed FROM tblsensorvalue WHERE IDWeatherStation = :location");  //Select last known wind speed value
    WindSpeed.bindValue(":location", (ui->Location->currentIndex() + 1));
    WindSpeed.exec();
    WindSpeed.last();
    QString windSpeed = QString::number(WindSpeed.value(0).toDouble());   //Updates the wind speed variable

    if(((temperature == nullptr) || (humidity == nullptr) || (windDirection == nullptr) || (windSpeed == nullptr)) && (init == 0)){  //If there is a NULL value give an error prompt
        errorwindow = new class errorwindow(this);
        errorwindow->show();
        init = 1;
    }

    ui->temp->setText(temperature + " " + "℃");   //Show values in gui
    ui->humi->setText(humidity + " " + "%");
    ui->windspeed->setText(windSpeed + " " + "m/s");

    if(temperature > 20){                         //Sets background image according to the weather
       setBackgroundImage("sunny.jpg");
    }
    else if(windSpeed > 4){
        setBackgroundImage("cold.jpg");
    }
    else if(humidity > 50){
        setBackgroundImage("rainy.jpg");
    }
    else{
        setBackgroundImage("cold.jpg");
    }

    //windDirection = 'S';

    if(windDirection != nullptr){
        updateCompass(windDirection);
    }

}

void MainWindow::on_trendButton_clicked()   //Opens the trend window
{
    trendwindow = new trendWindow(this);
    trendwindow->show();
}

void MainWindow::setUpCompass(){    //Draws compass on the mainWindow
    QGraphicsScene* scene = new QGraphicsScene(0,0,190,190,ui->graphicsView);
    Compass* comp = new Compass;

    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(Qt::black);
    scene->addItem(comp);

    ui->graphicsView->show();
}

void MainWindow::updateCompass(QString direction){   //Updates the direction the compass is pointing depending on the wind direction
    QGraphicsScene* scene = new QGraphicsScene(0,0,190,190,ui->graphicsView);
    Compass* compass = new Compass;
    QPen pen;

    pen.setWidth(6);

    scene->setBackgroundBrush(Qt::black);
    scene->addItem(compass);
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
