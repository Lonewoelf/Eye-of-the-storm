#ifndef ERRORWINDOW_H
#define ERRORWINDOW_H

#include <QDialog>

namespace Ui {
class errorwindow;
}

class errorwindow : public QDialog
{
    Q_OBJECT

public:
    explicit errorwindow(QWidget *parent = nullptr);
    ~errorwindow();

private:
    Ui::errorwindow *ui;
};

#endif // ERRORWINDOW_H
