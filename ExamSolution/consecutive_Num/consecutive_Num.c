#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int N;
	scanf("%d", &N);
	int count = 0;
	int num = 666;
	char buffer[100];
	
	while (1)
	{
		sprintf(buffer, "%d", num);
		if (strstr(buffer, "666"))
		{
			count++;
			if (count == N)
			{
				printf("%d", num);
				break;
			}
		}
		num++;
	}

	return 0;
}