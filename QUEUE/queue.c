#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

void push(int **queue, int *back, int X) 
{
	if (*queue == NULL)
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

void pop(int **queue, int *front) 
{
	if (*queue == NULL)
		printf("-1\n");
	else
	{
		printf("%d", (*queue)[*front]); //

	}
}
void size() {}
void empty() {}
void Front() {}
void Back() {}

int main()
{
	//int N;
	int* queue = NULL;
	int front = 0;
	int back = 0;
}