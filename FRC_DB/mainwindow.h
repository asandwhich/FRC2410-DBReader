#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "databasemanager.h"
#include <QSortFilterProxyModel>

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

private:
    Ui::MainWindow *ui;
    DatabaseManager toast;
    QSortFilterProxyModel *mainModel;
    void populateTable();
};

#endif // MAINWINDOW_H
