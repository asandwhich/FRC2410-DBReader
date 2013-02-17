#include "databasemanager.h"
//#include <QtSql/QSql>
//#include <QtSql/QSqlDatabase>
//#include <QSql>
//#include <QSqlDatabase>
//#include <QtSql/QSqlDriver>
//#include <QtSql/QSql>
DatabaseManager::DatabaseManager(QObject *parent) :
    QObject(parent)
{
    dbModel = new QSqlQueryModel;
}
DatabaseManager::~DatabaseManager(){

}

bool DatabaseManager::openDB(QString path){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    return db.open();
}
bool DatabaseManager::readDB(){
    if( db.isOpen() ){
        //dbModel = new QSqlQueryModel;
        dbModel->setQuery("select * from test", db);
        return true;
    } else {
        return false;
    }
}
