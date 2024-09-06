#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, M, L;
	int i = 0;
	scanf("%d %d %d", &N, &M, &L);

	int* count = (int*)calloc(N, sizeof(int));
	count[0] = 1;
	int throw = 1;

	while (1)
	{
		if (M == 1)
		{
			printf("0");
			free(count);
			return 0;
		}

		if (count[i] % 2 != 0)
		{
			if (i + L > N - 1)
				i = i + L - N;
			else
				i = i + L;

			count[i]++;
		}
		else if(count[i] % 2 == 0)
		{
			if (i < L)
				i = N - (L - i);
			else
				i = i - L;

			count[i]++;
		}

		if (count[i] == M)
		{
			printf("%d", throw);
			free(count);
			return 0;
		}

		throw++;
	}
}