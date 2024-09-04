#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int balance = 1;
	char command = 'D';
	int amount = 1;

	while (1)
	{
		scanf("%d %c %d", &balance, &command, &amount);

		if (command == 'W' && balance != 0 && amount != 0)
		{
			if (balance < amount)
				printf("Not allowed\n");

			else
				printf("%d\n", balance - amount);
		}

		else if(command == 'D' && balance != 0 && amount != 0)
		{
			printf("%d\n", balance + amount);
		}

		if (balance == 0 && command == 'W' && amount == 0)
			return 0;
	}
}