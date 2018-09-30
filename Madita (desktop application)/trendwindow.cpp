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
    ui->enterNum -> setInputMask("999");
    ui->enterNum->setText("10");
    QPixmap reloadBut("C:/Users/Madita/Documents/BU/Madita (desktop application)/WeatherstationApp/recources");
    ui->reload->setIcon(reloadBut);
    //ui->enterNum->setValidator(( new QIntValidator(1, 365, this)));
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
                       "WHERE ID <= :periodOfTime AND IDWeatherStation = :location");

    trendTable.bindValue(":periodOfTime", trendWindow::periodOfTime);                                     //fill in the 'period of time' variable from the query with the variable from the class
    trendTable.bindValue(":location", trendWindow::location);
    trendTable.exec();                                                                                    //execute the query
    trendModel->setQuery(trendTable);                                                                     //fill the model with the results from the query
    ui->tableView->setModel(trendModel);                                                                  //fill the table with the results
}

void trendWindow::loadGraph(){
    checkInput();
    QSqlQuery trendGraph;
    QSqlQuery countGraph;
    int amount, j =0;
    ui->trendGraph->clearGraphs();

    // get data:

    countGraph.prepare("SELECT COUNT(Temperature) FROM tblsensorvalue "
                       "WHERE IDWeatherStation = :location AND ID <= :periodOfTime");
    countGraph.bindValue(":location", trendWindow::location);
    countGraph.bindValue(":periodOfTime", trendWindow::periodOfTime);
    countGraph.exec();
    countGraph.next();
    amount = countGraph.value(0).toInt();

    QVector<double> x(amount + 2), y(amount + 2); // initialize with entries 0..100
    for (int i=0; i<amount +2; i++)
    {
      x[i] = i;
      trendGraph.prepare("SELECT Temperature, Humidity, Wind_Speed, Wind_Direction FROM tblsensorvalue "
                         "WHERE ID = :periodID AND IDWeatherStation = :location");
      trendGraph.bindValue(":periodID", i + 1);
      trendGraph.bindValue(":location", trendWindow::location);
      trendGraph.exec();
      if(trendGraph.next()){
          y[j] = trendGraph.value(ui->measurement->currentIndex()).toInt();   // show the selected values
          j++;
      }
    }

    // create graph and assign data to it:
    ui->trendGraph->addGraph();
    ui->trendGraph->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->trendGraph->xAxis->setLabel("Period of time");
    ui->trendGraph->yAxis->setLabel("Measurements");
    // set axes ranges:
    ui->trendGraph->graph(0)->rescaleAxes();
    ui->trendGraph->replot();

}

void trendWindow::on_reload_clicked()
{
    loadTable();
    loadGraph();
}
