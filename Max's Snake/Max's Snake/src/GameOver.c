//
//  GameOver.c
//  Max's Snake
//
//  Created by Max Raulea on 06/04/2023.
//

#include "GameOver.h"
#include "CollisionSelf.h"
#include "CollisionWall.h"

int IsGameOver(dArray *snake, int maxHeight, int maxWidth){
    
    if(IsCollisionWithSelf(snake) || IsCollisionWithWall(snake, maxHeight, maxWidth)){
        return 1;
    }
    return 0;
}
