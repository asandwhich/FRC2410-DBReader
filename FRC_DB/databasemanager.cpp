#include "databasemanager.h"

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
        dbModel->setQuery("select * from Scouting_Data", db);
        return true;
    } else {
        return false;
    }
}
