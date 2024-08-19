#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

double chToNum(char* s)
{
	// case : 소수점
	double n = 0;
	int len = strlen(s);
	int minus = -1;
	int point = 1;
	for (int i = 0; i < len; i++)
	{
		if (isdigit(s[i]))
		{
			if (s[i] - 48 != 0)
			{
				n += (s[i] - 48) * pow(10, len - i - 1);
			}
			else if (s[i] == '.') 
			{
				point = pow(10, -(len-(i+1)));
			}
		}
		// 1.234
		// 30.5678
		// len = 7 point = 3 
		// len = 5 , point = 2 5-2 = 3 1234 * 10^-3
		// point = pow(10, -(len-point))
		// 1.234 s[0] = 1 /s[1] = . /s[2] = 2 /s[3] = 3 /s[4] = 4
		// i = 1 -> point 변화 생기고. 
	}

	if (s[0] == '-')
		return -n * point;

	return n * point;
}

int main()
{
	char s[] = "1.234";
	double s_num = chToNum(s);
	printf("%lf", s_num);
}