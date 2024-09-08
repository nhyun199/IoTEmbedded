#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int cup[3] = { 1, 2, 3 };
	int M;
	int X, Y; // 1 2 3
	int index[3] = { 0, 1, 2 };

	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &X, &Y); // 2 1
		int temp = cup[index[X - 1]];
		int tempIndex = index[X - 1];
		cup[index[X - 1]] = cup[index[Y - 1]];
		index[X - 1] = index[Y - 1];
		cup[index[Y - 1]] = temp;
		index[Y - 1] = tempIndex;
	}
	printf("%d\n", cup[0]);
}