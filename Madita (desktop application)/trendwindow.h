#ifndef TRENDWINDOW_H
#define TRENDWINDOW_H

#include <QMainWindow>
#include <QtSql/qsqldatabase.h>
#include <QtSql/qtsqlglobal.h>

namespace Ui {
class trendWindow;
}

class trendWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase dbTrend;
    void loadTable();
    void loadGraph();
    void checkInput();
    explicit trendWindow(QWidget *parent = nullptr);
    ~trendWindow();

private slots:

    void on_reload_clicked();

private:
    Ui::trendWindow *ui;
    int periodOfTime = 1;
    int location;
};

#endif // TRENDWINDOW_H
