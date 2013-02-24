#include "teamwindow.h"
#include "ui_teamwindow.h"

TeamWindow::TeamWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TeamWindow)
{
    ui->setupUi(this);
}

TeamWindow::~TeamWindow()
{
    delete ui;
}
void TeamWindow::setPath( QString path )
{
    dbPath = path;
}
void TeamWindow::start(){

    if( dbPath != "" ){
        if( teamToast.openDB(dbPath) ){
            ui->dbLabel->setText( dbPath );
            TeamWindow::populateTable();
        } else {
            ui->dbLabel->setText("Load the database before checking Teams");
        }
    } else {
        ui->dbLabel->setText("Load the database before checking Teams");
    }
}
void TeamWindow::populateTable(){
    if( teamToast.readAvgDB() ){
        QSortFilterProxyModel *teamModel= new QSortFilterProxyModel(this);
        teamModel->setSourceModel(teamToast.dbModel);
        ui->tableView->setModel(teamModel);
    }
}
