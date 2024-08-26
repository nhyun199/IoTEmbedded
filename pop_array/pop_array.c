#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void push(int **stack, int *size, int n)
{
	*size += 1;
	int* temp = (int*)realloc(*stack, (*size) * sizeof(int));
	*stack = temp;
	(*stack)[*size - 1] = n;
}

void pop(int **stack, int *size)
{
	if(*stack == NULL || *size == 0) {}

	else
	{
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

int main()
{
	int size = 0;
	int* stack = NULL;
	int n;
	int num;
	int top = 0;
	int last = 0;
	int err = 0;
	char result[200000];
	int index = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);

		if (num > top)
		{
			for (int j = last+1; j <= num; j++)
			{
				push(&stack, &size, j);
				result[index++] = '+';
			}
			pop(&stack, &size);
			result[index++] = '-';
			top = (size > 0) ? stack[size - 1] : 0;
			last = num;
		}

		else if (num == top)
		{
			pop(&stack, &size);
			result[index++] = '-';
			top = (size > 0) ? stack[size - 1] : 0;
		}

		else if (num < top)
		{
			err = 1;
		}
	}

	if (err == 1)
	{
		printf("NO");
	}

	else
	{
		for (int i = 0; i < index; i++)
		{
			printf("%c\n", result[i]);
		}
	}

	if (stack != NULL)
		free(stack);
}