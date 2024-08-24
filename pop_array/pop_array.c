#define _CRT_SECRUE_NO_WARNINGS
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

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);

		for (int j = last + 1; j <= num; j++)
		{
			if (top == num)
			{
				pop(&stack, &size);
				if (stack == NULL || size == 0)
				{
					top = 0;
				}
				else
					top = stack[size - 1];
			}

			else if (top < num)
			{
				push(&stack, &size, j);
				last = j;
				top = stack[size - 1];
			}

			else if (top > num)
			{
				printf("NO");
				break;
			}
		}
	}		
}