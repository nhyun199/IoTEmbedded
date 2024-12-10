#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "SLL_List.h"

Node *list = NULL;
NodeList *nodeList;

void initialize()
{
    nodeList = (NodeList *)malloc(sizeof(NodeList));
}

void Clear_All_List()
{
    
}

void Dummy_SLL_Creat_10()
{
    list = NULL;
    Node *myNode = NULL;
    for (int i = 0; i < 10; i++)
    {
        myNode = SLL_CreatNode(117 + i * 2);
        SLL_AppendNode(&list, myNode);
    }
}

void Test_SLL_Create(void **state)
{
    Node *myNode = NULL;
    myNode = SLL_CreatNode(117);
    assert_int_equal(myNode->Data, 117);
    assert_int_not_equal(myNode->Data, 116);
}

void Test_SLL_Append(void **state)
{
    Node *myNode = SLL_CreatNode(117);
    SLL_AppendNode(&list, myNode);

    if (!list)
        assert_false(list);
    while (list->NextNode != NULL)
    {
        list = list->NextNode;
    }
    assert_int_equal(list->Data, myNode->Data);
    myNode = SLL_CreatNode(116);
    assert_int_not_equal(list->Data, myNode->Data);
}

void Test_SLL_Search(void **state)
{
    Dummy_SLL_Creat_10();
    Node *data = SLL_Search(list, 125);
    assert_int_equal(data->Data, 125);
    assert_int_not_equal(data->Data, 126);
}

void Test_SLL_Remove(void **state)
{
    Dummy_SLL_Creat_10();
    Node *data = SLL_Search(list, 125);
    SLL_RemoveNode(&list, data);
    assert_non_null(data);
    data =SLL_Search(list, 125);
    assert_null(data);
}

void Test_Memory_Free(void **state)
{
    nodeList = (NodeList *)test_malloc(sizeof(NodeList));
    nodeList->Head = NULL;
    nodeList->Tail = NULL;
    nodeList->Current = NULL;
    test_free(nodeList);
}

void Test_SLL_InsertAfter(void **state)
{
    Dummy_SLL_Creat_10();
    Node *insertLoc = SLL_Search(list, 125);
    Node *newdata = SLL_CreatNode(200);

    Node *data = SLL_Search(list, 200);
    assert_null(data);


    SLL_InsertNode(insertLoc, newdata);
    data = SLL_Search(list, 200);
    assert_non_null(data);

}

void Test_SLL_InsertNewHead(void **state)
{

}

void Test_NodeGetCount(void **state)
{
    Dummy_SLL_Creat_10();
    assert_int_equal(SLL_GetNodeCount(list), 10);
}

int setup(void **state);
int tear_down(void **state);

int main(int argc, char **argv)
{
    const struct CMUnitTest tests[] =
        {
            cmocka_unit_test(Test_SLL_Create),
            cmocka_unit_test(Test_SLL_Append),
            cmocka_unit_test(Test_Memory_Free),
            cmocka_unit_test(Test_SLL_Search),
            cmocka_unit_test(Test_SLL_Remove),
            cmocka_unit_test(Test_SLL_InsertAfter),
            cmocka_unit_test(Test_NodeGetCount),
        };

    return cmocka_run_group_tests(tests, NULL, NULL);
}