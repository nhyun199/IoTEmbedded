#include "SLL_List.h"
#include <stdlib.h>

Node *SLL_CreatNode(Element newData)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->Data = newData;
    newNode->NextNode = NULL;

    return newNode;
}

void SLL_DestroyNode(Node* node)
{
    free(node);
}

void SLL_AppendNode(Node **head, Node *newNode)
{
    if((*head) == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node* tail = (*head);
        while(tail->NextNode != NULL)
        {
            tail = tail->NextNode;
        }
        tail->NextNode = newNode;
    }
}

void SLL_AppendNodeList(NodeList *list, Node *newNode)
{
    if(list->Head == NULL)
    {
        list->Head = newNode;
        list->Tail = newNode;
    }
    else
    {
        list->Tail->NextNode = newNode;
        list->Tail = newNode;
    }
}

Node* SLL_Search(Node *head, int value)
{
    while(head && head->Data != value)
    {
        head = head->NextNode;
    }
    return head;
}

Node* SLL_SearchNodeList(NodeList *list, int value)
{
    while(list->Head && list->Head->Data != value)
    {
        list->Head = list->Head->NextNode;
    }
    return list->Head;
}

void SLL_RemoveNode(Node **head, Node *remove)
{
    if(*head == remove)
    {
        *head = remove->NextNode;
        SLL_DestroyNode(remove);
    }
    else
    {
        Node* current = *head;
        while(current != NULL && current->NextNode != remove)
        {
            current = current->NextNode;
        }

        if(current != NULL)
        {
            current->NextNode = remove->NextNode;
            SLL_DestroyNode(remove);
        }
    }
}

void SLL_RemoveNodeList(NodeList *list, Node *remove)
{
    if(list->Head == remove)
        list->Head = remove->NextNode;
    else
    {
        Node* current = list->Head;
        while(current != NULL && current->NextNode != remove)
        {
            current = current->NextNode;
        }

        if(current != NULL)
            current->NextNode = remove->NextNode;
    }
}

void SLL_InsertNode(Node *current, Node *newNode)
{
    newNode->NextNode = current->NextNode;
    current->NextNode = newNode;
}


void SLL_InsertNewHead(Node** head, Node* newHead)
{
    if ( head == NULL )
    {
        (*head) = newHead;    
    }
    else
    {
        newHead->NextNode = (*head);
        (*head) = newHead;
    }
}

int SLL_GetNodeCount(Node* Head)
{
    int   Count = 0;
    Node* Current = Head;

    while ( Current != NULL )
    {
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}


