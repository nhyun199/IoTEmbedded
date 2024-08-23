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

// arr = �˻��� ������ �迭, n = �迭�� ũ��, key = ã�����ϴ� ��
// ���ϴ� ���� ã�Ҵٸ� �ش� �ε����� ��ȯ, ���� ���ٸ� -1�� ��ȯ��
int binsearch(int *arr, int n, int key)
{
	int low = 0;
	int high = n - 1;
	int mid = 0;
	int count = 0;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (key == arr[mid])
		{
			count++;

			int left = mid - 1;
			while (left >= 0 && arr[left] == key)
			{
				count++;
				left--;
			}

			int right = mid + 1;
			while (right < n && arr[right] == key)
			{
				count++;
				right++;
			}

			break;
		}

		else if (key < arr[mid])
		{
			high = mid - 1;
		}
		else if (key > arr[mid])
		{
			low = mid + 1;
		}
	}
	return count;
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
	int* b = (int*)malloc(M * sizeof(int));
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &b[i]);
	}

	for (int i = 0; i < M; i++)
	{
		int result;
		result = binsearch(a, N, b[i]);
		printf("%d ", result);
	}
}