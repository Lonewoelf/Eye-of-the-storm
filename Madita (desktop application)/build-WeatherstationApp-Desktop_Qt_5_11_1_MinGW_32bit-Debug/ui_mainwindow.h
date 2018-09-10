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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTrend;
    QWidget *centralWidget;
    QPlainTextEdit *windDirection;
    QPlainTextEdit *humidity;
    QLabel *currentLabel;
    QPlainTextEdit *windSpeed;
    QPlainTextEdit *temperature;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *trendButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(650, 407);
        MainWindow->setStyleSheet(QStringLiteral("background-color:qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(255, 255, 255, 255), stop:0.1 rgba(255, 255, 255, 255), stop:0.2 rgba(163, 163, 163, 167), stop:0.3 rgba(204, 204, 204, 92), stop:0.4 rgba(209, 209, 209, 51), stop:0.5 rgba(0, 0, 0, 205), stop:0.52 rgba(0, 0, 0, 205), stop:0.6 rgba(234, 234, 234, 84), stop:1 rgba(255, 255, 255, 0))"));
        MainWindow->setIconSize(QSize(100, 100));
        actionTrend = new QAction(MainWindow);
        actionTrend->setObjectName(QStringLiteral("actionTrend"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        windDirection = new QPlainTextEdit(centralWidget);
        windDirection->setObjectName(QStringLiteral("windDirection"));
        windDirection->setGeometry(QRect(370, 80, 131, 91));
        QFont font;
        font.setFamily(QStringLiteral("Source Code Pro"));
        font.setPointSize(26);
        font.setBold(false);
        font.setWeight(50);
        windDirection->setFont(font);
        windDirection->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
""));
        windDirection->setInputMethodHints(Qt::ImhNone);
        windDirection->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        windDirection->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        windDirection->setReadOnly(true);
        humidity = new QPlainTextEdit(centralWidget);
        humidity->setObjectName(QStringLiteral("humidity"));
        humidity->setGeometry(QRect(150, 230, 131, 91));
        humidity->setFont(font);
        humidity->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
""));
        humidity->setInputMethodHints(Qt::ImhNone);
        humidity->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        humidity->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        humidity->setReadOnly(true);
        currentLabel = new QLabel(centralWidget);
        currentLabel->setObjectName(QStringLiteral("currentLabel"));
        currentLabel->setGeometry(QRect(290, 30, 81, 31));
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
        QFont font1;
        font1.setFamily(QStringLiteral("SimSun"));
        font1.setPointSize(14);
        currentLabel->setFont(font1);
        currentLabel->setStyleSheet(QLatin1String("background-color: rgba(0,0,0,0%)\n"
""));
        windSpeed = new QPlainTextEdit(centralWidget);
        windSpeed->setObjectName(QStringLiteral("windSpeed"));
        windSpeed->setGeometry(QRect(370, 230, 131, 91));
        windSpeed->setFont(font);
        windSpeed->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
""));
        windSpeed->setInputMethodHints(Qt::ImhNone);
        windSpeed->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        windSpeed->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        windSpeed->setReadOnly(true);
        temperature = new QPlainTextEdit(centralWidget);
        temperature->setObjectName(QStringLiteral("temperature"));
        temperature->setGeometry(QRect(150, 80, 131, 91));
        temperature->setFont(font);
        temperature->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
""));
        temperature->setInputMethodHints(Qt::ImhNone);
        temperature->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        temperature->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        temperature->setReadOnly(true);
        temperature->setCenterOnScroll(false);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 200, 47, 13));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label->setPalette(palette1);
        label->setStyleSheet(QStringLiteral("background-color: rgba(0,0,0,0%)"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 50, 71, 16));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_2->setPalette(palette2);
        label_2->setStyleSheet(QStringLiteral("background-color: rgba(0,0,0,0%)"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(400, 50, 71, 16));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_3->setPalette(palette3);
        label_3->setStyleSheet(QStringLiteral("background-color: rgba(0,0,0,0%)"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(400, 200, 71, 16));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        label_4->setPalette(palette4);
        label_4->setStyleSheet(QStringLiteral("background-color: rgba(0,0,0,0%)"));
        trendButton = new QPushButton(centralWidget);
        trendButton->setObjectName(QStringLiteral("trendButton"));
        trendButton->setGeometry(QRect(570, 380, 75, 23));
        trendButton->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255)"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Weather station(Current)", nullptr));
        actionTrend->setText(QApplication::translate("MainWindow", "Trend", nullptr));
        windDirection->setPlainText(QString());
        humidity->setPlainText(QString());
        currentLabel->setText(QApplication::translate("MainWindow", "Current", nullptr));
        windSpeed->setPlainText(QString());
        temperature->setPlainText(QString());
        label->setText(QApplication::translate("MainWindow", "Humidity", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Temperature", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Wind direction", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Wind speed", nullptr));
        trendButton->setText(QApplication::translate("MainWindow", "Trend", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
