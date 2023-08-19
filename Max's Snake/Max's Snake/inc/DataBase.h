//
//  DataBase.h
//  Max's Snake
//
//  Created by Max Raulea on 19/08/2023.
//

#ifndef DataBase_h
#define DataBase_h

#include <stdio.h>
#include "sqlite3.h"

typedef struct{
    sqlite3* dataBase;
    int score;
    char* userName;
} GameOutput;

typedef struct{
    int score;
    char* userName;
} UserScore;

int InitDataBase(sqlite3* dataBase);

int InsertScore(GameOutput gameOutput);

int CloseDB(sqlite3* database);
#endif /* DataBase_h */
