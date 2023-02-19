#include "test_list.h"

#include <time.h>
#include <stdlib.h>

const int N_ELEM_MAX   = 1e6;
const int N_ELEM_LIMIT = 1e5;

double testListAll()
{
    List lst;

    double t1 = testList1(&lst),
           t2 = testList2(&lst),
           t3 = testList3(&lst);

    printf("%lg\n%lg\n%lg\n", t1, t2, t3);
    // printf("List:\nTest\tTime\n1\t%lg\n2\t%lg\n3\t%lg\n", t1, t2, t3);
}

double testList1(List *lst)
{
    ListCtor(lst, sizeof(int));

    clock_t t1 = clock();

    int val = 1;
    for (int i = 0; i < N_ELEM_MAX; ++i)
        ListPush(lst, (void*) &val);

    while (lst->size >= N_ELEM_LIMIT)
    {
        for (int i = 0; i < N_ELEM_MAX / 2; ++i)
            ListPop(lst);

        for (int i = 0; i < N_ELEM_MAX / 4; ++i)
            ListPop(lst);
    }

    clock_t t2 = clock();

    ListDtor(lst);

    return 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;
}

double testList2(List *lst)
{
    ListCtor(lst, sizeof(int));

    clock_t t1 = clock();

    int val = 1;
    for (int i = 0; i < N_ELEM_MAX; ++i)
        ListPush(lst, (void*) &val);

    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 10000; ++j)
            ListPop(lst);

        for (int j = 0; j < 10000; ++j)
            ListPush(lst, (void*) &val);
    }

    while (lst->size >= N_ELEM_LIMIT)
    {
        for (int i = 0; i < N_ELEM_MAX / 2; ++i)
            ListPop(lst);

        for (int i = 0; i < N_ELEM_MAX / 4; ++i)
            ListPop(lst);
    }

    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 10000; ++j)
            ListPop(lst);

        for (int j = 0; j < 10000; ++j)
            ListPush(lst, (void*) &val);
    }

    clock_t t2 = clock();

    ListDtor(lst);

    return 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;
}

double testList3(List *lst)
{
    ListCtor(lst, sizeof(int));

    int val = 1;
    for (int i = 0; i < N_ELEM_MAX; ++i)
        ListPush(lst, (void*) &val);

    clock_t t1 = clock();

    for (int i = 0; i < N_ELEM_MAX; ++i)
        if (rand() % 2)
            ListPush(lst, (void*) &val);
        else
            ListPop(lst);

    clock_t t2 = clock();

    ListDtor(lst);

    return 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;
}

