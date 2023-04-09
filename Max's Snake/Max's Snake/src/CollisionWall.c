//
//  CollisionWall.c
//  Max's Snake
//
//  Created by Max Raulea on 07/04/2023.
//

#include "CollisionWall.h"

int IsCollisionWithWall(dynamicArray *snake, int maxHeight, int maxWidth){
    
    if (snake->block[0].y < 0 || snake->block[0].y > maxHeight){
        return 1;
    }
    
    if (snake->block[0].x < 0 || snake->block[0].x > maxWidth){
        return 1;
    }
    return 0;
}
