#ifndef TRENDWINDOW_H
#define TRENDWINDOW_H

#include <QMainWindow>

namespace Ui {
class trendWindow;
}

class trendWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit trendWindow(QWidget *parent = nullptr);
    ~trendWindow();

private:
    Ui::trendWindow *ui;
};

#endif // TRENDWINDOW_H
