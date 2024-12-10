#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "LinkedListStack.h"

LinkedListStack *Stack;

void Test_Push_Pop(void **state)
{
    
}

void Test_IsEmpty(void **state)
{
    
}

void Test_IsFull(void **state)
{
    
}

static int setup(void **state)
{
    LLS_CreateStack(Stack);
    return 0;
}
static int tear_down(void **state)
{
    
    return 0;
}

int main(int argc, char **argv)
{
    const struct CMUnitTest tests[] =
        {
            cmocka_unit_test_setup_teardown(Test_Push_Pop, setup, tear_down),
            cmocka_unit_test_setup_teardown(Test_IsEmpty, setup, tear_down),
            cmocka_unit_test_setup_teardown(Test_IsFull, setup, tear_down),
        };

    return cmocka_run_group_tests(tests, NULL, NULL);
}