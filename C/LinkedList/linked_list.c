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
	// ���� ��� �� ������ ��尡 �����ΰ�?
	// ���� NULL�� ��带 ã����ǳ�?
}

int main()
{
	FOOD food[3] =
	{
		{3000, 5, "Ramen", NULL},
		{1500, 5, "Gimbab", NULL},
		{2500, 10, "Mandu", NULL}
	};

	//FOOD* Head = NULL; // ���۳�� Head ?

	//Head = &food[0];
	food[0].Next = &food[1];
	food[1].Next = &food[2];
	food[2].Next = NULL;
		
}