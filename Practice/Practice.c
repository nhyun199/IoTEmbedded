#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int AtSign(int A, int B)
{
	int C;
	C = (A + B) * (A - B);
	return C;
}

int main()
{
	/*min = a[0];
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

	// 그림 출력하기 - 특이한 문자 출력
	/*
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

	// 학점 계산기
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

	/*char S[1001];
	int i;

	scanf("%s", S);
	scanf("%d", &i);

	printf("%c", S[i-1]);*/

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

	// 3003번 체스

	// 킹 퀸 룩 비숍 나이트 폰 1 1 2 2 2 8

	//int Chess_Origin[6] = { 1, 1, 2, 2, 2, 8 };
	//int Piece[6]; // 현재 가진 개수
	//int PieceMissig[6];

	//for (int i = 0; i < 6; i++)
	//{
	//	scanf("%d", &Piece[i]);
	//	PieceMissig[i] = Chess_Origin[i] - Piece[i];
	//	printf("%d ", PieceMissig[i]);
	//}
	
	// A B를 비교하여 문자를 출력하고 0 0 이 들어오면 종료하기
	/*int A, B;

	for (; ; )
	{
		scanf("%d %d", &A, &B);

		if (A != 0 || B != 0)
		{
			if (A > B)
				printf("Yes\n");
			else
				printf("No\n");
		}
		else
			break;
	}*/

	// 두 문자열의 길이 비교
	//char Ah[1001]; // 재환이의 ah
	//char AhDoctor[1001]; // 의사가 요구하는 ah
	//// 같거나 길면 go 짧으면 no?

	//scanf("%s", Ah);
	//scanf("%s", AhDoctor);

	//if (strlen(Ah) >= strlen(AhDoctor))
	//	printf("go");
	//else
	//	printf("no");

	//printf("강한친구 대한육군\n강한친구 대한육군");

	/*char ID[21];
	char FAN[] = ":fan:";
	scanf("%s", ID);	
	printf("%s%s%s\n", FAN, FAN, FAN);
	printf("%s:%s:%s\n", FAN, ID, FAN);
	printf("%s%s%s", FAN, FAN, FAN);*/

	/*int A, B;
	scanf("%d %d", &A, &B);
	printf("%d %d", B - A, B);*/

	/*int nA, nB, nC;
	char chA[5];
	char chB[5];
	char result[5];
	scanf("%d %d %d", &nA, &nB, &nC);
	sprintf(chA, "%d", nA);
	sprintf(chB, "%d", nB);
	strcpy(result, chA);
	strcat(result, chB);

	printf("%d\n", nA + nB - nC);
	printf("%d", atoi(result) - nC);*/
	
	/*int N[9];
	int max = 0;
	int index = 1;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &N[i]);
		if (max < N[i])
			max = N[i];
	}

	for (int i = 0; i < 9; i++)
	{
		if (max != N[i])
			index++;
		else
			break;
	}

	printf("%d\n%d", max, index);*/

	/*int T, R;
	char S[21];

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf("%d %s", &R, S);
		for (int j = 0; j < strlen(S); j++)
		{
			for (int k = 0; k < R; k++)
			{
				printf("%c", S[j]);
			}
		}
		printf("\n");
	}*/

	/*int N[8] = { 0 };
	int N2[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int ascen = 0;
	int descen = 0;
	
	for (int i = 0; i < 8; i++)
		scanf("%d", &N[i]);
	
	for (int i = 0; i < 8; i++)
	{
		if (N[i] == N2[i])
			ascen++;

		else if (N[i] == N2[7 - i])
			descen++;
	}

	if (ascen == 8)
		printf("ascending");
	else if (descen == 8)
		printf("descending");
	else
		printf("mixed");*/

	
	//int A, B, C;
	//int ABC[10] = {0};
	//int N[10] = {0};
	//scanf("%d %d %d", &A, &B, &C);

	//int num = A * B * C;
	//int index = 0;

	//while (num > 0)	// 제일 작은 자릿수가 0부터 들어감. -> 출력할 때 역순으로 해야된다는 이야기다.
	//{
	//	ABC[index] = num % 10;
	//	num /= 10;
	//	index++;
	//}

	//for (int i = 0; i < index; i++)
	//{
	//	N[ABC[i]]++;
	//}

	//for (int i = 0; i < 10; i++)
	//	printf("%d\n", N[i]);
	
	/*char S[101];
	char alpha[26];
	int correct[26];
	scanf("%s", S);

	for (int i = 0; i < 26; i++)
	{
		alpha[i] = 'a' + i;
		correct[i] = -1;
	}

	for (int i = 0; i < strlen(S); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (S[i] == alpha[j] && correct[j] == -1)
			{
				correct[j] = i;
				break;
			}
		}
	}

	for (int i = 0; i < 26; i++)
		printf("%d ", correct[i]);*/

	//int N[10]; // 나눌 수
	//int remain[10]; // 42로 나눈 나머지를 담음
	//int remain_42[42] = {0,};
	//// 나올 수 있는 나머지의 값은 0 ~ 41
	//int sum = 0; // 중복값 판단

	//for (int i = 0; i < 10; i++)
	//{
	//	scanf("%d", &N[i]);
	//	remain[i] = N[i] % 42;		
	//}

	//for (int i = 0; i < 10; i++)
	//{
	//	for (int j = 0; j < 42; j++)
	//	{
	//		if (remain[i] == j)
	//			remain_42[j] = 1;
	//	}
	//}

	//for (int i = 0; i < 42; i++)
	//	sum += remain_42[i];

	//printf("%d", sum);

	/*int T;
	scanf("%d", &T);
	char S[80];

	for (int i = 0; i < T; i++)
	{
		scanf("%s", S);
		int len = strlen(S);
		int score = 0;
		int sum = 0;
		
		for (int j = 0; j < len; j++)
		{
			if (S[j] == 'O')
			{
				score++;
				sum += score;
			}

			else if (S[j] == 'X')
			{
				score = 0;
			}
			
		}

		printf("%d\n", sum);
	}*/
	
	//char S[1000001];
	//scanf("%[^\n]", S);
	//int len = strlen(S);
	//int blank = 1;

	//if (S[0] == ' ' && len == 1) // 공백 하나로 된 문자열
	//	printf("0");
	//
	//else
	//{
	//	for (int i = 1; i < len - 1; i++)
	//	{
	//		if (S[i] == ' ')
	//			blank++;
	//	}
	//	printf("%d", blank);
	//}

	/*int T;
	int H, W, N;
	int roomNum;
	scanf("%d", &T);
	
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d %d", &H, &W, &N);
		
		int floor = (N - 1) % H + 1;
		int room = (N - 1) / H + 1;
		roomNum = floor * 100 + room;

		printf("%d\n", roomNum);
	}*/
	
	// H > N H01 roomNum = H * 100 + 1
	// H < N && N % H = 0 H층 N/H호
	// H < N && N % H != 0 11층 20번째 손님 (N % H)층 (N/H+1)호?
	
	// 직각삼각형 - 피타고라스
	/*int a, b, c;
	for (; ;)
	{
		scanf("%d %d %d", &a, &b, &c);
		int A = a * a;
		int B = b * b;
		int C = c * c;
		if (a != 0 && b != 0 && c != 0)
		{
			if (a > b && a > c)
			{
				if (A == B + C)
					printf("right\n");
				else
					printf("wrong\n");
			}
			else if (b > a && b > c)
			{
				if (B == A + C)
					printf("right\n");
				else
					printf("wrong\n");
			}
			else if (c > a && c > b)
			{
				if (C == A + B)
					printf("right\n");
				else
					printf("wrong\n");
			}
		}
		else if (a == 0 && b == 0 && c == 0)
			break;
	}*/

	/*int N;
	int M=0;
	float sum = 0;
	int score[1000];
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &score[i]);		
	}

	for (int i = 0; i < N; i++)
	{
		if (M < score[i])
			M = score[i];
	}

	for (int i = 0; i < N; i++)
	{
		sum += (float)score[i] / M * 100;
	}

	printf("%f", sum / N);*/

	int L;
	int r = 1;
	int M = 1234567891;
	int H = 0;
	char orgin[51];
	int num[50];

	scanf("%d", &L);
	scanf("%s", orgin);
	
	for (int i = 0; i < L; i++)
	{
		num[i] = orgin[i] - 96;
		H += num[i] * r % M;
		r = (r * 31) % M;
	}
	printf("%d", H);
	
}
