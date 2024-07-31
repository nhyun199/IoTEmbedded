#include <stdio.h>

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void printArr(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	// selection sort
	int nArr[10] = { 4, 6, 11, 3, 1, 10, 9, 5, 7, 2 };
	int size = sizeof(nArr) / sizeof(int);
	int min = 0;

	printArr(nArr, size); // Before sort
	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (nArr[min] > nArr[j])
				min = j;
		}
		swap(&nArr[i], &nArr[min]);
	}
	printArr(nArr, size); // After sort
	

	// bubble sort
	int nArr2[6] = { 5,1,9,7,2,3 };
	int size2 = sizeof(nArr2) / sizeof(int);

	printArr(nArr2, size2); // Before sort
	for (int i = 0; i < size2 - 1; i++)
	{
		for (int j = 0; j < size2 - 1 - i; j++)
		{
			if (nArr2[j] > nArr2[j + 1])
			{
				swap(&nArr2[j], &nArr2[j + 1]);
			}
		}
	}
	printArr(nArr2, size2); // After sort

}