#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}

int main()
{
	int N;
	scanf("%d", &N);
	int* num = (int*)malloc(N * sizeof(int));
	int max = -4001;
	int min = 4001;
	int sum = 0;
	float mean = 0;
	int mid = 0;
	int range = 0;
	int mode = num[0];
	int maxCount = 0;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
		
		sum += num[i];

		if (max < num[i])
			max = num[i];

		if (min > num[i])
			min = num[i];
	}

	qsort(num, N, sizeof(num[0]), compare);

	if (N == 1)
	{
		mean = num[0];
		mid = num[0];
		mode = num[0];
		range = 0;
		printf("%d\n%d\n%d\n%d", (int)mean, mid, mode, range);
		return 0;
	}
	else
	{
		mean = (float)sum / N;
		mid = num[N / 2];
		range = max - min;
	}

	for (int i = 0; i < N; i++)
	{
		int count = 1;
		for (int j = i + 1; j < N; j++)
		{
			if (num[i] == num[j])
			{
				count++;
			}
		}
		if (maxCount < count)
		{
			maxCount = count;
			mode = num[i];
		}
		if (maxCount == count)
		{
			if (mode < num[i])
			{
				mode = num[i];
				break;
			}
		}
	}

	printf("%d\n%d\n%d\n%d", (int)round(mean), mid, mode, range);
	return 0;
}