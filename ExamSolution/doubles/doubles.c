#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num[16] = { 0 };
	while (1)
	{
		int index = 0;
		int doubleCount = 0;

		for (int i = 0; i < 16; i++)
		{
			scanf("%d", &num[i]);

			if (num[i] == 0)
			{
				break;
			}

			else if (num[i] == -1)
			{
				return 0;
			}

			index++;
		}

		for (int i = 0; i < index; i++)
		{
			for (int j = i + 1; j < index; j++)
			{
				if (num[i] * 2 == num[j] || num[i] == num[j] * 2)
					doubleCount++;
			}
		}
		printf("%d\n", doubleCount);
	}
}