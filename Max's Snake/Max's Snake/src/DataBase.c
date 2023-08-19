//
//  DataBase.c
//  Max's Snake
//
//  Created by Max Raulea on 19/08/2023.
//

#include "DataBase.h"
#include "sqlite3.h"

//use threads to write the data to the database
int InitDataBase(sqlite3* dataBase){
    sqlite3_stmt* statement;
    
    if(sqlite3_open("scores.db", &dataBase) != SQLITE_OK){
        return 1;
    }
    
    if(sqlite3_prepare_v2(dataBase, "CREATE TABLE IF NOT EXISTS scores(id INTEGER PRIMARY KEY,user CHAR(100) NOT NULL,score INTEGER NOT NULL)"
       , -1, &statement, 0)!= SQLITE_OK){
        printf("\nFailed to create table: %s", sqlite3_errmsg(dataBase));
        return 1;
    }
    
    
    return 0;
}

int InsertScore(GameOutput gameOutput){
    sqlite3_stmt* statement;
    
    return 0;
}

int GetScore(sqlite3* dataBase, int ranking){
    return 0;
}

int CloseDB(sqlite3* database){
    if(sqlite3_close(database) != SQLITE_OK){
        return 1;
    }
    return 0;
}
