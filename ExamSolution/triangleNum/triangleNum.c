#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int tri(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += i;
	}
	return sum;
}

int triSum(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += i * tri(i + 1);
	}
	return sum;
}

int main()
{
	int ex = triSum(3);
}