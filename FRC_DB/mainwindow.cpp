#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QLineEdit>
#include "databasemanager.h"
#include <QTreeView>
#include <QSortFilterProxyModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_fileButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open DB"),"",tr("Files (*.db*)"));
    ui->lineEdit->setText(filePath);
}

void MainWindow::on_openButton_clicked()
{
    QString filePath = ui->lineEdit->text();

    if( filePath != "" ){
        if( toast.openDB( filePath ) ){
            ui->debugLabel->setText("Database opened");
            MainWindow::populateTable();
        }else{
            ui->debugLabel->setText("Unable to open database");
        }
    } else {
        ui->debugLabel->setText("Path is empty");
    }
}

void MainWindow::populateTable(){
    if( toast.readDB() ){
        mainModel = new QSortFilterProxyModel(this);
        mainModel->setSourceModel(toast.dbModel);
        ui->tableView->setModel(mainModel);
    }
}

void MainWindow::on_refreshButton_clicked()
{
    ui->tableView->reset();
}
