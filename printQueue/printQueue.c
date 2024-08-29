#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void push(int** queue, int* back, int X)
{
	if (*queue == NULL || *back == 0)
	{
		*queue = (int*)malloc(sizeof(int));
	}
	else
	{
		*queue = (int*)realloc(*queue, (*back + 1) * sizeof(int));
	}
	(*queue)[*back] = X;
	(*back)++;
}

void pop(int** queue, int* back)
{
	if (*queue == NULL || *back == 0)
		//printf("-1\n");
	else
	{
		//printf("%d\n", (*queue)[0]);
		(*back)--;

		if (*back == 0)
		{
			free(*queue);
			*queue = NULL;
		}

		else
		{
			for (int i = 0; i < (*back); i++)
			{
				(*queue)[i] = (*queue)[i + 1];
			}
			*queue = (int*)realloc(*queue, (*back) * sizeof(int));
		}
	}
}

void printqueue(int* queue, int back)
{
	for (int i = 0; i < back; i++)
	{
		printf("%d ", queue[i]);
	}
	printf("\n");
}

int main()
{
	int* queue = NULL;
	int back = 0;
	int n, m;
	int print;
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		push(&queue, &back, num);
	}
	printqueue(queue, back);
	
	// 큰 수가 있는 지 탐색한다.
	// 큰 수가 있다 -> pop push
	// 큰 수가 없다 -> pop
	// 요소가 하나라면 바로 pop


}