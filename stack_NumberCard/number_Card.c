#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void push(int** stack, int* size, int X)
{
	*size += 1;
	int* temp = (int*)realloc(*stack, (*size) * sizeof(int));
	*stack = temp;
	(*stack)[*size - 1] = X;
}

void pop(int** stack, int* size)
{
	if (*stack == NULL) {}
	//printf("-1\n");
	else
	{
		//printf("%d\n", (*stack)[*size-1]);
		*size -= 1;
		if (*size == 0)
		{
			free(*stack);
			*stack = NULL;
		}
		else
		{
			int* temp = (int*)realloc(*stack, (*size) * sizeof(int));
			*stack = temp;
		}
	}
}

void Size(int size)
{
	printf("%d\n", size);
}

void empty(int* stack)
{
	if (stack == NULL)
		printf("1\n");
	else
		printf("0\n");
}

void top(int* stack, int size)
{
	if (stack != NULL)
		printf("%d\n", stack[size - 1]);
	else
		printf("-1\n");
}

int main()
{
	int N;
	int M;
	int* stack = NULL;
	int size = 0;
	scanf("%d", &N);
	int num;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		push(&stack, &size, num);
	}

	scanf("%d", &M);
	int* count = (int*)calloc(M, sizeof(int));
	int num2;

	for (int i = 0; i < M; i++)
	{
		scanf("%d", &num2);
		for (int j = 0; j < N; j++)
		{
			if (num2 == stack[j])
			{
				count[i]++;
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		printf("%d ", count[i]);
	}
}