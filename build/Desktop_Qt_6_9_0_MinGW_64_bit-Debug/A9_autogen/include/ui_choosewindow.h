/********************************************************************************
** Form generated from reading UI file 'choosewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEWINDOW_H
#define UI_CHOOSEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *btnAdmin;
    QPushButton *btnUser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChooseWindow)
    {
        if (ChooseWindow->objectName().isEmpty())
            ChooseWindow->setObjectName("ChooseWindow");
        ChooseWindow->resize(368, 226);
        centralwidget = new QWidget(ChooseWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 40, 241, 41));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        btnAdmin = new QPushButton(centralwidget);
        btnAdmin->setObjectName("btnAdmin");
        btnAdmin->setGeometry(QRect(60, 120, 80, 24));
        QFont font1;
        font1.setPointSize(12);
        btnAdmin->setFont(font1);
        btnAdmin->setCursor(QCursor(Qt::CursorShape::BusyCursor));
        btnUser = new QPushButton(centralwidget);
        btnUser->setObjectName("btnUser");
        btnUser->setGeometry(QRect(220, 120, 80, 24));
        btnUser->setFont(font1);
        ChooseWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChooseWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 368, 21));
        ChooseWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ChooseWindow);
        statusbar->setObjectName("statusbar");
        ChooseWindow->setStatusBar(statusbar);

        retranslateUi(ChooseWindow);

        QMetaObject::connectSlotsByName(ChooseWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChooseWindow)
    {
        ChooseWindow->setWindowTitle(QCoreApplication::translate("ChooseWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("ChooseWindow", "Choose the type of user:", nullptr));
        btnAdmin->setText(QCoreApplication::translate("ChooseWindow", "Admin", nullptr));
        btnUser->setText(QCoreApplication::translate("ChooseWindow", "User", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChooseWindow: public Ui_ChooseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEWINDOW_H
