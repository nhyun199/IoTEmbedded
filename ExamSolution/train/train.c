#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int max = 0;
	int off, on;
	int sum = 0;

	for (int i = 0; i < 10; i++)
	{
		scanf("%d %d", &off, &on);
		sum = sum - off + on;
		if (max < sum)
			max = sum;
	}
	printf("%d", max);
}