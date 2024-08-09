#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int sprial[100][100] = { 0 };
	int dX[] = { 0, 1, 0, -1 };
	int dY[] = { 1, 0, -1, 0 };
	int x = 0, y = 0, dir = 0;
	int value = 1;

	for (int i = 0; i < n * n; i++)
	{
		sprial[x][y] = value;
		value++;

		int nX = x + dX[dir];
		int nY = y + dY[dir];

		if (nX < 0 || nX >= n || nY < 0 || nY >= n || sprial[nX][nY] != 0)
		{
			dir = (dir + 1) % 4;
			nX = x + dX[dir];
			nY = y + dY[dir];
		}
		x = nX;
		y = nY;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%4d", sprial[i][j]);
		}
		printf("\n");
	}

	return 0;
}
