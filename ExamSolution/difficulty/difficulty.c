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
	int n;
	int sum = 0;
	scanf("%d", &n);

	if (n == 0)
	{
		printf("0");
		return 0;
	}

	int triMean = round(n * 0.15);
	int* diff = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &diff[i]);
	}

	qsort(diff, n, sizeof(diff[0]), compare);

	for (int i = triMean; i < n - triMean; i++)
	{
		sum += diff[i];
	}

	printf("%d", (int)round((double)sum / (n - triMean * 2)));

	free(diff);
}