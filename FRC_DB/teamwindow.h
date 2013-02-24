#ifndef TEAMWINDOW_H
#define TEAMWINDOW_H

#include <QMainWindow>
#include <QSortFilterProxyModel>
#include "databasemanager.h"

namespace Ui {
class TeamWindow;
}

class TeamWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit TeamWindow(QWidget *parent = 0);
    void setPath( QString path );
    ~TeamWindow();
    void start();
    void populateTable();

private:
    Ui::TeamWindow *ui;
    DatabaseManager teamToast;
    QString dbPath;
};

#endif // TEAMWINDOW_H
