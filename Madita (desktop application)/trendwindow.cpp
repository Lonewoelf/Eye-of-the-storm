#include "trendwindow.h"
#include "ui_trendwindow.h"
#include <QtSql/qsqldatabase.h>
#include <QtSql/qtsqlglobal.h>
#include <QtSql>
#include <QDebug>

trendWindow::trendWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::trendWindow)
{
    ui->setupUi(this);
    ui->enterNum -> setInputMask("999");   //Set input mask to a max of 999, digits only
    ui->enterNum->setText("10");           //Set default input value to 10
    //ui->enterNum->setValidator(( new QIntValidator(1, 365, this)));

    QPixmap bkgnd(":/Images/images/trendBG.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

trendWindow::~trendWindow()
{
    delete ui;
}

void trendWindow::checkInput(){

    QSqlQuery id("SELECT ID FROM tblsensorvalue");                  //Get highest id from the database
    id.last();
    int idNum = (id.value(0).toInt());
    int enteredValue = ui->enterNum->text().toInt();                //Get number from line edit

    if(enteredValue > idNum){                                       //Check entered period of time, so it is not bigger than the row count of the database
        trendWindow::periodOfTime = idNum;
    }
    else{
        trendWindow::periodOfTime = enteredValue;
    }

    trendWindow::location = ((ui->location->currentIndex()) + 1);
}
void trendWindow::loadTable()
{
    checkInput();

    QSqlQueryModel * trendModel = new QSqlQueryModel;                                                     //Create a model
    QSqlQuery trendTable;

    trendTable.prepare("SELECT Temperature, Humidity, Wind_Speed, Wind_Direction FROM tblsensorvalue "    //prepare the query
                       "WHERE IDMeasurement <= :periodOfTime AND IDWeatherStation = :location");

    trendTable.bindValue(":periodOfTime", trendWindow::periodOfTime);                                     //fill in the 'period of time' variable from the query with the variable from the class
    trendTable.bindValue(":location", trendWindow::location);
    trendTable.exec();                                                                                    //execute the query
    trendModel->setQuery(trendTable);                                                                     //fill the model with the results from the query
    ui->tableView->setModel(trendModel);                                                                  //fill the table with the results
}

void trendWindow::loadGraph(){
    QSqlQuery trendGraph;   //Create query object for trend queries
    QSqlQuery countGraph;   //Create query object for the query that counts the amount of output rows

    int amount, j =0;
    ui->trendGraph->clearGraphs();   //Delete all graphs, so the widget is blank

    // get data:

    countGraph.prepare("SELECT COUNT(Temperature) FROM tblsensorvalue "
                       "WHERE IDWeatherStation = :location AND IDMeasurement <= :periodOfTime");  //Count the amount of output rows
    countGraph.bindValue(":location", trendWindow::location);   //Fill in the variables
    countGraph.bindValue(":periodOfTime", trendWindow::periodOfTime);
    countGraph.exec();
    countGraph.next();
    amount = countGraph.value(0).toInt();

    QVector<double> x(amount), y(amount);
    for (int i=0; i<(amount); i++)
    {
      x[i] = i;
      trendGraph.prepare("SELECT Temperature, Humidity, Wind_Speed, Wind_Direction FROM tblsensorvalue "
                         "WHERE IDMeasurement = :periodID AND IDWeatherStation = :location");   //Get all values between time 0 and the max end date wanted
      trendGraph.bindValue(":periodID", i + 1);   //Fill in the variables
      trendGraph.bindValue(":location", trendWindow::location);
      trendGraph.exec();
      if(trendGraph.next()){
          y[j] = trendGraph.value(ui->measurement->currentIndex()).toInt();   // show the selected values
          j++;
      }
    }

    // Create graph and assign data to it:
    ui->trendGraph->addGraph();
    ui->trendGraph->graph(0)->setData(x, y);
    // Give the axes some labels:
    ui->trendGraph->xAxis->setLabel("Period of time");
    ui->trendGraph->yAxis->setLabel("Measurements");
    // Set axes ranges:
    ui->trendGraph->graph(0)->rescaleAxes();
    ui->trendGraph->replot();
}

void trendWindow::on_reload_clicked()   //Load graph and table when reload button is clicked
{
    loadTable();
    loadGraph();
}
