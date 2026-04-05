/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *btnAdd;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *leAddName;
    QLineEdit *leAddAge;
    QLineEdit *leAddBreed;
    QLineEdit *leAddPhoto;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QGroupBox *groupBox_3;
    QPushButton *btnDelete;
    QLabel *label10;
    QLineEdit *leDeleteName;
    QGroupBox *groupBox_2;
    QPushButton *btnUpdate;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *leUpdateName;
    QLineEdit *leUpdateAge;
    QLineEdit *leUpdateBreed;
    QLineEdit *leUpdatePhoto;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QTableWidget *twAdmin;
    QPushButton *btnBack2;
    QPushButton *btnUndo;
    QPushButton *btnRedo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName("AdminWindow");
        AdminWindow->resize(800, 600);
        centralwidget = new QWidget(AdminWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(540, 10, 231, 211));
        btnAdd = new QPushButton(groupBox);
        btnAdd->setObjectName("btnAdd");
        btnAdd->setGeometry(QRect(80, 180, 80, 24));
        verticalLayoutWidget = new QWidget(groupBox);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(80, 40, 141, 116));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        leAddName = new QLineEdit(verticalLayoutWidget);
        leAddName->setObjectName("leAddName");

        verticalLayout->addWidget(leAddName);

        leAddAge = new QLineEdit(verticalLayoutWidget);
        leAddAge->setObjectName("leAddAge");

        verticalLayout->addWidget(leAddAge);

        leAddBreed = new QLineEdit(verticalLayoutWidget);
        leAddBreed->setObjectName("leAddBreed");

        verticalLayout->addWidget(leAddBreed);

        leAddPhoto = new QLineEdit(verticalLayoutWidget);
        leAddPhoto->setObjectName("leAddPhoto");

        verticalLayout->addWidget(leAddPhoto);

        verticalLayoutWidget_2 = new QWidget(groupBox);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(10, 40, 81, 111));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName("label_4");

        verticalLayout_2->addWidget(label_4);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(540, 440, 231, 111));
        btnDelete = new QPushButton(groupBox_3);
        btnDelete->setObjectName("btnDelete");
        btnDelete->setGeometry(QRect(80, 80, 80, 24));
        label10 = new QLabel(groupBox_3);
        label10->setObjectName("label10");
        label10->setGeometry(QRect(10, 40, 49, 16));
        leDeleteName = new QLineEdit(groupBox_3);
        leDeleteName->setObjectName("leDeleteName");
        leDeleteName->setGeometry(QRect(80, 40, 131, 24));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(540, 230, 231, 211));
        btnUpdate = new QPushButton(groupBox_2);
        btnUpdate->setObjectName("btnUpdate");
        btnUpdate->setGeometry(QRect(80, 180, 80, 24));
        verticalLayoutWidget_3 = new QWidget(groupBox_2);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(100, 40, 121, 116));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        leUpdateName = new QLineEdit(verticalLayoutWidget_3);
        leUpdateName->setObjectName("leUpdateName");

        verticalLayout_3->addWidget(leUpdateName);

        leUpdateAge = new QLineEdit(verticalLayoutWidget_3);
        leUpdateAge->setObjectName("leUpdateAge");

        verticalLayout_3->addWidget(leUpdateAge);

        leUpdateBreed = new QLineEdit(verticalLayoutWidget_3);
        leUpdateBreed->setObjectName("leUpdateBreed");

        verticalLayout_3->addWidget(leUpdateBreed);

        leUpdatePhoto = new QLineEdit(verticalLayoutWidget_3);
        leUpdatePhoto->setObjectName("leUpdatePhoto");

        verticalLayout_3->addWidget(leUpdatePhoto);

        verticalLayoutWidget_4 = new QWidget(groupBox_2);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(10, 40, 86, 111));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalLayoutWidget_4);
        label_5->setObjectName("label_5");

        verticalLayout_4->addWidget(label_5);

        label_6 = new QLabel(verticalLayoutWidget_4);
        label_6->setObjectName("label_6");

        verticalLayout_4->addWidget(label_6);

        label_7 = new QLabel(verticalLayoutWidget_4);
        label_7->setObjectName("label_7");

        verticalLayout_4->addWidget(label_7);

        label_8 = new QLabel(verticalLayoutWidget_4);
        label_8->setObjectName("label_8");

        verticalLayout_4->addWidget(label_8);

        twAdmin = new QTableWidget(centralwidget);
        twAdmin->setObjectName("twAdmin");
        twAdmin->setGeometry(QRect(25, 11, 491, 501));
        btnBack2 = new QPushButton(centralwidget);
        btnBack2->setObjectName("btnBack2");
        btnBack2->setGeometry(QRect(30, 530, 80, 24));
        btnUndo = new QPushButton(centralwidget);
        btnUndo->setObjectName("btnUndo");
        btnUndo->setGeometry(QRect(240, 530, 80, 24));
        btnRedo = new QPushButton(centralwidget);
        btnRedo->setObjectName("btnRedo");
        btnRedo->setGeometry(QRect(350, 530, 80, 24));
        AdminWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        AdminWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminWindow);
        statusbar->setObjectName("statusbar");
        AdminWindow->setStatusBar(statusbar);

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWindow)
    {
        AdminWindow->setWindowTitle(QCoreApplication::translate("AdminWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("AdminWindow", "Add Dog", nullptr));
        btnAdd->setText(QCoreApplication::translate("AdminWindow", "Add", nullptr));
        label->setText(QCoreApplication::translate("AdminWindow", "Name:", nullptr));
        label_2->setText(QCoreApplication::translate("AdminWindow", "Age:", nullptr));
        label_3->setText(QCoreApplication::translate("AdminWindow", "Breed:", nullptr));
        label_4->setText(QCoreApplication::translate("AdminWindow", "Photo link:", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("AdminWindow", "Delete Dog", nullptr));
        btnDelete->setText(QCoreApplication::translate("AdminWindow", "Delete", nullptr));
        label10->setText(QCoreApplication::translate("AdminWindow", "Name : ", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("AdminWindow", "Update Dog", nullptr));
        btnUpdate->setText(QCoreApplication::translate("AdminWindow", "Update", nullptr));
        label_5->setText(QCoreApplication::translate("AdminWindow", "Name:", nullptr));
        label_6->setText(QCoreApplication::translate("AdminWindow", "New Age:", nullptr));
        label_7->setText(QCoreApplication::translate("AdminWindow", "New Breed:", nullptr));
        label_8->setText(QCoreApplication::translate("AdminWindow", "New Photo link:", nullptr));
        btnBack2->setText(QCoreApplication::translate("AdminWindow", "Back", nullptr));
        btnUndo->setText(QCoreApplication::translate("AdminWindow", "Undo", nullptr));
        btnRedo->setText(QCoreApplication::translate("AdminWindow", "Redo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
