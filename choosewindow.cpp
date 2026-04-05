#include "choosewindow.h"
#include "ui_choosewindow.h"
#include "adminwindow.h"
#include "userwindow.h"

ChooseWindow::ChooseWindow(QWidget *parent, Service* service)
    : QMainWindow(parent), service(service)
    , ui(new Ui::ChooseWindow)
{
    ui->setupUi(this);
}

ChooseWindow::~ChooseWindow()
{
    delete ui;
}

void ChooseWindow::on_btnAdmin_clicked()
{
    AdminWindow* aw = new AdminWindow(this, service);
    this->hide();
    aw->show();
}


void ChooseWindow::on_btnUser_clicked()
{
    UserWindow* uw = new UserWindow(this, service);
    this->hide();
    uw->show();
}

