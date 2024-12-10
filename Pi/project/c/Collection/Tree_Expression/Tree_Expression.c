#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree_Expression.h"

ExpNode *Exp_CreatNode(Element NewData)
{
    ExpNode *NewNode = (ExpNode *)malloc(sizeof(ExpNode));
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

void Exp_DestroyNode(ExpNode *Node)
{
    free(Node);
}

void Exp_DestroyTree(ExpNode *Root)
{
    if (Root == NULL)
        return;

    
    Exp_DestroyTree(Root->Left);    
    Exp_DestroyTree(Root->Right);

    Exp_DestroyNode(Root);
}

void Exp_BuildTree(char *Postfix, ExpNode **Node)
{
    int len = strlen(Postfix);
    char token = Postfix[len - 1];
    Postfix[len - 1] = '\0';

    switch (token)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        (*Node) = Exp_CreatNode(token);
        Exp_BuildTree(Postfix, &(*Node)->Right);
        Exp_BuildTree(Postfix, &(*Node)->Left);
        break;

    default:
        (*Node) = Exp_CreatNode(token);
        break;
    }
}

double Exp_EvaluateTree(ExpNode *Tree)
{
    char temp[2];
    double Left = 0;
    double Right = 0;
    double Result = 0;

    if (Tree == NULL)
        return 0;

    switch (Tree->Data)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        Left = Exp_EvaluateTree(Tree->Left);
        Right = Exp_EvaluateTree(Tree->Right);

        if (Tree->Data == '+')
            Result = Left + Right;
        else if (Tree->Data == '-')
            Result = Left - Right;
        else if (Tree->Data == '*')
            Result = Left * Right;
        else if (Tree->Data == '/')
            Result = Left / Right;
        break;

    default:
        memset(temp, 0, sizeof(temp));
        temp[0] = Tree->Data;
        Result = atof(temp);
        break;
    }

    return Result;
}

void PreorderPrintTree(ExpNode *Root)
{
    if (Root == NULL)
        return;

    printf("%c", Root->Data);
    PreorderPrintTree(Root->Left);
    PreorderPrintTree(Root->Right);
}

void InorderPrintTree(ExpNode *Root)
{
    if (Root == NULL)
        return;

    InorderPrintTree(Root->Left);
    printf("%c", Root->Data);
    InorderPrintTree(Root->Right);
}

void PostorderPrintTree(ExpNode *Root)
{
    if (Root == NULL)
        return;

    PostorderPrintTree(Root->Left);
    PostorderPrintTree(Root->Right);
    printf("%c", Root->Data);
}
