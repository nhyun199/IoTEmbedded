#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/** 
 * @brief This function is for Counting Sort.
 * @param len is beforSort's length.
 * @param max the maximun value in the beforeSort.
 * @param sum should have a size of `max + 1`
 * @param afterSort should be the same size as `beforeSort`.
*/
void countingSort(int beforeSort[], int len, int max, int sum[], int afterSort[])
{
	for (int i = 0; i <= max; i++)
	{
		sum[i] = 0;
	}

	for (int i = 0; i < len; i++)
	{
		sum[beforeSort[i]] = sum[beforeSort[i]] + 1;
	}

	for (int i = 1; i <= max; i++)
	{
		sum[i] = sum[i] + sum[i - 1];
	}

	for (int i = len-1; i >= 0 ; i--)
	{
		afterSort[sum[beforeSort[i]] - 1] = beforeSort[i];
		sum[beforeSort[i]] = sum[beforeSort[i]] - 1;
	}
}

void printfArr(int A[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

int main()
{
	int after[] = { 1,3,4,2,1,6,5,2 };
	int len = 8;
	int max = 6;
	int sum[7];
	int before[8];
	countingSort(after, len, max, sum, before);
	printfArr(after, len);
	printfArr(before, len);
}