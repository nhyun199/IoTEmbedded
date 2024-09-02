#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	scanf("%d", &N);
	int max = 0;
	int end = 0;

	int* A = (int*)malloc(N * sizeof(int));

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
		if (max < A[i])
			max = A[i];
	}

	for (int i = 0; i < N; i++)
	{
		int NGE = 0;
		for (int j = i + 1; j < N; j++)
		{
			if (A[i] == max || i == N-1)
				break;

			if (A[i] < A[j])
			{
				printf("%d ", A[j]);
				NGE = 1;
				break;
			}
		}
		if (NGE == 0)
			printf("-1 ");
	}
}