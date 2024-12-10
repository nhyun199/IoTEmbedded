#include <stdbool.h>

typedef int Element;

typedef struct _Node
{
    Element Data;           // 저장할 데이터
    struct _Node *NextNode; // 다음 노드를 가르키는 포인터
} Node;

typedef struct _NodeList
{
    Node *Head;
    Node *Tail;
    Node *Current;
} NodeList;

Node *SLL_CreatNode(Element newData);
void SLL_DestroyNode(Node *node);
void SLL_AppendNode(Node **head, Node *newNode);
void SLL_AppendNodeList(NodeList *nodeList, Node *newNode);
Node *SLL_SearchNodeList(NodeList *nodeList, int value);
Node *SLL_Search(Node *head, int value);
void SLL_RemoveNode(Node **head, Node *remove);
void SLL_RemoveNodeList(NodeList *list, Node *remove);
void SLL_InsertNode(Node *current, Node *newNode);
void SLL_InsertNewHead(Node **head, Node *newHead);
int SLL_GetNodeCount(Node *Head);
Node *SLL_SequentialSearch(Node *Head, int Target);
Node *SLL_Search_MoveToFront(Node **Head, int Target);
Node *SLL_Search_Transpose(Node **Head, int Target);
