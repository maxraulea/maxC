//
//  DynamicArray.h
//  Max's Snake
//
//  Created by Max Raulea on 04/04/2023.
//

#ifndef DynamicArray_h
#define DynamicArray_h

#include "Block.h"
#include <stdlib.h>

typedef struct{
    Block *block;
    int Size;
    int Lentgh;
} dArray;

void initArray(dArray *blocks, int Size){
    blocks->block = malloc(Size * sizeof(Block));
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
        blocks->block = realloc(blocks->block, blocks->Size * sizeof(Block));
    }
    blocks->block[blocks->Lentgh] = block;
}


/**TODO make a function to free allocated memory**/


#endif /* DynamicArray_h */
