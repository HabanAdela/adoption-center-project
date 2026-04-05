#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include "Service.h"
namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr, Service* service = nullptr);
    ~AdminWindow();

private slots:
    void on_btnAdd_clicked();

    void on_btnDelete_clicked();

    void on_btnUpdate_clicked();

    void on_btnBack2_clicked();

    void on_btnUndo_clicked();

    void on_btnRedo_clicked();
protected:
    void keyPressEvent(QKeyEvent* event) override;
private:
    Ui::AdminWindow *ui;
    Service *service;
    void setTable();
};

#endif // ADMINWINDOW_H
