#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int binary_To_Decimal(long long bin)
{
	int dec = 0;
	int i = 0;
	int n = 0;

	while(bin > 0)
	{
		n = bin % 10;
		bin /= 10;
		dec += n * pow(2, i);
		i++;
	}
	return dec;
}

int main()
{
	long long bin;
	int dec;

	printf("Enter binary number: ");
	scanf("%lld", &bin);

	dec = binary_To_Decimal(bin);
	printf("%lld(binary) = %d(decimal)\n", bin, dec);
}