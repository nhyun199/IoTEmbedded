#include <stdio.h>

typedef struct _FOOD
{
	int nPrice;
	int nCookTime;
	char Name[20];
	struct FOOD* Next;
} FOOD;

void AddNode()
{
	// 현재 노드 중 마지막 노드가 누구인가?
	// 현재 NULL인 노드를 찾으면되나?
}

int main()
{
	FOOD food[3] =
	{
		{3000, 5, "Ramen", NULL},
		{1500, 5, "Gimbab", NULL},
		{2500, 10, "Mandu", NULL}
	};

	//FOOD* Head = NULL; // 시작노드 Head ?

	//Head = &food[0];
	food[0].Next = &food[1];
	food[1].Next = &food[2];
	food[2].Next = NULL;
		
}