#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int GCD(int x, int y)
{
	int gcd = 0;
	int d1 = 1;
	int d2 = 1;
	for (int i = 1; i <= x && i <= y; i++)
	{
		if (x % i == 0 && y % i == 0)
		{
			gcd = i;
		}
	}
	return gcd;
}

int LCM(int x, int y)
{
	int gcd = GCD(x, y);
	int lcm = (x * y) / gcd;
	return lcm;
}

int main()
{
	int a, b, gcd, lcm;

	printf("2개의 정수를 입력 : ");
	scanf("%d %d", &a, &b);

	gcd = GCD(a, b);
	lcm = LCM(a, b);

	printf("GCD(%d, %d) = %d\n", a, b, gcd);
	printf("LCM(%d, %d) = %d\n", a, b, lcm);
}