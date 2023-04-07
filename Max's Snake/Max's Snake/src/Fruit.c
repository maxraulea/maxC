//
//  Fruit.c
//  Max's Snake
//
//  Created by Max Raulea on 07/04/2023.
//

#include <stdlib.h>
#include "Fruit.h"

Fruit InitFruit(int maxHeight, int  maxWidth){
    
    Fruit fruit;
    
    int x = rand() % maxWidth;
    int y = rand() % maxHeight;
    
    x -= x % 10;
    y -= y % 10;
    
    fruit.x = x;
    fruit.y = y;
    
    printf("fruit x: %d, y: %d \n", x, y);
    return fruit;
}
