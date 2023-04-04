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
    int Used;
} dArray;

void initArray(dArray *blocks, int Size){
    blocks->block = malloc(Size * sizeof(Block));
    blocks->Size = Size;
    blocks->Used = 0;
}

void AppendBlock(dArray *blocks, Block block){
    if (blocks->Used > blocks->Size){
        
    }
}
#endif /* DynamicArray_h */
