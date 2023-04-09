//
//  Fruit.h
//  Max's Snake
//
//  Created by Max Raulea on 07/04/2023.
//

#ifndef Fruit_h
#define Fruit_h

#include <stdio.h>

typedef struct{
    int x;
    int y;
} Fruit;

Fruit InitFruit(int maxHeight, int  maxWidth);

#endif /* Fruit_h */
