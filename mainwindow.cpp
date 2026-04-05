#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "Exception.h"
#include "Service.h"
#include "choosewindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSetRepo_clicked()
{
    if (!(ui->btnCsvRepo->isChecked() || ui->btnHtmlRepo->isChecked())
        || !(ui->btnRepoFile->isChecked() || ui->btnMemoryRepo->isChecked())) {
        QMessageBox::warning(this, "Input Error", "You must choose a type of repository for the adoption center and for the adoption list.");
        return;
    }


    Repository* repo = nullptr;

    if (ui->btnMemoryRepo->isChecked()){
            repo = new MemoryRepository();

    }
    else {
        try {
            repo = new FileRepository("C:/Informatica/OOP/A9/Dogs.txt");
        }
        catch (Exception e) {
            QMessageBox::critical(this, "Input Error","Cannot open file");
            return;
        }
    }

    AdoptionRepository* adoption_repo = nullptr;

    if (ui->btnCsvRepo->isChecked()){
        try {
            adoption_repo = new CSVRepo("C:/Informatica/OOP/A9/Adopted.csv");
        }
        catch (Exception e) {
            QMessageBox::critical(this, "Input Error","Cannot open file");
            return;
        }
    }
    else{

        try {
            adoption_repo = new HtmlRepo("C:/Informatica/OOP/A9/adopted.html");
        }
        catch (Exception e) {
            QMessageBox::critical(this, "Input Error","Cannot open file");
            return;
        }
    }

    Service* service = new Service(*repo, *adoption_repo);
    ChooseWindow* ch_w = new ChooseWindow(nullptr, service);
    this->hide();
    ch_w->show();
}


void MainWindow::on_btnMemoryRepo_clicked(bool checked)
{
    if (checked && ui->btnRepoFile->isChecked())
        ui->btnRepoFile->setChecked(false);
}


void MainWindow::on_btnRepoFile_clicked(bool checked)
{
    if (checked && ui->btnMemoryRepo->isChecked())
        ui->btnMemoryRepo->setChecked(false);
}


void MainWindow::on_btnCsvRepo_clicked(bool checked)
{
    if (checked && ui->btnHtmlRepo->isChecked())
        ui->btnHtmlRepo->setChecked(false);
}


void MainWindow::on_btnHtmlRepo_clicked(bool checked)
{
    if (checked && ui->btnCsvRepo->isChecked())
        ui->btnCsvRepo->setChecked(false);
}


void MainWindow::on_pushButton_clicked()
{
    //std::
}

