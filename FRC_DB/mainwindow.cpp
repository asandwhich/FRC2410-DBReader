#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QLineEdit>
#include "databasemanager.h"
#include <QTreeView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setSortingEnabled(true);
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
        //ui->tableWidget->setModel(toast.dbModel);
        ui->tableView->setModel(toast.dbModel);
        //ui->tableView->horizontalHeader()->
        //ui->tableView->show();
    }
}

void MainWindow::on_shootButton_toggled(bool checked)
{
    if( checked ){
        /*toast.dbModel->sort(0, Qt::AscendingOrder );
        ui->tableView->setModel( toast.dbModel );
        ui->debugLabel->setText("chocked");*/
    }
}

void MainWindow::on_winButton_toggled(bool checked)
{
    if( checked ){
        //toast.dbModel->sort( 1, Qt::AscendingOrder );
        //ui->tableView->setModel( toast.dbModel );
        ui->tableView->sortByColumn( 1, Qt::AscendingOrder );
    }

}

void MainWindow::on_shootButton_clicked()
{
    toast.dbModel->sort( 1, Qt::AscendingOrder );
    //ui->tableView->reset();
}
