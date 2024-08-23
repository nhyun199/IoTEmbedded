#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}

// arr = 검색을 수행할 배열, n = 배열의 크기, key = 찾고자하는 수
// 원하는 수를 찾았다면 해당 인덱스를 반환, 수가 없다면 -1을 반환함
int binsearch(int *arr, int n, int key)
{
	int low = 0;
	int high = n - 1;
	int mid = 0;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (key == arr[mid])
			return 1;

		else if (key < arr[mid])
		{
			high = mid - 1;
		}
		else if (key > arr[mid])
		{
			low = mid + 1;
		}
	}
	return 0;
}

int main()
{
	int N, M;
	scanf("%d", &N);

	int* a = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	qsort(a, N, sizeof(a[0]), compare);

	scanf("%d", &M);
	int* b = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &b[i]);
	}

	for (int i = 0; i < M; i++)
	{
		int result;
		result = binsearch(a, N, b[i]);
		printf("%d\n", result);
	}
}