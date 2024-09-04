#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int year;
	scanf("%d", &year);

	if (year == 1996 || year == 1997 || year == 2000 || year == 2007 ||
		year == 2008 ||	year == 2013 || year == 2018)
		printf("SPbSU");

	else if (year == 2006)
		printf("PetrSU, ITMO");

	else
		printf("ITMO");
}