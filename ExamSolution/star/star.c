#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N = 5;
	/*scanf("%d", &N);*/

	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < i; k++)
		{
			printf(" ");
		}

		for (int j = N; j > i; j--)
		{
			printf("*");
		}
		
		printf("\n");
	}

	printf("\n");

	for (int i = 0; i < N; i++)
	{
		for (int j = N; j > i+1; j--)
		{
			printf(" ");
		}
		for (int k = 0; k < i; k++)
		{
			printf("*");
		}
		printf("*");
		for (int b = 0; b < i; b++)
		{
			printf("*");
		}

		printf(" ");
		printf("\n");
	}
	
	printf("\n");

	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < i; k++)
		{
			printf(" ");
		}

		for (int j = N * 2; j > 2 * i + 1; j--)
		{
			printf("*");
		}

		printf(" \n");
	}

	printf("\n");

	for (int i = 0; i < N; i++)
	{
		for (int j = N; j > i+1; j--)
		{
			printf(" ");
		}
		for (int k = 0; k < 2 * i + 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (int i = 0; i < N-1; i++)
	{
		for (int k = 0; k < i + 1; k++)
		{
			printf(" ");
		}
		for (int j = 2 * (N - 1); j > 2*i + 1; j--)
		{
			printf("*");
		}
		printf("\n");
	}

}