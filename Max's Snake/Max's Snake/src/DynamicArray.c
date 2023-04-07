//
//  DynamicArray.c
//  Max's Snake
//
//  Created by Max Raulea on 06/04/2023.
//


#include "DynamicArray.h"
#include <stdlib.h>


void initArray(dArray *blocks, int Size){
    blocks->block = malloc(Size  * sizeof(Block));
    blocks->Size = Size;
    blocks->Lentgh = 1;
}

void AppendBlock(dArray *blocks){
    
    Block block;
    block.direction = '\0';
    block.x = 0;
    block.y = 0;
    
    blocks->Lentgh += 1;
    if (blocks->Lentgh > blocks->Size){
        blocks->Size *= 3/2 + 8;
        blocks->block = realloc(blocks->block, (blocks->Size + 1) * sizeof(Block));
    }
    blocks->block[blocks->Lentgh] = block;
}


/**TODO make a function to free allocated memory**/
