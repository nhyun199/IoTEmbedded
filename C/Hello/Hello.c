#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "../LibTest/LibTest.h"

#define LOTTO_MAX_NUM 45
#define LOTTO_NUM_COUNT 6
#define TRIALS 1000000

int AtSign(int A, int B)
{
	int C;
	C = (A + B) * (A - B);
	return C;
}

void generateLottoNumbers(int* lottoNumbers, int count)
{
	srand(time(0));
	int i = 0;
	while (i < count)
	{
		int randnumber = (rand() % LOTTO_MAX_NUM) + 1;
		int X = 1;

		for (int j = 0; j < i; j++)
		{
			if (lottoNumbers[j] == randnumber)
				X = 0;
			break;
		}

		if (X)
		{
			lottoNumbers[i] = randnumber;
			i++;
		}
	}
}

void printLottoNumbers(int* lottoNumbers, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%d ", lottoNumbers[i]);
	}
}

void main()
{
	// char szbuffer[128] = { 0 };
	//char* szbuffer = /*(char*)malloc(128 * sizeof(char));*/ /*(char*)malloc(128)*/malloc(sizeof(int));
	//int a = sizeof(szbuffer);
	//printf("%d", a);

	// malloc 동적 메모리 할당
	// 메모리 크기를 결정하고 그 크기만큼 heap 영역에 메모리를 할당함
	// OS(운영체제)가 위치(주소)를 할당함.
	// stack 영역에서 쓰레기값 - cc / heap 영역에서 쓰레기값 - cd
	// 문자열 상수는 heap 영역에 할당됨

	//printf("Input your name : ");
	//gets(szbuffer);

	//printf("Your name is ");
	//puts(szbuffer);

	//free(szbuffer); // 할당한 메모리를 해제하지않으면 메모리 누수의 가능성이 있음.

	//double a = 123.456;
	//printf("%.12lf", a);

	/*int Year;
	printf("계산할 연도를 입력하세요 :");
	scanf_s("%d", &Year);

	if ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0)
	{
		printf("%d년은 윤년입니다.", Year);
	}
	else
		printf("%d년은 윤년이 아닙니다.", Year);*/

	/*int a[10];
	int sum = 0;
	int min, max;

	for (int i =0; i<10; i++)
	{
		printf("%d번째 숫자를 입력하세요 : ", i+1);
		scanf_s("%d", &a[i]);
		sum += a[i];
	}

	min = a[0];
	max = a[0];

	for (int i = 1; i < 10; i++)
	{
		if (min > a[i])
			min = a[i];

		if (max < a[i])
			max = a[i];
	}
	
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\nmax = %d, min = %d, average = %.1f", max, min, (float)sum / 10);*/

	//printf("총합은 %d입니다",sum);


	// 구구단 출력하기
	/*int N;
	scanf_s("%d", &N);
	for (int i = 1; i < 10; i++)
	{
		printf("%d * %d = %d\n", N, i, N * i);
	}*/

	// A + B 반복 출력하기

	/*int T, A, B;
	scanf_s("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf_s("%d %d", &A, &B);
		printf("%d\n", A + B);
	}*/

	// 1부터 N까지의 합 출력하기

	/*int N;
	int Sum = 0;
	scanf_s("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		Sum += i;
	}
	printf("%d", Sum);*/

	// 공백 4 3 2 1 0 별 1 2 3 4 5 
	/*int N;
	scanf_s("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - (i + 1); j++)
		{
			printf(" ");
		}
		for (int k = 0; k < i; k++)
		{
			printf("*");
		}		
		printf("*\n");
	}*/

	/*int A, B;
	for ( ; ; )
	{
		scanf_s("%d %d", &A, &B);
		if (A != 0 || B != 0)
		{
			printf("%d\n", A + B);
		}
		else
			break;
	}*/

	/*int x, y;
	for (; ; )
	{
		if (scanf("%d %d", &x, &y) == EOF)
			break;

		printf("%d", x + y);
	}*/

	/*int a;
	printf("\\    /\\\n");
	printf(" )  ( ')\n");
	printf("(  /  )\n");
	printf(" \\(__)|\n");
	printf("|\\_/|\n");
	printf("|q p|   /\}\n");
	printf("( 0 )\"\"\"\\\n");
	printf("|\"^\"`    |\n");
	printf("||_/=\\\\__|\n");
	printf("         ,r'\"7\n");
	printf("r`-_   ,'  ,/\n");
	printf(" \\. \". L_r'\n");
	printf("   `~\\/\n");
	printf("      |\n");
	printf("      |\n");*/

	
	// 1 ~ 45 6개 선택
	// 중복 X
	
	//int lottoNumbers[LOTTO_NUM_COUNT];

	/*int lottoNumbers[LOTTO_NUM_COUNT];

	generateLottoNumbers(lottoNumbers, LOTTO_NUM_COUNT);

	printf("생성된 로또 번호: ");
	printLottoNumbers(lottoNumbers, LOTTO_NUM_COUNT);*/

	//int N[100] = {0}; // 전체 배열 0으로 초기화
	//int n;
	//
	//for (int i = 1; i <= 28; i++)
	//{
	//	scanf("%d", &n);
	//	N[n] = 1;	// 들어온 값에 대해 1로 초기화함
	//}

	//for (int i = 1; i <= 30; i++)
	//{
	//	if (N[i] == 0)
	//		printf("%d\n", i);
	//}

	/*int N, M;
	int A[100][100], B[100][100];
	scanf_s("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)		
			scanf_s("%d", &A[i][j]);		
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			scanf_s("%d", &B[i][j]);
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ", A[i][j] + B[i][j]);
		}
		printf("\n");
	}*/

	/*char X;
	scanf_s("%c", &X);
	printf("%d", X);*/
		
	/*char* apszData[] = { "Test", "String", "Data" };
	char szBuffer[128] = { 0 };
	int i = 0, nOffset = 0;*/
	
	// 몬테카를로 시뮬레이션
	/*int cnt[13] = { 0 };
	int rand_min = 1;
	int rand_max = 6;
	int dice;
	int randnum; 

	srand(time(0));

	for (int i = 0; i < TRIALS; i++)
	{
		dice = (rand() % (rand_max - rand_min + 1)) + rand_min;
		randnum = (rand() % (rand_max - rand_min + 1)) + rand_min;
		dice += randnum;
		cnt[dice]++;
	}

	for (int i = 2; i < 13; i++)
	{
		printf("합이 %d가 나올 확률은 %.5f%%입니다.\n", i, (double)cnt[i] / TRIALS * 100);
	}*/
	
	/*char grade;
	char sign;

	scanf_s("%c", &grade);
	if (grade == 'F')
	{
		printf("0.0");
		return 0;
	}

	scanf_s("%c", &sign);

	switch (grade)
	{
	case 'A' :
		switch (sign)
		{
		case '+' :
			printf("4.3");
			break;
		case '0' :
			printf("4.0");
			break;
		case '-' :
			printf("3.7");
			break;
		}
		break;
	case 'B':
		switch (sign)
		{
		case '+':
			printf("3.3");
			break;
		case '0':
			printf("3.0");
			break;
		case '-':
			printf("2.7");
			break;
		}
		break;
	case 'C':
		switch (sign)
		{
		case '+':
			printf("2.3");
			break;
		case '0':
			printf("2.0");
			break;
		case '-':
			printf("1.7");
			break;
		}
		break;
	case 'D':
		switch (sign)
		{
		case '+':
			printf("1.3");
			break;
		case '0':
			printf("1.0");
			break;
		case '-':
			printf("0.7");
			break;
		}
		break;
	}*/

	/*char S[1001];
	int i;

	scanf("%s", S);
	scanf("%d", &i);

	printf("%c", S[i-1]);*/

	/*int T;
	char S[1001];
	
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf("%s", S);
		int len = strlen(S);


		if (len == 1)
			printf("%c%c\n", S[0], S[0]);
		else if (len > 0)
			printf("%c%c\n", S[0], S[len - 1]);
	}*/

	/*int A, B;
	scanf("%d %d", &A, &B);
	printf("%d", AtSign(A, B));*/
	
	PrintData(10);
	PrintString("hello");

	
}