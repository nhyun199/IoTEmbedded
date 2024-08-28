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
	{
		push(&queue, &back, i);
	}

	printf("<");
	while (back > K-1)
	{
		for (int i = 0; i < K; i++)
		{
			int temp = 0;
			if (i != K - 1)
			{
				temp = queue[0];
				pop(&queue, &back);
				push(&queue, &back, temp);
			}
			else if (i == K - 1)
			{
				printf("%d, ", queue[0]);
				pop(&queue, &back);
			}
		}
	}
	for (int i = 0; i < back; i++)
	{
		if (i == back - 1)
			printf("%d", queue[i]);
		else
			printf("%d, ",queue[i]);
	}
	printf(">");
}