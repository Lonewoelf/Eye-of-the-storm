#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //test
    int testTemp[9] ={20, 30, 15, -4, 3, 2, 45, 100, 23} ;
    int testHumi[9] ={1, 2, 3, 4, 5, 6, 7, 8, 9};
    char testWind[9] ={'W', 'S', 'N', 'E', 'S', 'W', 'N', 'S', 'E'};
    int testSpeed[9] ={3, 4, 3, 4, 5, 7, 8, 1, 2};


public slots:
    void updateValues();

private:
    Ui::MainWindow *ui;
    QTimer *timer_1m;
    int value = 0;
};

#endif // MAINWINDOW_H
