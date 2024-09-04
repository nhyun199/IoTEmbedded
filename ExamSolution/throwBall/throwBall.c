#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, M, L;
	scanf("%d %d %d", &N, &M, &L);

	int* count = (int*)malloc(N * sizeof(int));

	// 1번부터 던짐 -> count[0]++
	// 한 사람이 M번 받으면 게임 끝
	
}