#include <stdlib.h>
#include "BinarySearchTree.h"

BSTNode *BST_CreatNode(Element NewData)
{
    BSTNode *NewNode = (BSTNode*)malloc(sizeof(BSTNode));
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

BSTNode *BST_SearchNode(BSTNode *Tree, Element Target)
{
    if(Tree == NULL)
        return NULL;
    
    if(Tree->Data == Target)
        return Tree;
    else if(Tree->Data > Target)
        return BST_SearchNode(Tree->Left, Target);
    else
        return BST_SearchNode(Tree->Right, Target);
}

BSTNode *BST_SearchMinNode(BSTNode *Tree)
{
    if(Tree == NULL) return NULL;

    if(Tree->Left == NULL) return Tree;
    else return BST_SearchMinNode(Tree->Left);
}

BSTNode *BST_RemoveNode(BSTNode *Tree, BSTNode *Parent, Element Target)
{
    BSTNode *Removed = NULL;

    if(Tree == NULL) return NULL;

    if(Tree->Data > Target)
        Removed = BST_RemoveNode(Tree->Left, Tree, Target);
    else if(Tree->Data < Target)
        Removed = BST_RemoveNode(Tree->Right, Tree, Target);
    else
    {
        Removed = Tree;

        if(Tree->Left == NULL && Tree->Right == NULL)
        {
            BSTNode *MinNode = BST_SearchMinNode(Tree->Right);
            MinNode = BST_RemoveNode(Tree, NULL, MinNode->Data);
            Tree->Data = MinNode->Data;
        }
    }
}

void BST_InsertNode(BSTNode *Tree, BSTNode *Child)
{
    if(Tree->Data > Child->Data)
    {
        if(Tree->Left == NULL)
            Tree->Left == Child;
        else
            BST_InsertNode(Tree->Left, Child);
    }
    else
    {
        if(Tree->Right == NULL)
            Tree->Right == Child;
        else
            BST_InsertNode(Tree->Right, Child);
    }
}
