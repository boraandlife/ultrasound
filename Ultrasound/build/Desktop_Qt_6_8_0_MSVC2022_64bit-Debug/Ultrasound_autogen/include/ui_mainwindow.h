/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton1;
    QLabel *statuslabel1;
    QGraphicsView *graphicsView;
    QSlider *noiseLevelSlider;
    QSlider *objectWidthSlider;
    QLabel *noiseLabel;
    QLabel *witdhLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton1 = new QPushButton(centralwidget);
        pushButton1->setObjectName("pushButton1");
        pushButton1->setGeometry(QRect(330, 50, 91, 24));
        statuslabel1 = new QLabel(centralwidget);
        statuslabel1->setObjectName("statuslabel1");
        statuslabel1->setGeometry(QRect(120, 120, 111, 16));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(70, 200, 661, 351));
        noiseLevelSlider = new QSlider(centralwidget);
        noiseLevelSlider->setObjectName("noiseLevelSlider");
        noiseLevelSlider->setGeometry(QRect(570, 160, 160, 16));
        noiseLevelSlider->setMinimum(10);
        noiseLevelSlider->setMaximum(100);
        noiseLevelSlider->setValue(50);
        noiseLevelSlider->setOrientation(Qt::Orientation::Horizontal);
        objectWidthSlider = new QSlider(centralwidget);
        objectWidthSlider->setObjectName("objectWidthSlider");
        objectWidthSlider->setGeometry(QRect(390, 160, 160, 16));
        objectWidthSlider->setMinimum(10);
        objectWidthSlider->setMaximum(100);
        objectWidthSlider->setValue(50);
        objectWidthSlider->setOrientation(Qt::Orientation::Horizontal);
        noiseLabel = new QLabel(centralwidget);
        noiseLabel->setObjectName("noiseLabel");
        noiseLabel->setGeometry(QRect(620, 130, 49, 16));
        witdhLabel = new QLabel(centralwidget);
        witdhLabel->setObjectName("witdhLabel");
        witdhLabel->setGeometry(QRect(440, 130, 49, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton1->setText(QCoreApplication::translate("MainWindow", "Baslat / Durdur", nullptr));
        statuslabel1->setText(QCoreApplication::translate("MainWindow", "Durum", nullptr));
        noiseLabel->setText(QCoreApplication::translate("MainWindow", "Noise :", nullptr));
        witdhLabel->setText(QCoreApplication::translate("MainWindow", "Width :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
