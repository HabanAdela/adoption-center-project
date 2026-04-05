#include "userwindow.h"
#include "ui_userwindow.h"
#include <Windows.h>
#include <QMessageBox>
#include <vector>


UserWindow::UserWindow(QWidget *parent, Service *service)
    : QMainWindow(parent), service(service)
    , ui(new Ui::UserWindow)
{
    ui->setupUi(this);

    tableView = new QTableView;
    table = new AdoptionTable(this, service->getAllAdopted());
}

UserWindow::~UserWindow()
{
    delete ui;
}

void UserWindow::on_btnOpen_clicked()
{
    std::string fileType = this->service->getFileType();
    std::string path;
    if (fileType == "csv")
    {
        path = "C:/Informatica/OOP/A9/Adopted.csv";
        std::string com = "start notepad.exe " + path;
        system(com.c_str());
    }
    else
    {
        path = "C:/Informatica/OOP/A9/adopted.html";
        std::string com = "start " + path;
        system(com.c_str());
    }
}


void UserWindow::on_btnShow_clicked()
{
    currentIndex = 0;
    currentDogs = this->service->getAll();
    displayDog();
}

void UserWindow::displayDog() {
    if (currentDogs.empty()) {
        ui->teDog->setPlainText("No dogs to display.");
        return;
    }

    int i = currentIndex;
    QString text = QString::fromStdString(currentDogs[i].getBreed()) + " | " +
                   QString::fromStdString(currentDogs[i].getName()) + " | " +
                   QString::number(currentDogs[i].getAge()) + " | " +
                   QString::fromStdString(currentDogs[i].getPhoto());

    ui->teDog->setPlainText(text);

    std::string url = currentDogs[i].getPhoto();
    ShellExecuteA(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

void UserWindow::on_btnShowFiltered_clicked()
{
    std::string breed, age_str;
    int age;
    breed = ui->leFilterBreed->text().toStdString();
    age_str = ui->leFilterAge->text().toStdString();
    if (breed.empty() || age_str.empty()) {
        QMessageBox::warning(this, "Input warning","A field cannot be empty");
    }
    age = stoi(age_str);

    currentIndex = 0;
    currentDogs = this->service->FilterByBreed(breed, age);
    displayDog();
}


void UserWindow::on_btnAdopt_clicked()
{

    QString content = ui->teDog->toPlainText();
    QStringList parts = content.split(" | ");

    std::string breed = parts[0].toStdString();
    std::string name = parts[1].toStdString();
    int age = parts[2].toInt();
    std::string photo = parts[3].toStdString();

    Dog dog = Dog(breed, name, age, photo);
    currentDogs.erase(std::remove(currentDogs.begin(), currentDogs.end(), dog), currentDogs.end());
    this->service->adoptDog(dog);
    currentIndex -= 1;
}


void UserWindow::on_bntNext_clicked()
{
    if (currentDogs.empty()) {
        QMessageBox::information(this, "Info", "No more dogs.");
        return;
    }

    currentIndex = (currentIndex + 1) % currentDogs.size();
    displayDog();
}




void UserWindow::on_btnBack_clicked()
{
    this->close();
    if (parentWidget())
        parentWidget()->show();
}


void UserWindow::on_btnAdoptedTable_clicked()
{
    table = new AdoptionTable(this, service->getAllAdopted());
    tableView->setModel(table);
    tableView->setFixedSize(500, 500);
    tableView->show();
}

