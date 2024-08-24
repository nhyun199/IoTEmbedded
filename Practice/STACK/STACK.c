#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void push(int **stack, int *size, int X)
{
	*size += 1;
	int* temp = (int*)realloc(*stack, (*size) * sizeof(int));
	*stack = temp;
	(*stack)[*size - 1] = X;
}

void pop(int **stack, int *size)
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
	int k;
	scanf("%d", &k);
	int size = 0;
	int* stack = NULL;
	int sum = 0;	
	int num;

	for (int i = 0; i < k; i++)
	{
		scanf("%d", &num);

		if (num == 0)
			pop(&stack, &size);

		else
			push(&stack, &size, num);
	}
	
	for (int i = 0; i < size; i++)
	{
		sum += stack[i];
	}

	printf("%d", sum);
	free(stack);
}