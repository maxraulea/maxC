//
//  CollisionFruit.c
//  Max's Snake
//
//  Created by Max Raulea on 07/04/2023.
//

#include "CollisionFruit.h"

int IsCollisionWithFruit(dynamicArray *snake, Fruit fruit){
    
    if (snake->block[0].x == fruit.x && snake->block[0].y == fruit.y){
        return 1;
    }
    return 0;
}
