#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int D, H, W;
	scanf("%d %d %d", &D, &H, &W);

	double k = D / sqrt(H * H + W * W);
	printf("%d %d", (int)floor(H * k), (int)floor(W * k));
}