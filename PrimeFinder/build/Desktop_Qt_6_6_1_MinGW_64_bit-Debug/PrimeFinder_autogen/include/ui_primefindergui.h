/********************************************************************************
** Form generated from reading UI file 'primefindergui.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRIMEFINDERGUI_H
#define UI_PRIMEFINDERGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PrimeFinderGUI
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PrimeFinderGUI)
    {
        if (PrimeFinderGUI->objectName().isEmpty())
            PrimeFinderGUI->setObjectName("PrimeFinderGUI");
        PrimeFinderGUI->resize(800, 600);
        centralwidget = new QWidget(PrimeFinderGUI);
        centralwidget->setObjectName("centralwidget");
        PrimeFinderGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PrimeFinderGUI);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 29));
        PrimeFinderGUI->setMenuBar(menubar);
        statusbar = new QStatusBar(PrimeFinderGUI);
        statusbar->setObjectName("statusbar");
        PrimeFinderGUI->setStatusBar(statusbar);

        retranslateUi(PrimeFinderGUI);

        QMetaObject::connectSlotsByName(PrimeFinderGUI);
    } // setupUi

    void retranslateUi(QMainWindow *PrimeFinderGUI)
    {
        PrimeFinderGUI->setWindowTitle(QCoreApplication::translate("PrimeFinderGUI", "PrimeFinderGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PrimeFinderGUI: public Ui_PrimeFinderGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRIMEFINDERGUI_H
