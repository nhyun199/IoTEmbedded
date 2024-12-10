#include <stdio.h>

typedef char Element;
typedef struct _LCRSNode
{
    struct _LCRSNode *LeftChild;    // 왼쪽 자식
    struct _LCRSNode *RightSibling; // 오른쪽 형제
    Element Data;
} LCRSNode;

LCRSNode *LCRS_CreateNode(Element NewData);
void LCRS_DestroyNode(LCRSNode *Node);
void LCRS_DestroyTree(LCRSNode *Node);
void LCRS_AddChildNode(LCRSNode *Parent, LCRSNode *Child);
void LCRS_PrintTree(LCRSNode *Node, int Depth);