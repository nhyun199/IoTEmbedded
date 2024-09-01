#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num[9][9];
	int max = -1;
	int x = 0;
	int y = 0;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &num[i][j]);
			if (max < num[i][j])
			{
				max = num[i][j];
				x = i+1, y = j+1;
			}
		}
	}

	printf("%d\n%d %d", max, x, y);
}

