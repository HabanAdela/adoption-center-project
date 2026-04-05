#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "Service.h"
#include <vector>
#include "Dog.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QKeyEvent>

AdminWindow::AdminWindow(QWidget *parent, Service *service)
    : QMainWindow(parent), service(service)
    , ui(new Ui::AdminWindow)
{
    ui->setupUi(this);

    setTable();

}

void AdminWindow::setTable(){
    ui->twAdmin->clear();
    ui->twAdmin->setColumnCount(4);
    ui->twAdmin->setHorizontalHeaderLabels({ "Breed", "Name", "Age", "Photo Link" });

    std::vector<Dog> all = service->getAll();
    ui->twAdmin->setRowCount(all.size());
    for (int i = 0; i < all.size(); ++i)
    {
        ui->twAdmin->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(all[i].getBreed())));
        ui->twAdmin->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(all[i].getName())));
        ui->twAdmin->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(std::to_string(all[i].getAge()))));
        ui->twAdmin->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(all[i].getPhoto())));
    }
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::on_btnAdd_clicked()
{
    std::string breed, name, photo, age_str;
    int age;
    name = ui->leAddName->text().toStdString();
    photo = ui->leAddPhoto->text().toStdString();
    breed = ui->leAddBreed->text().toStdString();
    age_str = ui->leAddAge->text().toStdString();
    if (name.empty() || photo.empty() || breed.empty() || age_str.empty()) {
        QMessageBox::warning(this, "Input warning","A field cannot be empty");
    }

    age = stoi(age_str);
    if (age < 0)
        QMessageBox::warning(this, "Input warning","The age cannot be a negativ integer");


    Dog dog = Dog(breed, name, age, photo);
    try{
        this->service->addDog(dog);
    }

    catch(...){
         QMessageBox::warning(this, "Input warning","Cannot add dog");
    }
    this->setTable();

}


void AdminWindow::on_btnDelete_clicked()
{
    std::string name = ui->leDeleteName->text().toStdString();
    try{

        std::vector<Dog> all = service->getAll();
        Dog found;
        for (auto d : all)
            if (d.getName() == name)
            {
                found = d;
                break;
            }
        this->service->deleteDog(found);
        this->setTable();
    }
    catch(...){
        QMessageBox::warning(this, "Input warning","The dog is not found");
    }
}


void AdminWindow::on_btnUpdate_clicked()
{
    std::string breed, name, photo, age_str;
    int age;
    name = ui->leUpdateName->text().toStdString();
    photo = ui->leUpdatePhoto->text().toStdString();
    breed = ui->leUpdateBreed->text().toStdString();
    age_str = ui->leUpdateAge->text().toStdString();
    if (name.empty()) {
        QMessageBox::warning(this, "Input warning","The name cannot be empty");
    }

    if (!age_str.empty()){
        age = stoi(age_str);
        if (age < 0)
            QMessageBox::warning(this, "Input warning","The age cannot be a negativ integer");
    }
    else age = -1;

    std::vector<Dog> all = service->getAll();
    Dog found;
    for (auto d : all)
        if (d.getName() == name)
        {
            found = d;
            break;
        }
    Dog newDog(breed, name, age, photo);
    if (breed == "")
        newDog.setBreed(found.getBreed());
    if (age == -1)
        newDog.setAge(found.getAge());
    if (photo == "")
        newDog.setPhoto(found.getPhoto());

    this->service->updateDog(found, newDog);
    this->setTable();
}


void AdminWindow::on_btnBack2_clicked()
{
    this->close();
    if (parentWidget())
        parentWidget()->show();
}


void AdminWindow::on_btnUndo_clicked()
{
    try
    {
        service->undo();
        setTable();
    }
    catch (...)
    {
        QMessageBox::warning(this, "Undo error", "No more undo");
    }
}


void AdminWindow::on_btnRedo_clicked()
{
    try
    {
        service->redo();
        setTable();
    }
    catch (...)
    {
        QMessageBox::warning(this, "Redo error", "No more redo");
    }
}

void AdminWindow::keyPressEvent(QKeyEvent* event)
{
    if (event->modifiers() & Qt::ControlModifier) {
        switch (event->key()){
        case Qt::Key_Z:
            try
            {
                service->undo();
                setTable();
            }
            catch (...)
            {
                QMessageBox::warning(this, "Undo error", "No more undo");
            }
            break;
        case Qt::Key_Y:
            try
            {
                service->redo();
                setTable();
            }
            catch (...)
            {
                QMessageBox::warning(this, "Redo error", "No more redo");
            }
            break;
        }
    }
}

