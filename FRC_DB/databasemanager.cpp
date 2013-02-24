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
QString DatabaseManager::getPath(){
    return db.databaseName();
}
bool DatabaseManager::readAvgDB(){
    if( db.isOpen() ){
        dbModel->setQuery("select TEAM_NUMBER, avg(TEAM_SCORE), avg(ALLIANCE_SCORE), avg(TEAM_PENALTIES), avg(ALLIANCE_PENALTIES), avg(SHOOTING_STATUS), avg(SHOOTER_ONE_POINT), avg(SHOOTER_TWO_POINT), avg(SHOOTER_THREE_POINT), avg(SHOOTER_FIVE_POINT), avg(SHOOTER_TEAM_PENALTIES), avg(SHOOTER_ALLIANCE_PENALTIES), avg(SHOOTER_ONE_POINT_SHOTS_MADE), avg(SHOOTER_TWO_POINT_SHOTS_MADE), avg(SHOOTER_THREE_POINT_SHOTS_MADE), avg(SHOOTER_FIVE_POINT_SHOTS_MADE), avg(SHOOTER_ONE_POINT_SHOTS_TAKEN), avg(SHOOTER_TWO_POINT_SHOTS_TAKEN), avg(SHOOTER_THREE_POINT_SHOTS_TAKEN), avg(SHOOTER_FIVE_POINT_SHOTS_TAKEN), avg(CLIMBING_STATUS), avg(CLIMBING_LEVEL_ONE), avg(CLIMBING_LEVEL_TWO), avg(CLIMBING_LEVEL_THREE), avg(CLIMBING_SUCESSFUL_CLIMBS), avg(CLIMBING_TOTAL_ATTEMPTS), avg(CLIMBING_TEAM_PENALTIES), avg(CLIMBING_ALLIANCE_PENALTIES), avg(AUTONOMOUS_STATUS), avg(AUTNOMOUS_TEAM_PENALTIES), avg(AUTONOMOUS_ALLIANCE_PENALTIES), avg(AUTONOMOUS_ONE_POINT), avg(AUTONOMOUS_TWO_POINT), avg(AUTONOMOUS_THREE_POINT), avg(AUTONOMOUS_FIVE_POINT), avg(AUTONOMOUS_ONE_POINT_SHOTS_MADE), avg(AUTONOMOUS_TWO_POINT_SHOTS_MADE), avg(AUTONOMOUS_THREE_POINT_SHOTS_MADE), avg(AUTONOMOUS_FIVE_POINT_SHOTS_MADE), avg(AUTONOMOUS_ONE_POINT_SHOTS_TAKEN), avg(AUTONOMOUS_THREE_POINT_SHOTS_TAKEN), avg(AUTONOMOUS_FIVE_POINT_SHOTS_TAKEN), avg(DEFENSE_STATUS), avg(DEFENSE_RANK), avg(CLIMB_ASSIST_STATUS), avg(HUMAN_PLAYER_STATUS), avg(HUMAN_PLAYER_PENALTIES),  avg(HUMAN_PLAYER_SHOTS_MADE),  avg(HUMAN_PLAYER_SHOTS_TAKEN) from Scouting_Data group by TEAM_NUMBER",db);
        return true;
    } else {
        return false;
    }
}
