#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LCRS_Tree.h"

LCRSNode *LCRS_CreateNode(Element NewData)
{
    LCRSNode *NewNode = (LCRSNode *)malloc(sizeof(LCRSNode));
    NewNode->LeftChild = NULL;
    NewNode->RightSibling = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

void LCRS_DestroyNode(LCRSNode *Node)
{
    free(Node);
}

void LCRS_DestroyTree(LCRSNode *Root)
{
    if (Root->LeftChild != NULL)
        LCRS_DestroyTree(Root->LeftChild);
    if (Root->RightSibling != NULL)
        LCRS_DestroyTree(Root->RightSibling);

    Root->LeftChild = NULL;
    Root->RightSibling = NULL;
    LCRS_DestroyNode(Root);
}

void LCRS_AddChildNode(LCRSNode *Parent, LCRSNode *Child)
{
    if (Parent->LeftChild == NULL)
        Parent->LeftChild = Child;
    else
    {
        LCRSNode *TempNode = Parent->LeftChild;
        while (TempNode->RightSibling != NULL)
        {
            TempNode = TempNode->RightSibling;
        }
        TempNode->RightSibling = Child;
    }
}

void LCRS_PrintTree(LCRSNode *Node, int Depth)
{
    int i = 0;
    for (i = 0; i < Depth - 1; i++)
        printf("   ");
    if (Depth > 0)
        printf("+--");

    printf("%c\n", Node->Data);

    if (Node->LeftChild != NULL)
        LCRS_PrintTree(Node->LeftChild, Depth + 1);
    if (Node->RightSibling != NULL)
        LCRS_PrintTree(Node->RightSibling, Depth);
}
