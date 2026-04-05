#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Repository.h"
#include "RepoFile.h"
#include "AdoptionRepository.h"
#include "CSVRepo.h"
#include "HtmlRepo.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnSetRepo_clicked();


    void on_btnMemoryRepo_clicked(bool checked);

    void on_btnRepoFile_clicked(bool checked);

    void on_btnCsvRepo_clicked(bool checked);

    void on_btnHtmlRepo_clicked(bool checked);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
