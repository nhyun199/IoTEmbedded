#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int binaryToDecimal(char* binary)
{
	int deci = 0;
	int len = strlen(binary);
	int j = 0;
	for (int i = len-1; i >= 0; i--)
	{
		if (binary[i] == '1')
		{
			deci += (int)pow(2, j);
			j++;
		}
		else
			j++;
	}
	return deci;
}

void decimalToBinary(int decimal)
{
	if (decimal == 0)
	{
		printf("0");
		return;
	}

	char bin = '0';
	char result[50] = { 0 };
	int index = 0;

	while (decimal != 0)
	{
		if (decimal % 2 == 0)
			bin = '0';
		else if (decimal % 2 == 1)
			bin = '1';

		result[index] = bin;
		index++;
		decimal /= 2;
	}

	for (int i = index-1; i >= 0; i--)
		printf("%c", result[i]);
}

int main()
{
	char bin1[81];
	char bin2[81];

	scanf(" %s", bin1);
	scanf(" %s", bin2);
	
	int result = binaryToDecimal(bin1) + binaryToDecimal(bin2);
	decimalToBinary(result);
	return 0;
}