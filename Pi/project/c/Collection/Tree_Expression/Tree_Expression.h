#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Element;
typedef struct _ExpNode
{
    struct _ExpNode *Left;
    struct _ExpNode *Right;
    Element Data;
} ExpNode;

ExpNode *Exp_CreatNode(Element NewData);
void Exp_DestroyNode(ExpNode *Node);
void Exp_DestroyTree(ExpNode *Root);
void Exp_BuildTree(char *Postfix, ExpNode **Node);
double Exp_EvaluateTree(ExpNode *Tree);
void PreorderPrintTree(ExpNode *Root);
void InorderPrintTree(ExpNode *Root);
void PostorderPrintTree(ExpNode *Root);