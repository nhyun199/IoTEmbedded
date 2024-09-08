#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int width = 1;
	char num[5];
	
	while (1)
	{
		scanf("%s", num);
		int len = strlen(num);

		if (num[0] == '0')
			break;

		for (int i = 0; i < len; i++)
		{
			if (num[i] == '1')
			{
				width += 2;
			}
			else if (num[i] == '0')
			{
				width += 4;
			}
			else
			{
				width += 3;
			}
			width++;
		}
		printf("%d\n", width);
		width = 1;
	}
}