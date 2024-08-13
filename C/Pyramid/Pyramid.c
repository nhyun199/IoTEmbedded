#include <stdio.h>

int main()
{
	// case 1
	for (int i = 0; i < 5; i++)
	{
		printf("*");
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n");

	// case 2
	for (int i = 0; i < 5; i++)
	{
		printf("*");
		for (int j = 0; j < i; j++)
		{
			printf("**");
		}
		printf("\n");
	}
	printf("\n");

	// case 3
	for (int i = 0; i < 5; i++)
	{
		printf("*");
		for (int j = 4; j > i; j--)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n");

	//case 4
	for (int i = 0; i < 5; i++)
	{	
		
		for (int j = 4; j > i; j--)
		{
			printf(" ");
		}
		
		for (int k = 0; k < i; k++)
		{
			printf("*");
		}
		printf("*\n");
	}
	printf("\n");

	// case 5
	for (int i = 0; i < 5; i++)
	{
		for (int j = 4; j > i; j--)
		{
			printf(" ");
		}
		printf("*");

		for (int l = 0; l < i; l++)
		{
			printf("**");
		}

		for (int k = 4; k > i; k--)
		{
			printf(" ");
		}
		printf("\n");
	}
	printf("\n");

	// case 6
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i; j++)
			printf(" ");

		for (int k = 8; k > i * 2; k--)
		{
			printf("*");
		}
		printf("*");
		printf("\n");
	}
}