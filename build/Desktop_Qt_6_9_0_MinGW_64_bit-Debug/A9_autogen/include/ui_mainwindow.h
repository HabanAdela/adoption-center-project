/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *btnCsvRepo;
    QRadioButton *btnHtmlRepo;
    QPushButton *btnSetRepo;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QRadioButton *btnMemoryRepo;
    QRadioButton *btnRepoFile;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(785, 367);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 70, 311, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(430, 70, 311, 31));
        label_2->setFont(font);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(500, 130, 131, 52));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnCsvRepo = new QRadioButton(layoutWidget);
        btnCsvRepo->setObjectName("btnCsvRepo");

        verticalLayout_2->addWidget(btnCsvRepo);

        btnHtmlRepo = new QRadioButton(layoutWidget);
        btnHtmlRepo->setObjectName("btnHtmlRepo");

        verticalLayout_2->addWidget(btnHtmlRepo);

        btnSetRepo = new QPushButton(centralwidget);
        btnSetRepo->setObjectName("btnSetRepo");
        btnSetRepo->setGeometry(QRect(340, 270, 80, 24));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(80, 130, 131, 52));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnMemoryRepo = new QRadioButton(layoutWidget1);
        btnMemoryRepo->setObjectName("btnMemoryRepo");

        verticalLayout->addWidget(btnMemoryRepo);

        btnRepoFile = new QRadioButton(layoutWidget1);
        btnRepoFile->setObjectName("btnRepoFile");

        verticalLayout->addWidget(btnRepoFile);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 785, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Repository type for the dogs at the center:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Repository type for the adopted dogs:", nullptr));
        btnCsvRepo->setText(QCoreApplication::translate("MainWindow", "CSV Repository", nullptr));
        btnHtmlRepo->setText(QCoreApplication::translate("MainWindow", "Html Repository", nullptr));
        btnSetRepo->setText(QCoreApplication::translate("MainWindow", "Ok", nullptr));
        btnMemoryRepo->setText(QCoreApplication::translate("MainWindow", "Memory Repository", nullptr));
        btnRepoFile->setText(QCoreApplication::translate("MainWindow", "File Repository", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
