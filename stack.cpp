#include "stack.h"

#include <time.h>
#include <stdlib.h>
#include <string.h>

void StackCtor(Stack *stk, size_t capacity, size_t elemSize)
{
    void *data = calloc(capacity, elemSize);

    stk->data       = data;
    stk->size       = 0;
    stk->capacity   = capacity;
    stk->elemSize   = elemSize;
}

void StackDtor(Stack *stk)
{
    free(stk->data);
}

bool StackPush(Stack *stk, void *elem)
{
    bool res = StackIncSize(stk);
    memcpy((char*) stk->data + stk->elemSize * (stk->size - 1), elem, stk->elemSize);

    return res;
}

bool StackTop(Stack *stk, void *elem)
{
    if (stk->size == 0)
        return false;

    memcpy(elem, (char*) stk->data + stk->elemSize * (stk->size - 1), stk->elemSize);
    return true;
}

bool StackPop(Stack *stk)
{
    if (stk->size == 0)
        return false;

    --stk->size;
    return true;
}

bool StackIncSize(Stack *stk)
{
    ++stk->size;
    if (stk->size > stk->capacity)
        return StackDupRealloc(stk);

    return true;
}

bool StackDupRealloc(Stack *stk)
{
    stk->capacity *= 2;

    void *newData = realloc(stk->data, stk->elemSize * stk->capacity);
    if (newData == NULL)
        return false;

    stk->data = newData;
    return true;
}

