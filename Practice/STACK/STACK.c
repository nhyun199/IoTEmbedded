#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// size empty top
void push(int **stack, int *size, int X)
{
	*size += 1;
	int* temp = (int*)realloc(*stack, (*size) * sizeof(int));
	*stack = temp;
	(*stack)[*size - 1] = X;
}

void pop(int **stack, int *size)
{
	if (*stack == NULL)
		printf("-1\n");
	else
	{
		printf("%d\n", (*stack)[*size-1]);
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

void empty(int *stack)
{
	if (stack == NULL)
		printf("1\n");
	else
		printf("0\n");
}

void top(int *stack, int size)
{
	if (stack != NULL)
		printf("%d\n", stack[size-1]);
	else
		printf("-1\n");
}

int main()
{
	int N;
	scanf("%d", &N);
	int size = 0;
	int* stack = NULL;
	char command[10];

	for (int i = 0; i < N; i++)
	{
		scanf("%s", command);
		if (strcmp(command, "push") == 0)
		{
			int X;
			scanf("%d", &X);
			push(&stack, &size, X);
		}
		else if (strcmp(command, "pop") == 0)
		{
			pop(&stack, &size);
		}
		else if (strcmp(command, "size") == 0)
		{
			Size(size);
		}
		else if (strcmp(command, "empty") == 0)
		{
			empty(stack);
		}
		else if (strcmp(command, "top") == 0)
		{
			top(stack, size);
		}
	}

	free(stack);
}