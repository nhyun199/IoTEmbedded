#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int age;
	int branch;
	int cut;
	int leaf = 0;
	while (1)
	{
		scanf("%d", &age);
		if (age == 0)
			return 0;

		for (int i = 0; i < age; i++)
		{
			scanf("%d %d", &branch, &cut);
			if (i == 0)
				leaf = branch - cut;
			else
				leaf = leaf * branch - cut;
		}
		printf("%d\n", leaf);
	}
}