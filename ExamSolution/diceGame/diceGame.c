#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	int a, b, c;
	int award = 0;
	int maxAward = 0;

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		
		if (a == b && b == c)
			award = 10000 + a * 1000;
		
		else if (a == b || a == c)
			award = 1000 + a * 100;
		
		else if (b == c)
			award = 1000 + b * 100;
		
		else
		{
			if (a > b && a > c)
				award = a * 100;

			else if (b > a && b > c)
				award = b * 100;

			else if (c > a && c > b)
				award = c * 100;
		}

		if (maxAward < award)
			maxAward = award;
	}
	printf("%d", maxAward);
}