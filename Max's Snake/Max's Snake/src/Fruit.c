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
    
    int xPosition = rand() % (maxWidth - 20);
    int yPosition = rand() % (maxHeight - 20);
    
    xPosition -= xPosition % 10;
    yPosition -= yPosition % 10;
    
    fruit.x = xPosition + 10;
    fruit.y = yPosition + 10;
    
    return fruit;
}
