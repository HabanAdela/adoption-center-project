#ifndef USERWINDOW_H
#define USERWINDOW_H
#include "Service.h"
#include <QMainWindow>
#include <vector>
#include "adoptiontable.h"

namespace Ui {
class UserWindow;
}

class UserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = nullptr, Service *service = nullptr);
    ~UserWindow();

private slots:
    void on_btnOpen_clicked();

    void on_btnShow_clicked();

    void on_btnShowFiltered_clicked();

    void on_btnAdopt_clicked();

    void on_bntNext_clicked();

    void on_btnBack_clicked();

    void on_btnAdoptedTable_clicked();

private:
    Ui::UserWindow *ui;
    Service *service;
    std::vector<Dog> currentDogs;
    int currentIndex = 0;
    void displayDog();
    AdoptionTable* table;
    QTableView* tableView;
};

#endif // USERWINDOW_H
