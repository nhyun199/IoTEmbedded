#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "LinkedQueue.h"



void Test_Enqueue_Dequeue(void **state)
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
    
}
static int tear_down(void **state)
{
   
}

int main(int argc, char **argv)
{
    const struct CMUnitTest tests[] =
        {
            //cmocka_unit_test_setup_teardown(Test_Enqueue_Dequeue, setup, tear_down),
            //cmocka_unit_test_setup_teardown(Test_IsEmpty, setup, tear_down),
            //cmocka_unit_test_setup_teardown(Test_IsFull, setup, tear_down),
        };

    return cmocka_run_group_tests(tests, NULL, NULL);
}