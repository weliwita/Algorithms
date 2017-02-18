#include<iostream>
#include "stack.h"
#include <assert.h>

using namespace std;

// create stack with 4 elements, each element can be different primitive variables
// if int elemsize is 4 bytes, if double elemsize is 8 bytes
void StackNew(Stack *s, int elemSize){
    assert(s->elemSize > 0);
    s->elemSize = elemSize;
    s->logicalLen = 0;
    s->allocLen = 4;
    s->elems = malloc(4*elemSize);
    assert(s->elems != NULL);
}

void StackDispose(Stack *s)
{
    free(s->elems);
}

// internal/private??
static void StackGrow(Stack *s)
{
    s-> allocLen *=2;
    s->elems = realloc(s->elems, s->allocLen * s->elemSize);
}

void StackPush(Stack *s, void* elemAddr)
{
    if(s->logicalLen == s->allocLen)
    {
        StackGrow(s);
    }

    void *target = (char*) s->elems + s->logicalLen * s->elemSize;
    memcpy(target, elemAddr, s->elemSize);
    s->logicalLen++;
}

void StackPop(Stack *s, void *elemAddr)
{
    void *source = (char*) s->elems + (s->logicalLen - 1) * s->elemSize;
    
    memcpy(elemAddr, source, s->elemSize);

    s->logicalLen--;
}