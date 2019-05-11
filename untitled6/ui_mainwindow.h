/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *podpis;
    QPushButton *but_start;
    QPushButton *but_wyj;
    QLabel *background;
    QLabel *bitmapa;
    QPushButton *but_e1;
    QPushButton *but_e2;
    QPushButton *but_e3;
    QPushButton *but_e4;
    QPushButton *but_e5;
    QFrame *frame;
    QLCDNumber *asmTimer;
    QLabel *asmTimeLabel;
    QLabel *cTimeLabel;
    QLCDNumber *cTimer;
    QLabel *milisecondsLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1024, 768);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/bmp_icon.png"), QSize(), QIcon::Normal, QIcon::On);
        MainWindow->setWindowIcon(icon);
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        podpis = new QLabel(centralWidget);
        podpis->setObjectName(QString::fromUtf8("podpis"));
        podpis->setGeometry(QRect(780, 10, 231, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Goudy Old Style"));
        font.setPointSize(10);
        podpis->setFont(font);
        but_start = new QPushButton(centralWidget);
        but_start->setObjectName(QString::fromUtf8("but_start"));
        but_start->setGeometry(QRect(60, 40, 186, 41));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        but_start->setFont(font1);
        but_start->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(180, 180, 180);\n"
"border: 1px solid gray;\n"
"\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        but_wyj = new QPushButton(centralWidget);
        but_wyj->setObjectName(QString::fromUtf8("but_wyj"));
        but_wyj->setGeometry(QRect(290, 40, 186, 41));
        but_wyj->setFont(font1);
        but_wyj->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(200, 200, 200);\n"
"border: 1px solid gray;\n"
"\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: red;\n"
"    font: bold 14px;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        background = new QLabel(centralWidget);
        background->setObjectName(QString::fromUtf8("background"));
        background->setGeometry(QRect(0, 0, 1031, 771));
        bitmapa = new QLabel(centralWidget);
        bitmapa->setObjectName(QString::fromUtf8("bitmapa"));
        bitmapa->setGeometry(QRect(310, 150, 640, 480));
        bitmapa->setStyleSheet(QString::fromUtf8(""));
        but_e1 = new QPushButton(centralWidget);
        but_e1->setObjectName(QString::fromUtf8("but_e1"));
        but_e1->setGeometry(QRect(30, 220, 186, 41));
        but_e1->setFont(font1);
        but_e1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(180, 180, 180);\n"
"border: 1px solid gray;\n"
"\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        but_e2 = new QPushButton(centralWidget);
        but_e2->setObjectName(QString::fromUtf8("but_e2"));
        but_e2->setGeometry(QRect(30, 290, 186, 41));
        but_e2->setFont(font1);
        but_e2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(180, 180, 180);\n"
"border: 1px solid gray;\n"
"\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        but_e3 = new QPushButton(centralWidget);
        but_e3->setObjectName(QString::fromUtf8("but_e3"));
        but_e3->setGeometry(QRect(30, 360, 186, 41));
        but_e3->setFont(font1);
        but_e3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(180, 180, 180);\n"
"border: 1px solid gray;\n"
"\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        but_e4 = new QPushButton(centralWidget);
        but_e4->setObjectName(QString::fromUtf8("but_e4"));
        but_e4->setGeometry(QRect(30, 430, 186, 41));
        but_e4->setFont(font1);
        but_e4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(180, 180, 180);\n"
"border: 1px solid gray;\n"
"\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        but_e5 = new QPushButton(centralWidget);
        but_e5->setObjectName(QString::fromUtf8("but_e5"));
        but_e5->setGeometry(QRect(30, 500, 186, 41));
        but_e5->setFont(font1);
        but_e5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(180, 180, 180);\n"
"border: 1px solid gray;\n"
"\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 10em;\n"
"    padding: 6px;\n"
"}\n"
"QPushButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #BEBEBE, stop: 1 #D7D7D7);\n"
"}"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 200, 231, 361));
        QFont font2;
        font2.setFamily(QString::fromUtf8("8514oem"));
        font2.setBold(true);
        font2.setWeight(75);
        frame->setFont(font2);
        frame->setStyleSheet(QString::fromUtf8(" border: 2px solid black;\n"
"    border-radius: 3px;\n"
"    padding: 2px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        asmTimer = new QLCDNumber(centralWidget);
        asmTimer->setObjectName(QString::fromUtf8("asmTimer"));
        asmTimer->setGeometry(QRect(400, 650, 211, 41));
        asmTimer->setSmallDecimalPoint(false);
        asmTimer->setProperty("value", QVariant(0.000000000000000));
        asmTimeLabel = new QLabel(centralWidget);
        asmTimeLabel->setObjectName(QString::fromUtf8("asmTimeLabel"));
        asmTimeLabel->setGeometry(QRect(180, 650, 201, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("OCR A Extended"));
        font3.setPointSize(20);
        asmTimeLabel->setFont(font3);
        asmTimeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cTimeLabel = new QLabel(centralWidget);
        cTimeLabel->setObjectName(QString::fromUtf8("cTimeLabel"));
        cTimeLabel->setGeometry(QRect(180, 710, 201, 41));
        cTimeLabel->setFont(font3);
        cTimeLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        cTimer = new QLCDNumber(centralWidget);
        cTimer->setObjectName(QString::fromUtf8("cTimer"));
        cTimer->setGeometry(QRect(400, 710, 211, 41));
        milisecondsLabel = new QLabel(centralWidget);
        milisecondsLabel->setObjectName(QString::fromUtf8("milisecondsLabel"));
        milisecondsLabel->setGeometry(QRect(630, 660, 55, 71));
        QFont font4;
        font4.setFamily(QString::fromUtf8("OCR A Extended"));
        font4.setPointSize(26);
        milisecondsLabel->setFont(font4);
        MainWindow->setCentralWidget(centralWidget);
        frame->raise();
        background->raise();
        podpis->raise();
        but_start->raise();
        but_wyj->raise();
        bitmapa->raise();
        but_e1->raise();
        but_e2->raise();
        but_e3->raise();
        but_e4->raise();
        but_e5->raise();
        asmTimer->raise();
        asmTimeLabel->raise();
        cTimeLabel->raise();
        cTimer->raise();
        milisecondsLabel->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "So\305\202daczuk_Dy\305\233ko_AK2", nullptr));
        podpis->setText(QApplication::translate("MainWindow", "Marek So\305\202daczuk / Tomasz Dy\305\233ko", nullptr));
        but_start->setText(QApplication::translate("MainWindow", "Wczytaj obraz", nullptr));
        but_wyj->setText(QApplication::translate("MainWindow", "Zako\305\204cz", nullptr));
        background->setText(QString());
        bitmapa->setText(QApplication::translate("MainWindow", "Bitmapa", nullptr));
        but_e1->setText(QApplication::translate("MainWindow", "Binaryzacja", nullptr));
        but_e2->setText(QApplication::translate("MainWindow", "Negatyw", nullptr));
        but_e3->setText(QApplication::translate("MainWindow", "Rozja\305\233nienie", nullptr));
        but_e4->setText(QApplication::translate("MainWindow", "Efekt 4", nullptr));
        but_e5->setText(QApplication::translate("MainWindow", "Efekt 5", nullptr));
        asmTimeLabel->setText(QApplication::translate("MainWindow", "Czas ASM", nullptr));
        cTimeLabel->setText(QApplication::translate("MainWindow", "Czas C/C++", nullptr));
        milisecondsLabel->setText(QApplication::translate("MainWindow", "ms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
