#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
	char num1[] = "17";
	char num2[] = "25";
	char result[3];

	// 문자형식의 수에서 '0'을 빼면 정수형이 된다.
	// ex) char a = '4', int b = '4' - '0' = 4

	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int carry = 0;
	int i;

	for (i = 0; i < len1 || i < len2 || carry; i++) // 더하기 연산을 수행함.
	{
		int digit1 = i < len1 ? num1[len1 - 1 - i] - '0' : 0;
		int digit2 = i < len2 ? num2[len2 - 1 - i] - '0' : 0;
		int sum = digit1 + digit2 + carry;
		carry = sum / 10;
		result[i] = (sum % 10) + '0';
	}
	result[i] = '\0';

	for (int j = 0; j < i / 2; j++)
	{
		char temp = result[j];
		result[j] = result[i - j - 1];
		result[i - j - 1] = temp;
	}

	printf("%s", result);
}