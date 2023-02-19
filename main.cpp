#include "test_stack.h"
#include "test_list.h"

int main()
{
    for (int i = 0; i < 10; ++i)
    {
        testListAll();
        printf("\n");
    }
    return 0;
}


