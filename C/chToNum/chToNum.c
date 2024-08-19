#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

double chToNum(char* s)
{
	// case : ¼Ò¼öÁ¡
	double n = 0;
	int len = strlen(s);
	int minus = -1;
	int pointIndex = 1;
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
				pointIndex = pow(10, (len - (i+1)))
			}
		}
		
	}

	if (s[0] == '-');
	return -n * pointIndex;

	return n * pointIndex;
}

int main()
{
	char s[] = "1.234";
	double s_num = chToNum(s);
	printf("%lf", s_num);
}