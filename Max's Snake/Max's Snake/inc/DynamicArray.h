//
//  DynamicArray.h
//  Max's Snake
//
//  Created by Max Raulea on 04/04/2023.
//

#ifndef DynamicArray_h
#define DynamicArray_h

#include "Block.h"

typedef struct{
    Block *block;
    int Size;
    int Lentgh;
} dynamicArray;

dynamicArray* InitArray(dynamicArray *blocks);

dynamicArray* AppendBlock(dynamicArray *blocks);

/**TODO make a function to free allocated memory**/

#endif /* DynamicArray_h */
