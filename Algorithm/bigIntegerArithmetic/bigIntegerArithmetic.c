#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void add(char* num1, char* num2, char* result)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int carry = 0;
	int i;

	for (i = 0; i < len1 || i < len2 || carry; i++)
	{
		int digit1 = i < len1 ? num1[len1-1-i] - '0' : 0;
		int digit2 = i < len2 ? num2[len2-1-i] - '0' : 0;
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
}
void multiple(char* num1, char* num2, char* result)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int carry = 0;
	int i;

	for (i = 0; i < len1 || i < len2 || carry; i++)
	{
		int digit1 = i < len1 ? num1[len1-i-1] - '0' : 0;
		int digit2 = i < len2 ? num2[len2-i-1] - '0' : 0;
	}

}


int main()
{
	char num1[10001];
	char num2[10001];
	char result[10003];

	scanf("%s %s", num1, num2);

	add(num1, num2, result);

	printf("%s", result);
}