#include "trendwindow.h"
#include "ui_trendwindow.h"

trendWindow::trendWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::trendWindow)
{
    ui->setupUi(this);
}

trendWindow::~trendWindow()
{
    delete ui;
}
