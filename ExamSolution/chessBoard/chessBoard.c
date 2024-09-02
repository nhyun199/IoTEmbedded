#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	// 하양 검정 하양 검정
	// 검정 하양 검정 하양
	char chessboard[8][8];
	int count = 0;
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			scanf(" %c", &chessboard[i][j]);
			if (i % 2 == 0 && j % 2 == 0) // i j = 0 2 4 6
			{
				if (chessboard[i][j] == 'F')
					count++;
			}

			else if (i % 2 != 0 && j % 2 != 0) // i j = 1 3 5 7
			{
				if (chessboard[i][j] == 'F')
					count++;
			}
		}
	}
	printf("%d", count);
}