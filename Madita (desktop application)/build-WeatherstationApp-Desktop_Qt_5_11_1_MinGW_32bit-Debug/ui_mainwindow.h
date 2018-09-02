/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTrend;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *Current_tab;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser_3;
    QLabel *label;
    QWidget *Trend_tab;
    QWidget *Graph;
    QWidget *Table;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        actionTrend = new QAction(MainWindow);
        actionTrend->setObjectName(QStringLiteral("actionTrend"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 651, 411));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        tabWidget->setPalette(palette);
        Current_tab = new QWidget();
        Current_tab->setObjectName(QStringLiteral("Current_tab"));
        textBrowser = new QTextBrowser(Current_tab);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 150, 161, 91));
        textBrowser_2 = new QTextBrowser(Current_tab);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(240, 150, 161, 91));
        textBrowser_3 = new QTextBrowser(Current_tab);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(460, 150, 161, 91));
        label = new QLabel(Current_tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(280, 90, 71, 31));
        QPalette palette1;
        QBrush brush1(QColor(249, 249, 249, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        QBrush brush2(QColor(254, 254, 254, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        QBrush brush3(QColor(120, 120, 120, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        label->setPalette(palette1);
        QFont font;
        font.setFamily(QStringLiteral("SimSun"));
        font.setPointSize(14);
        label->setFont(font);
        tabWidget->addTab(Current_tab, QString());
        Trend_tab = new QWidget();
        Trend_tab->setObjectName(QStringLiteral("Trend_tab"));
        Graph = new QWidget(Trend_tab);
        Graph->setObjectName(QStringLiteral("Graph"));
        Graph->setGeometry(QRect(30, 100, 241, 171));
        Table = new QWidget(Trend_tab);
        Table->setObjectName(QStringLiteral("Table"));
        Table->setGeometry(QRect(370, 100, 241, 171));
        tabWidget->addTab(Trend_tab, QString());
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Weather stationC", nullptr));
        actionTrend->setText(QApplication::translate("MainWindow", "Trend", nullptr));
        label->setText(QApplication::translate("MainWindow", "Current", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Current_tab), QApplication::translate("MainWindow", "Current", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Trend_tab), QApplication::translate("MainWindow", "Trend", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
