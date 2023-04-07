//
//  CollisionSelf.c
//  Max's Snake
//
//  Created by Max Raulea on 07/04/2023.
//

#include "CollisionSelf.h"

int IsCollisionWithSelf(dArray *snake){
    
    for (int i = 1; i < snake->Lentgh; i++){
        if (snake->block[0].x == snake->block[i].x && snake->block[0].y == snake->block[i].y){
            return 1;
        }
    }
    return 0;
}
