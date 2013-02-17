#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "databasemanager.h"

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

    void on_shootButton_toggled(bool checked);

    void on_winButton_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    DatabaseManager toast;
    void populateTable();
};

#endif // MAINWINDOW_H
