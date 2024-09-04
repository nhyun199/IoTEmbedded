#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	int area = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (area == K)
			{
				printf("%d %d", i, j);
				return 0;
			}
			area++;
		}
	}
}