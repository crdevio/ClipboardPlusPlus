/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *logs;
    QLabel *label;
    QListWidget *listWidget;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(754, 667);
        MainWindow->setStyleSheet(QString::fromUtf8("*{\n"
"background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(111, 111, 111, 30), stop:1 rgba(88, 88, 88, 30))\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        logs = new QLabel(centralwidget);
        logs->setObjectName(QString::fromUtf8("logs"));
        QFont font;
        font.setPointSize(16);
        logs->setFont(font);
        logs->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(logs, 2, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Lucida Console"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        font1.setStyleStrategy(QFont::PreferAntialias);
        label->setFont(font1);
        label->setTextFormat(Qt::MarkdownText);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Source Code Pro"));
        font2.setPointSize(26);
        font2.setBold(false);
        font2.setWeight(50);
        font2.setKerning(true);
        font2.setStyleStrategy(QFont::PreferAntialias);
        listWidget->setFont(font2);

        gridLayout->addWidget(listWidget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 754, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        logs->setText(QCoreApplication::translate("MainWindow", "Logiciel lanc\303\251", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ClipBoard ++ [Prototype]", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
