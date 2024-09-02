#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isPrime(int x)
{
	if (x <= 1)
		return 0;
	
	if (x == 2)
		return 1;

	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int M, N;
	scanf("%d %d", &M, &N);

	for (int i = M; i <= N; i++)
	{
		if (isPrime(i))
		{
			printf("%d\n", i);
		}
	}
}