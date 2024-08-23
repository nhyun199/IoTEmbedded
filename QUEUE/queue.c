#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void push(int **queue, int *back, int X) 
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

void pop(int **queue, int *back)
{
	if (*queue == NULL || *back == 0)
		printf("-1\n");
	else
	{
		printf("%d\n", (*queue)[0]);
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

void size(int back) 
{
	printf("%d\n", back);
}

void empty(int *queue, int back) 
{
	if (queue == NULL || back == 0)
		printf("1\n");
	else
		printf("0\n");
}

void Front(int *queue, int back) 
{
	if (queue == NULL || back == 0)
		printf("-1\n");
	else
		printf("%d\n", queue[0]);
}

void Back(int *queue, int back) 
{
	if (queue == NULL || back == 0)
		printf("-1\n");
	else
		printf("%d\n", queue[back - 1]);
}

int main()
{
	int N;
	scanf("%d", &N);
	int* queue = NULL;
	int front = 0;
	int back = 0;
	char command[10];

	for (int i = 0; i < N; i++)
	{
		scanf("%s", command);

		if (strcmp(command, "push") == 0)
		{
			int X;
			scanf("%d", &X);
			push(&queue, &back, X);
		}
		else if (strcmp(command, "pop") == 0)
		{
			pop(&queue, &back);
		}
		else if (strcmp(command, "size") == 0)
		{
			size(back);
		}
		else if (strcmp(command, "empty") == 0)
		{
			empty(queue, back);
		}
		else if (strcmp(command, "front") == 0)
		{
			Front(queue, back);
		}
		else if (strcmp(command, "back") == 0)
		{
			Back(queue, back);
		}
	}

	free(queue);
	return 0;
}