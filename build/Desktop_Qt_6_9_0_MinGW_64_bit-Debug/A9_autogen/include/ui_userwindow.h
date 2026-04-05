/********************************************************************************
** Form generated from reading UI file 'userwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnShow;
    QPushButton *btnOpen;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *leFilterBreed;
    QLineEdit *leFilterAge;
    QPushButton *btnShowFiltered;
    QGroupBox *Dog;
    QPlainTextEdit *teDog;
    QPushButton *btnAdopt;
    QPushButton *bntNext;
    QPushButton *btnBack;
    QPushButton *btnAdoptedTable;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *UserWindow)
    {
        if (UserWindow->objectName().isEmpty())
            UserWindow->setObjectName("UserWindow");
        UserWindow->resize(711, 481);
        centralwidget = new QWidget(UserWindow);
        centralwidget->setObjectName("centralwidget");
        btnShow = new QPushButton(centralwidget);
        btnShow->setObjectName("btnShow");
        btnShow->setGeometry(QRect(520, 220, 111, 31));
        btnOpen = new QPushButton(centralwidget);
        btnOpen->setObjectName("btnOpen");
        btnOpen->setGeometry(QRect(520, 310, 121, 41));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(460, 40, 221, 141));
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 40, 81, 51));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        verticalLayoutWidget_2 = new QWidget(groupBox);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(80, 40, 131, 56));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        leFilterBreed = new QLineEdit(verticalLayoutWidget_2);
        leFilterBreed->setObjectName("leFilterBreed");

        verticalLayout_2->addWidget(leFilterBreed);

        leFilterAge = new QLineEdit(verticalLayoutWidget_2);
        leFilterAge->setObjectName("leFilterAge");

        verticalLayout_2->addWidget(leFilterAge);

        btnShowFiltered = new QPushButton(groupBox);
        btnShowFiltered->setObjectName("btnShowFiltered");
        btnShowFiltered->setGeometry(QRect(60, 100, 111, 31));
        Dog = new QGroupBox(centralwidget);
        Dog->setObjectName("Dog");
        Dog->setGeometry(QRect(30, 20, 321, 291));
        teDog = new QPlainTextEdit(Dog);
        teDog->setObjectName("teDog");
        teDog->setGeometry(QRect(10, 30, 291, 131));
        btnAdopt = new QPushButton(Dog);
        btnAdopt->setObjectName("btnAdopt");
        btnAdopt->setGeometry(QRect(40, 220, 80, 24));
        bntNext = new QPushButton(Dog);
        bntNext->setObjectName("bntNext");
        bntNext->setGeometry(QRect(190, 220, 80, 24));
        btnBack = new QPushButton(centralwidget);
        btnBack->setObjectName("btnBack");
        btnBack->setGeometry(QRect(590, 400, 80, 24));
        btnAdoptedTable = new QPushButton(centralwidget);
        btnAdoptedTable->setObjectName("btnAdoptedTable");
        btnAdoptedTable->setGeometry(QRect(20, 410, 80, 24));
        UserWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UserWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 711, 21));
        UserWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(UserWindow);
        statusbar->setObjectName("statusbar");
        UserWindow->setStatusBar(statusbar);

        retranslateUi(UserWindow);

        QMetaObject::connectSlotsByName(UserWindow);
    } // setupUi

    void retranslateUi(QMainWindow *UserWindow)
    {
        UserWindow->setWindowTitle(QCoreApplication::translate("UserWindow", "MainWindow", nullptr));
        btnShow->setText(QCoreApplication::translate("UserWindow", "Display Dogs", nullptr));
        btnOpen->setText(QCoreApplication::translate("UserWindow", "Open Adoption List", nullptr));
        groupBox->setTitle(QCoreApplication::translate("UserWindow", "Filter Dogs", nullptr));
        label_2->setText(QCoreApplication::translate("UserWindow", "Breed : ", nullptr));
        label->setText(QCoreApplication::translate("UserWindow", "Max age : ", nullptr));
        btnShowFiltered->setText(QCoreApplication::translate("UserWindow", "Show Filtered", nullptr));
        Dog->setTitle(QCoreApplication::translate("UserWindow", "Dog", nullptr));
        btnAdopt->setText(QCoreApplication::translate("UserWindow", "Adopt", nullptr));
        bntNext->setText(QCoreApplication::translate("UserWindow", "Next", nullptr));
        btnBack->setText(QCoreApplication::translate("UserWindow", "Back", nullptr));
        btnAdoptedTable->setText(QCoreApplication::translate("UserWindow", "Show", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindow: public Ui_UserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
