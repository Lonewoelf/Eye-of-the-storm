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

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(650, 407);
        MainWindow->setIconSize(QSize(100, 100));
        actionTrend = new QAction(MainWindow);
        actionTrend->setObjectName(QStringLiteral("actionTrend"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        windDirection = new QPlainTextEdit(centralWidget);
        windDirection->setObjectName(QStringLiteral("windDirection"));
        windDirection->setGeometry(QRect(360, 130, 131, 91));
        QFont font;
        font.setFamily(QStringLiteral("Source Code Pro"));
        font.setPointSize(26);
        font.setBold(false);
        font.setWeight(50);
        windDirection->setFont(font);
        windDirection->setInputMethodHints(Qt::ImhNone);
        windDirection->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        windDirection->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        windDirection->setReadOnly(true);
        humidity = new QPlainTextEdit(centralWidget);
        humidity->setObjectName(QStringLiteral("humidity"));
        humidity->setGeometry(QRect(150, 270, 131, 91));
        humidity->setFont(font);
        humidity->setInputMethodHints(Qt::ImhNone);
        humidity->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        humidity->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        humidity->setReadOnly(true);
        currentLabel = new QLabel(centralWidget);
        currentLabel->setObjectName(QStringLiteral("currentLabel"));
        currentLabel->setGeometry(QRect(290, 30, 81, 31));
        QPalette palette;
        QBrush brush(QColor(249, 249, 249, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush1(QColor(254, 254, 254, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush1);
        currentLabel->setPalette(palette);
        QFont font1;
        font1.setFamily(QStringLiteral("SimSun"));
        font1.setPointSize(14);
        currentLabel->setFont(font1);
        windSpeed = new QPlainTextEdit(centralWidget);
        windSpeed->setObjectName(QStringLiteral("windSpeed"));
        windSpeed->setGeometry(QRect(360, 270, 131, 91));
        windSpeed->setFont(font);
        windSpeed->setInputMethodHints(Qt::ImhNone);
        windSpeed->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        windSpeed->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        windSpeed->setReadOnly(true);
        temperature = new QPlainTextEdit(centralWidget);
        temperature->setObjectName(QStringLiteral("temperature"));
        temperature->setGeometry(QRect(150, 130, 131, 91));
        temperature->setFont(font);
        temperature->setInputMethodHints(Qt::ImhNone);
        temperature->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        temperature->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        temperature->setReadOnly(true);
        temperature->setCenterOnScroll(false);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 240, 47, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 100, 71, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(390, 100, 71, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(390, 240, 71, 16));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Weather stationC", nullptr));
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
