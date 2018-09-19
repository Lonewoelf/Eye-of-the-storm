/********************************************************************************
** Form generated from reading UI file 'trendwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRENDWINDOW_H
#define UI_TRENDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_trendWindow
{
public:
    QWidget *centralwidget;
    QLabel *currentLabel;
    QTableView *tableView;
    QGraphicsView *graphicsView;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *trendWindow)
    {
        if (trendWindow->objectName().isEmpty())
            trendWindow->setObjectName(QStringLiteral("trendWindow"));
        trendWindow->resize(650, 407);
        centralwidget = new QWidget(trendWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        currentLabel = new QLabel(centralwidget);
        currentLabel->setObjectName(QStringLiteral("currentLabel"));
        currentLabel->setGeometry(QRect(290, 50, 51, 31));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(249, 249, 249, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush3(QColor(254, 254, 254, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush3);
        QBrush brush4(QColor(120, 120, 120, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush3);
        currentLabel->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("SimSun"));
        font.setPointSize(14);
        currentLabel->setFont(font);
        currentLabel->setStyleSheet(QLatin1String("background-color: rgba(0,0,0,0%)\n"
""));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(360, 130, 256, 192));
        tableView->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(20, 130, 256, 192));
        graphicsView->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        trendWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(trendWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        trendWindow->setStatusBar(statusbar);

        retranslateUi(trendWindow);

        QMetaObject::connectSlotsByName(trendWindow);
    } // setupUi

    void retranslateUi(QMainWindow *trendWindow)
    {
        trendWindow->setWindowTitle(QApplication::translate("trendWindow", "Weather station (Trend)", nullptr));
        currentLabel->setText(QApplication::translate("trendWindow", "Trend", nullptr));
    } // retranslateUi

};

namespace Ui {
    class trendWindow: public Ui_trendWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRENDWINDOW_H
