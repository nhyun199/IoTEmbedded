#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
	if (*queue == NULL || *back == 0) {}
		//printf("-1\n");
	else
	{
		//printf("%d", (*queue)[0]);
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

void printQueue(int* queue, int back)
{
	for (int i = 0; i < back; i++)
	{
		printf("%d ", queue[i]);
	}
	printf("\n");
}

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	int* queue = NULL;
	int back = 0;	

	for (int i = 1; i <= N; i++)
		push(&queue, &back, i);

	/*printQueue(queue, back);

	if (N == 1 && K == 1)
	{
		printf("<1>");
		return 0;
	}*/

	printf("<");
	while (back > 0)
	{
		for (int i = 0; i < K-1; i++)
		{
			int temp = queue[0];
			pop(&queue, &back);
			push(&queue, &back, temp);
		}
		printf("%d", queue[0]);
		pop(&queue, &back);

		if (back > 0)
			printf(", ");
	}

	printf(">");
	
}