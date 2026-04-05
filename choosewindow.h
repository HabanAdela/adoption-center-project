#ifndef CHOOSEWINDOW_H
#define CHOOSEWINDOW_H

#include <QMainWindow>
#include "Service.h"
#include "HtmlRepo.h"


namespace Ui {
class ChooseWindow;
}

class ChooseWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseWindow(QWidget *parent = nullptr, Service* service = nullptr);
    ~ChooseWindow();

private slots:
    void on_btnAdmin_clicked();

    void on_btnUser_clicked();

private:
    Ui::ChooseWindow *ui;
    Service* service;
};

#endif // CHOOSEWINDOW_H
