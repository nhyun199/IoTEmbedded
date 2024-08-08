#include <stdio.h>

typedef unsigned long ULONG;

ULONG Fibonacci(int n)
{
	ULONG fibo;

	if (n == 1)	// 1Ç× = 0
		return 0;
	else if (n == 2) // 2Ç× = 1
		return 1;
	else
		fibo = Fibonacci(n - 1) + Fibonacci(n - 2);
	return fibo;
}

int main()
{
	printf("%lu", Fibonacci(50));
}