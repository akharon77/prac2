#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdint.h>

struct Stack
{
    size_t  size;
    size_t  capacity;
    size_t  elemSize; 

    void   *data;
};

void StackCtor       (Stack *stk, size_t capacity, size_t elemSize);
void StackDtor       (Stack *stk);
bool StackPush       (Stack *stk, void *elem);
bool StackTop        (Stack *stk, void *elem);
bool StackPop        (Stack *stk);
bool StackIncSize    (Stack *stk);
bool StackDupRealloc (Stack *stk);

#endif  // STACK_H
