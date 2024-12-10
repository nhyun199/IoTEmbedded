#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct _BSTNode
{
    struct _BSTNode *Left;
    struct _BSTNode *Right;
    Element Data;
} BSTNode;

BSTNode *BST_CreatNode(Element NewData);
BSTNode *BST_SearchNode(BSTNode *Tree, Element Target);
BSTNode *BST_SearchMinNode(BSTNode *Tree);
BSTNode *BST_RemoveNode(BSTNode *Tree, BSTNode *Parent, Element Target);
void BST_InsertNode(BSTNode *Tree, BSTNode *Child);
