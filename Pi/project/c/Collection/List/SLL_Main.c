#include <stdio.h>
#include <stdlib.h>
#include "SLL_List.h"

void SLL_PrintAllNode(const Node* list);
void SLL_PrintAllNodeList(NodeList* list);

int main()
{
    Node* list = NULL;
    NodeList* nodelist = (NodeList*)malloc(sizeof(NodeList));
    Node* myNode = NULL;
    
    for(int i = 0; i < 10; i++)
    {
        myNode = SLL_CreatNode(100 + i*2);
        SLL_AppendNode(&list, myNode);
    }
    
    printf("Node 구조체 크기: %zu 바이트\n", sizeof(Node));
    SLL_PrintAllNode(list);

}

void SLL_PrintAllNode(const Node *list)
{
    while(list != NULL)
    {
        printf("%p : %d\n", list, list->Data);
        list = list->NextNode;
    }
}

void SLL_PrintAllNodeList(NodeList *list)
{
    list->Current = list->Head;
    while(list->Current != NULL)
    {
        printf("%p : %d\n", list->Current, list->Current->Data);
        list->Current = list->Current->NextNode;
    }
}
