#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "../LibTest/LibTest.h"
//#pragma comment(lib, "./x64/Debug/LibTest") // 라이브러리 위치를 알려줌
//#ifndef #endif == pragma once 실행 파일에 포함되지 않음. preprocess에서만..

#define LOTTO_MAX_NUM 45
#define LOTTO_NUM_COUNT 6
#define TRIALS 1000000

typedef struct _ENGINE
{
	char manufacture[50];
	char model[50];
	int year;
	char color[20];
	double price;
} ENGINE;

typedef struct _CAR
{
	char manufacture[50];
	char model[50];
	int year;
	char color[20];
	double price;
	ENGINE engine;
} CAR;


void CAR_stop(CAR* car) 
{
	//engine.stop()
};

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
	
	// 정적 라이브러리
	//PrintData(10);
	//PrintString("hello");	

	/*CAR yellow_car = {"Toyota", " Corolla", 2020, "Yellow", 2000.0};
	yellow_car.price = 200;
	CAR_stop(&yellow_car);*/

	// 원주율 계산하기
	bool sign = false;
	double pi = 0;

	for (int i = 1; i <= 100000000000; i += 2)
	{
		if (sign == false)
		{
			pi += (double)1 / i;
			sign = true;
		}
		else
		{
			pi -= (double)1 / i;
			sign = false;
		}

		if (i < 20 || i > 999999990)
			printf("i = %10d, pi = %.18f\n", i, 4 * pi);
	}
}