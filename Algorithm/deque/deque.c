#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push_frontX(int** deque, int* back, int X)
{
	if (*deque == NULL || *back == 0)
	{
		*deque = (int*)malloc(sizeof(int));
	}
	else
	{
		*deque = (int*)realloc(*deque,(*back + 1) * sizeof(int));
		for (int i = *back; i > 0; i--)
		{
			(*deque)[i] = (*deque)[i - 1];
		}
	}

	(*deque)[0] = X;
	(*back)++;
}

void push_backX(int** deque, int* back, int X)
{
	if (*deque == NULL || *back == 0)
	{
		*deque = (int*)malloc(sizeof(int));
	}
	else
	{
		*deque = (int*)realloc(*deque, (*back + 1) * sizeof(int));
	}
	(*deque)[*back] = X;
	(*back)++;
}

void pop_front(int** deque, int* back)
{
	if (*deque == NULL || *back == 0)
		printf("-1\n");

	else
	{
		printf("%d\n", (*deque)[0]);
		(*back)--;

		if (*back == 0)
		{
			free(*deque);
			*deque = NULL;
		}

		else
		{
			for (int i = 0; i < *back; i++)
			{
				(*deque)[i] = (*deque)[i + 1];
			}
			*deque = (int*)realloc(*deque, (*back) * sizeof(int));
		}
	}
}

void pop_back(int** deque, int* back)
{
	if (*deque == NULL || *back == 0)
		printf("-1\n");

	else
	{
		printf("%d\n", (*deque)[(*back) - 1]);
		(*back)--;

		if (*back == 0)
		{
			free(*deque);
			*deque = NULL;
		}

		else
		{
			*deque = (int*)realloc(*deque, (*back) * sizeof(int));
		}
	}
}

void size(int back)
{
	printf("%d\n", back);
}

void empty(int* deque)
{
	if (deque == NULL)
		printf("1\n");

	else
		printf("0\n");
}

void front(int* deque)
{
	if (deque == NULL)
		printf("-1\n");

	else
		printf("%d\n", deque[0]);
}

void back(int* deque, int back)
{
	if (deque == NULL)
		printf("-1\n");

	else
		printf("%d\n", deque[back - 1]);
}

void printdeque(int* deque, int back)
{
	for (int i = 0; i < back; i++)
	{
		printf("%d ", deque[i]);
	}
	printf("\n");
}

int main()
{
	int* deque = NULL;
	int backN= 0;
	int N;
	char command[15];
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int X;
		scanf("%s", command);

		if (strcmp(command, "push_front") == 0)
		{
			scanf("%d", &X);
			push_frontX(&deque, &backN, X);
		}
		else if (strcmp(command, "push_back") == 0)
		{
			scanf("%d", &X);
			push_backX(&deque, &backN, X);
		}
		else if (strcmp(command, "pop_front") == 0)
		{
			pop_front(&deque, &backN);
		}
		else if (strcmp(command, "pop_back") == 0)
		{
			pop_back(&deque, &backN);
		}
		else if (strcmp(command, "size") == 0)
		{
			size(backN);
		}
		else if (strcmp(command, "empty") == 0)
		{
			empty(deque);
		}
		else if (strcmp(command, "front") == 0)
		{
			front(deque);
		}
		else if (strcmp(command, "back") == 0)
		{
			back(deque, backN);
		}
	}
	
	free(deque);
}