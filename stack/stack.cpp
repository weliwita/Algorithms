#include<iostream>
#include "stack.h"
#include <assert.h>

using namespace std;


void StackNew(Stack *s){
    s->logicalLen = 0;
    s->allocLen = 4;
    s->elems = (int*)
        malloc(4*sizeof(int));
    assert(s->elems != NULL);
}

void StackDispose(Stack *s)
{
    free(s->elems);
}

void StackPush(Stack *s, int value)
{
    if(s->logicalLen == s->allocLen)
    {
        s->allocLen *= 2;
        s->elems =(int*) realloc(s->elems,
                            s->allocLen*sizeof(int));
        assert(s->elems != NULL);
    }
    s->elems[s->logicalLen] = value;
    s->logicalLen++;
}

int StackPop(Stack *s)
{
    assert(s->logicalLen>0);
    s->logicalLen--;
    return s->elems[s->logicalLen];
}