#include "test_stack.h"

#include <time.h>
#include <stdlib.h>

const int N_ELEM_MAX   = 1e6;
const int N_ELEM_LIMIT = 1e5;

double testStackAll()
{
    Stack stk;

    double t1 = testStack1(&stk),
           t2 = testStack2(&stk),
           t3 = testStack3(&stk);

    printf("Stack:\nTest\tTime\n1\t%lg\n2\t%lg\n3\t%lg\n", t1, t2, t3);
}

double testStack1(Stack *stk)
{
    StackCtor(stk, 42, sizeof(int));

    clock_t t1 = clock();

    int val = 1;
    for (int i = 0; i < N_ELEM_MAX; ++i)
        StackPush(stk, (void*) &val);

    while (stk->size >= N_ELEM_LIMIT)
    {
        for (int i = 0; i < N_ELEM_MAX / 2; ++i)
            StackPop(stk);

        for (int i = 0; i < N_ELEM_MAX / 4; ++i)
            StackPop(stk);
    }

    clock_t t2 = clock();

    StackDtor(stk);

    return 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;
}

double testStack2(Stack *stk)
{
    StackCtor(stk, 42, sizeof(int));

    clock_t t1 = clock();

    int val = 1;
    for (int i = 0; i < N_ELEM_MAX; ++i)
        StackPush(stk, (void*) &val);

    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 10000; ++j)
            StackPop(stk);

        for (int j = 0; j < 10000; ++j)
            StackPush(stk, (void*) &val);
    }

    while (stk->size >= N_ELEM_LIMIT)
    {
        for (int i = 0; i < N_ELEM_MAX / 2; ++i)
            StackPop(stk);

        for (int i = 0; i < N_ELEM_MAX / 4; ++i)
            StackPop(stk);
    }

    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 10000; ++j)
            StackPop(stk);

        for (int j = 0; j < 10000; ++j)
            StackPush(stk, (void*) &val);
    }

    clock_t t2 = clock();

    StackDtor(stk);

    return 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;
}

double testStack3(Stack *stk)
{
    StackCtor(stk, 42, sizeof(int));

    int val = 1;
    for (int i = 0; i < N_ELEM_MAX; ++i)
        StackPush(stk, (void*) &val);

    clock_t t1 = clock();

    for (int i = 0; i < N_ELEM_MAX; ++i)
        if (rand() % 2)
            StackPush(stk, (void*) &val);
        else
            StackPop(stk);

    clock_t t2 = clock();

    StackDtor(stk);

    return 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;
}
