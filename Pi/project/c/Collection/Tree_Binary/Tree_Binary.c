#include <stdio.h>
#include <stdlib.h>
#include "Tree_Binary.h"

BinaryNode *Binary_Create(Element NewData)
{
    BinaryNode *NewNode = (BinaryNode*)malloc(sizeof(BinaryNode));
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

void Binary_DestroyNode(BinaryNode *Node)
{
    free(Node);
}

