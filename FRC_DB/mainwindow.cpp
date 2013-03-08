#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QLineEdit>
#include "databasemanager.h"
#include <QTreeView>
#include <QSortFilterProxyModel>
#include "teamwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isonPit = false;
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
            ui->pitButton->setEnabled(true);
        } else {
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
    MainWindow::on_openButton_clicked();
}

void MainWindow::on_teamButton_clicked()
{
    teams = new TeamWindow(this);
    teams->show();
    teams->setPath( toast.getPath() );
    teams->start();
}

void MainWindow::on_pitButton_clicked()
{
    if( !isonPit ){
        toast.dbModel->setQuery("select * from Pit_Data");
        mainModel = new QSortFilterProxyModel(this);
        mainModel->setSourceModel(toast.dbModel);
        ui->tableView->setModel(mainModel);
        ui->pitButton->setText("Match Data");
        isonPit = true;
    } else {
        toast.dbModel->setQuery("select * from Match_Data");
        mainModel = new QSortFilterProxyModel(this);
        mainModel->setSourceModel(toast.dbModel);
        ui->tableView->setModel(mainModel);
        ui->pitButton->setText("Pit Data");
        isonPit = false;
    }
}
