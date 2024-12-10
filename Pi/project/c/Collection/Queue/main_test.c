#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "CircularQueue.h"

CircularQueue* Queue;

void Test_Enqueue_Dequeue(void **state)
{
    assert_int_equal(CQ_GetSize(Queue), 0);
    assert_int_equal(CQ_IsEmpty(Queue), 1);
    CQ_Enqueue(Queue, 10);
    assert_int_equal(CQ_GetSize(Queue), 1);
    assert_int_equal(CQ_Dequeue(Queue), 10);
    assert_int_equal(CQ_GetSize(Queue), 0);
}

void Test_IsEmpty(void **state)
{
    assert_int_equal(CQ_IsEmpty(Queue), 1);
    CQ_Enqueue(Queue, 10);
    assert_int_equal(CQ_IsEmpty(Queue), 0);
}

void Test_IsFull(void **state)
{
    for(int i = 0; i < 10; i++)
    {
        CQ_Enqueue(Queue, i);
    }

    assert_int_equal(CQ_IsFull(Queue), 1);
    CQ_Dequeue(Queue);
    assert_int_equal(CQ_IsFull(Queue), 0);
}

static int setup(void **state)
{
    CQ_CreateQueue(&Queue, 10);
    return 0;
}
static int tear_down(void **state)
{
    CQ_DestroyQueue(Queue);
    return 0;
}

int main(int argc, char **argv)
{
    const struct CMUnitTest tests[] =
        {
            cmocka_unit_test_setup_teardown(Test_Enqueue_Dequeue, setup, tear_down),
            cmocka_unit_test_setup_teardown(Test_IsEmpty, setup, tear_down),
            cmocka_unit_test_setup_teardown(Test_IsFull, setup, tear_down),
        };

    return cmocka_run_group_tests(tests, NULL, NULL);
}