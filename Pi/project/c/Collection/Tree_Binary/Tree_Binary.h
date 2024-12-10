#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct _BinaryNode
{
    struct _BinaryNode *Left;
    struct _BinaryNode *Right;
    Element Data;
} BinaryNode;

BinaryNode *Binary_Create(Element NewData);
void Binary_DestroyNode(BinaryNode *Node);