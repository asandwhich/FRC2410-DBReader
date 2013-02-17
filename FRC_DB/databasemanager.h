#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
//#include <QtSql>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQueryModel>
//#include <QtSql/QSqlDatabase>
//#include <QtSql/QSqlDriver>
//#include <QtSql/QSql>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = 0);
    ~DatabaseManager();
    bool openDB(QString path);
    QSqlQueryModel *dbModel;
    bool readDB();
signals:
    
public slots:

private:
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
