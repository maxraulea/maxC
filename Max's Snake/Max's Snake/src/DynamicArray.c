//
//  DynamicArray.c
//  Max's Snake
//
//  Created by Max Raulea on 06/04/2023.
//


#include "DynamicArray.h"
#include <stdlib.h>

const int MEM_BATCH_SIZE = 32;

dynamicArray* InitArray(dynamicArray *blocks){
    if(!(blocks->block = malloc(MEM_BATCH_SIZE * sizeof(Block)))){
        return NULL;
    }
    blocks->Size = MEM_BATCH_SIZE;
    blocks->Lentgh = 1;
    return blocks;
}

dynamicArray* AppendBlock(dynamicArray *blocks){
    
    Block block;
    block.direction = '\0';
    block.x = 0;
    block.y = 0;
        
    if (blocks->Size - blocks->Lentgh < 1){
        if(!(blocks->block = realloc(blocks->block, (blocks->Size + MEM_BATCH_SIZE) * sizeof(Block)))){
            return NULL;
        }
        blocks->Size += MEM_BATCH_SIZE;
    }
    
    blocks->block[blocks->Lentgh] = block;
    blocks->Lentgh += 1;
    return blocks;
}


/**TODO make a function to free allocated memory**/
