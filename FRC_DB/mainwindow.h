#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "databasemanager.h"
#include <QSortFilterProxyModel>
#include "teamwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_fileButton_clicked();

    void on_openButton_clicked();

    void on_refreshButton_clicked();

    void on_teamButton_clicked();

    void on_pitButton_clicked();

private:
    Ui::MainWindow *ui;
    DatabaseManager toast;
    QSortFilterProxyModel *mainModel;
    void populateTable();
    TeamWindow *teams;
    bool isonPit;
};

#endif // MAINWINDOW_H
