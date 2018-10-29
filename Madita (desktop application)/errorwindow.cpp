#include "errorwindow.h"
#include "ui_errorwindow.h"

errorwindow::errorwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::errorwindow)
{
    ui->setupUi(this);
}

errorwindow::~errorwindow()
{
    delete ui;
}
