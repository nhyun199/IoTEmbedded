#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N[999];
	int primes = 0;

	for (int i = 0; i < 999; i++)
	{
		N[i] = i + 2;
	}

	for (int i = 0; i < 999; i++)
	{
		int is_prime = 1;

		for (int j = 2; j < N[i]; j++)
		{
			if (N[i] % j == 0)
			{
				is_prime = 0;
				break;
			}
		}

		if (is_prime)
		{
			printf("%d ", N[i]);
			primes++;
		}
	}
	printf("\n2부터 1000사이의 소수의 갯수: %d개", primes);
}