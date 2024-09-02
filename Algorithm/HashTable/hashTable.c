#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef unsigned int u_int;

typedef struct Node 
{
	char* key; // hash 함수를 통해 암호화
	int value; // 입력을 원하는 데이터
	struct Node* next; // 다음 노드를 가리키는 주소
} Node;

Node *hashTable[TABLE_SIZE];

u_int hash(char* key)
{
	u_int hashvalue = 0;
	for (int i = 0; key[i] != '\0'; i++)
	{
		hashvalue += key[i];
		hashvalue *= key[i];
	}
	return hashvalue % TABLE_SIZE;
}

void insert(char* key, int value) // 해시 충돌 고려하지 않음
{
	u_int hashindex = hash(key);
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->key = strdup(key);
	newnode->value = value;
	newnode->next = newnode;
}