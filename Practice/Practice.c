#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

int AtSign(int A, int B)
{
	int C;
	C = (A + B) * (A - B);
	return C;
}

int Factorial(int f)
{
	if (f == 1 || f == 0)
	{
		return 1;
	}

	int factorial = 1;
	for (int i = 2; i <= f; i++)
	{
		factorial = factorial * i;
		
	}
	return factorial;
}

int isNumeric(char *ch) // 문제에서 빈 문자열은 들어오지않는다고 가정함.
{
	int len = strlen(ch);
	for (int i = 0; i < len; i++)
	{
		if (!isdigit(ch[i]))
			return 0;
	}

	return 1;
}

void palindrome(int num)
{
	char num_ch[6];
	char num_pal[6];
	char temp[6];
	int correct = 0;

	sprintf(num_ch, "%d", num);
	
	for (int i = 0; i < strlen(num_ch); i++)
	{
		temp[i] = num_ch[i];
		num_pal[strlen(num_ch) - 1 - i] = temp[i];
	}
	num_pal[strlen(num_ch)] = '\0';

	for (int i = 0; i < strlen(num_ch); i++)
	{
		if (num_ch[i] == num_pal[i])
		{
		}
		else
			correct++;
	}

	if (correct > 0)
		printf("no\n");
	else
		printf("yes\n");
}

void Dice(int s, int dice[])
{
	for (int i = 0; i < s; i++)
	{
		dice[i] = i+1;
	}
}

int MenOfPassion(int A[], int n)
{
	int i = n / 2;
	return A[i];
}

// 분해합을 구하는 함수 범위 : 최대 6자리까지
// n = 분해합을 구하려는 수
int digitsum(int n)
{
	//int N[6] = { 0 };
	int sum = n;
	/*N[0] = n / 100000;
	N[1] = (n % 100000) / 10000;
	N[2] = (n % 10000) / 1000;
	N[3] = (n % 1000) / 100;
	N[4] = (n % 100) / 10;
	N[5] = (n % 10);
	for (int i = 0; i < 6; i++)
	{
		sum += N[i];
	}*/
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

void sort(int len, int max, int min, int A[], int B[], int C[])
{
	// 음수도 들어올 수 있다.
	int range = max - min + 1;

	for (int i = 0; i < len; i++)
	{
		B[A[i] - min]++;
	}

	for (int i = 1; i < range; i++)
	{
		B[i] = B[i] + B[i - 1];
	}

	for (int i = len-1; i >= 0; i--)
	{
		C[B[A[i] - min] - 1] = A[i];
		B[A[i] - min]--;
	}
}

int compare(const void* a, const void* b)
{
	if (*(int*)a > *(int*)b)
		return 1;
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}

int compare2(const void* a, const void* b)
{
	int* coordA = (int*)a;
	int* coordB = (int*)b;

	if (coordA[0] != coordB[0])
	{
		return coordA[0] - coordB[0];
	}
	return coordA[1] - coordB[1];

}

int compare3(const void* a, const void* b)
{
	char* A = (char*)a;
	char* B = (char*)b;

	if (strlen(A) != strlen(B))
		return strlen(A) - strlen(B);

	return strcmp(A, B);
}
typedef struct
{
	int age;
	char id[101];
} INFO;

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

			/*int L;
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
			printf("%d", H);*/

			// 소수 찾기
			// 소수 = 1을 제외한, 1과 자기자신으로만 나누어 떨어지는 수를 말함.
			// 수 n이 있으면.. 2부터 n-1까지 나누었을때.. 나머지가 0이면 안됨.

			/*int N;
			int prime[100];
			int count = 0;
			scanf("%d", &N);

			for (int i = 0; i < N; i++)
			{
				scanf("%d", &prime[i]);
			}

			for (int i = 0; i < N; i++)
			{
				int is_prime = 1;

				if (prime[i] == 1)
					continue;

				for (int j = 2; j < prime[i]; j++)
				{
					if (prime[i] % j == 0)
					{
						is_prime = 0;
						break;
					}
				}

				if (is_prime)
					count++;
			}
			printf("%d", count);*/

			/*int n, k;
			int Bino = 0;
			scanf("%d %d", &n, &k);

			Bino = Factorial(n) / (Factorial(k) * Factorial(n - k));

			printf("%d", Bino);*/

			/*int n = 0;
			char ch1[9];
			char ch2[9];
			char ch3[9];
			scanf("%s %s %s", ch1, ch2, ch3);

			if (isNumeric(ch1))
			{
				n = atoi(ch1) + 3;
			}
			else if (isNumeric(ch2))
			{
				n = atoi(ch2) + 2;
			}
			else if (isNumeric(ch3))
			{
				n = atoi(ch3) + 1;
			}

			if (n % 3 == 0 && n % 5 == 0)
				printf("FizzBuzz");

			else if (n % 3 == 0 && n % 5 != 0)
				printf("Fizz");

			else if (n % 3 != 0 && n % 5 == 0)
				printf("Buzz");

			else
				printf("%d", n);*/

				/*int n1, n2;
				int gcd = 0;
				int lcm = 0;
				int d1 = 1, d2 = 1;
				scanf("%d %d", &n1, &n2);

				for (int i = 1; i <= n1; i++)
				{
					for (int j = 1; j <= n2; j++)
					{
						if (n1 % i == 0)
							d1 = i;

						if (n2 % j == 0)
							d2 = j;

						if (d1 == d2 && gcd <= d1)
							gcd = d1;
					}
				}

				lcm = gcd * (n1 / gcd) * (n2 / gcd);
				printf("%d\n%d", gcd, lcm);*/

				/*int n = -1;
				while (1)
				{
					scanf("%d", &n);
					if (n != 0)
						palindrome(n);
					else
						break;
				}*/

				//int A; // 하루에 올라가는 높이
				//int B; // 하루에 미끄러지는 높이
				//int V; // 나무 막대의 높이
				//int H = 0;
				////int M = 1000000001;
				//int day = 0;
				//scanf("%d %d %d", &A, &B, &V);

				//day = ((V-B-1) / (A - B)) + 1;
				//printf("%d", day);

				/*int N;
				scanf("%d", &N);

				int* num = (int*)malloc(N * sizeof(int));

				for (int i = 0; i < N; i++)
				{
					scanf("%d", &num[i]);
				}

				for (int i = 0; i < N-1; i++)
				{
					for (int j = 0; j < N - i - 1; j++)
					{
						if (num[j] > num[j + 1])
						{
							int temp = num[j];
							num[j] = num[j + 1];
							num[j + 1] = temp;
						}
					}
				}

				for(int i = 0; i < N; i++)
				{
					printf("%d ", num[i]);
				}

				free(num);*/

				/*int N;
				scanf("%d", &N);
				long long fac = 1;

				if(N == 0 || N == 1)
					printf("1");

				else
				{
					for(int i = N; i > 1; i--)
					{
						fac = fac * i;
					}
					printf("%lld",fac);
				}*/

				/*int correct[11] = { 12, 11, 11, 10, 9, 9, 9, 8, 7, 6, 6 };
				int penalty[11] = { 1600, 894, 1327, 1311, 1004, 1178, 1357, 837, 1055, 556, 773 };
				int N;
				scanf("%d", &N);
				printf("%d %d", correct[N - 1], penalty[N - 1]);*/

	/*double a;
	double b;
	double c;
	int count = 1;

	for (; ; )
	{
		scanf("%lf %lf %lf", &a, &b, &c);

		if (a == 0 && b == 0 && c == 0)
			break;

		else
		{
			printf("Triangle #%d\n", count);
			if (c == -1)
			{
				c = sqrt(a * a + b * b);
				printf("c = %.3lf\n", c);
			}
			else if (a == -1 && b < c)
			{
				a = sqrt(c * c - b * b);
				printf("a = %.3lf\n", a);
			}
			else if (b == -1 && a < c)
			{
				b = sqrt(c * c - a * a);
				printf("b = %.3lf\n", b);
			}
			else
				printf("Impossible.\n");
		}
		count++;
		printf("\n");
	}*/

	//int S1; // 1~20의 눈
	//int S2; // 1~20의 눈
	//int S3; // 1~40의 눈
	//// 최소 1+1+1 = 3 최대 20+20+40 = 80 3~80
	//int sum[81] = { 0 }; // 3~80의 결과를 저장할 배열
	//int maxcount = 0;
	//int result = 0;
	//scanf("%d %d %d", &S1, &S2, &S3);

	//int* dice1 = (int*)calloc(S1, sizeof(int));
	//int* dice2 = (int*)calloc(S2, sizeof(int));
	//int* dice3 = (int*)calloc(S3, sizeof(int));

	//Dice(S1, dice1);
	//Dice(S2, dice2);
	//Dice(S3, dice3); // dice 배열에 모든 눈을 넣음 dice[0] = 1, dice[1] = 2...

	//for (int i = 0; i < S1; i++)
	//{
	//	for (int j = 0; j < S2; j++)
	//	{
	//		for (int k = 0; k < S3; k++)
	//		{
	//			sum[dice1[i] + dice2[j] + dice3[k]]++;
	//		}
	//	}
	//}

	//for (int i = 3; i < 81; i++)
	//{
	//	if (maxcount < sum[i])
	//	{
	//		maxcount = sum[i];
	//		result = i;
	//	}
	//}

	//printf("%d", result);

	//free(dice1);
	//free(dice2);
	//free(dice3);

	//int N; // 참가자의 수 1 ~ 10억
	//int s, m, l, xl, xxl, xxxl; // 티셔츠 사이즈별 신청(필요) 수량 0 ~ 10억 s+ m+ l+ xl+ xxl+ xxxl = N
	//int size[6];
	//int T, P; // T 티셔츠 묶음 수, P 펜의 묶음 수
	//int Tn = 0;
	//int PN = 0;
	//int Pn = 0;
	//scanf("%d", &N);
	//scanf("%d %d %d %d %d %d", &s, &m, &l, &xl, &xxl, &xxxl);
	//scanf("%d %d", &T, &P);
	//
	//size[0] = s;
	//size[1] = m;
	//size[2] = l;
	//size[3] = xl;
	//size[4] = xxl;
	//size[5] = xxxl;

	//for (int i = 0; i < 6; i++)
	//{
	//	if (size[i] % T == 0)
	//		Tn += size[i] / T;
	//	else
	//		Tn += size[i] / T + 1; // 올림처리		
	//}

	//PN = N / P;
	//if (N % P == 0)
	//	Pn = 0;
	//else
	//	Pn = N % P;

	//printf("%d\n%d %d", Tn, PN, Pn);

	//int N; // 생성자를 찾을 자연수
	//scanf("%d", &N);
	//int M = 0; // 생성자
	//for (int i = 1; i < 1000000; i++)
	//{
	//	if (digitsum(i) == N)
	//	{
	//		M = i;
	//		break;
	//	}
	//	else
	//		M = 0;
	//}
	//printf("%d", M);

	/*int L;
	int l = 0;
	scanf("%d", &L);

	for (int t = 1; t <= 200000; t++)
	{
		l = t * 5;
		if (L < l)
		{
			printf("%d", t);
			break;
	}*/

	/*char S[10];
	scanf("%s", S);
	if (strcmp(S, "SONGDO") == 0)
		printf("HIGHSCHOOL");
	else if (strcmp(S, "CODE"))
		printf("MASTER");
	else if (strcmp(S, "2023") == 0)
		printf("0611");
	else if (strcmp(S, "ALGORITHM") == 0)
		printf("CONTEST");*/

	// 세 제곱의 합?
	/*int N;
	scanf("%d", &N);
	int sum = 0;
	
	for (int i = 1; i <= N; i++)
	{
		sum += i;
	}
	printf("%d\n", sum);
	printf("%d\n", sum * sum);

	sum = 0;
	for (int i = 1; i <= N; i++)
	{
		
		sum += i * i * i;
	}
	printf("%d", sum);*/
	
	//int P; // 케이스 수
	//scanf("%d", &P);

	//int N; // 케이스 번호
	//float D ; // 철로의 길이
	//float A; // 기차의 속도
	//float B;
	//float F; // 파리의 속도
	//float t = 0;
	//
	//for (int i = 0; i < P; i++)
	//{
	//	scanf("%d %f %f %f %f", &N, &D, &A, &B, &F);
	//	printf("%d ", N);
	//	t = D / (A + B);
	//	printf("%f\n", F * t);
	//}
	
	/*int A, B, C, N;
	scanf("%d %d %d %d", &A, &B, &C, &N);
	int count = 0;
	for (int i = 0; i <= N / A; i++)
	{
		for (int j = 0; j <= N / B; j++)
		{
			for (int k = 0; k <= N / C; k++)
			{
				if (A * i + B * j + C * k == N)
				{
					count++;
				}
			}
		}
	}
	if (count > 0)
		printf("1");
	else
		printf("0");*/

	// 2 ~ 7	+6	1라인 
	// 8 ~ 19	+12	2라인 
	// 20 ~ 37	+18	3라인 
	// 38 ~ 61	+24	4라인 
	// 61 ~	90	+30	5라인
	// 13일때 2번째 라인이므로 3, 58은 4번째라인이므로 5
	// 주어진 N이 몇번째 라인인지 알 수 있는가?
	
	/*int N;
	scanf("%d", &N);	
	for (int i = 1; ; i++)
	{
		int honey1 = 3 * (i * i) - 3 * i + 2;
		int honey2 = 3 * (i * i) + 3 * i + 1;
		if (honey1 <= N && honey2 >= N)
		{
			printf("%d", i+1);
			break;
		}
		else if (N == 1)
		{
			printf("1");
			break;
		}
	}*/

	/*int N, M;
	int num[100] = {0};
	int sum = 0;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}

	for(int i = 0; i < N-2; i++)
		for(int j = i+1; j < N-1; j++)
			for (int k = j + 1; k < N; k++)
			{
				if (sum < num[i] + num[j] + num[k] && num[i] + num[j] + num[k] <= M)
					sum = num[i] + num[j] + num[k];
			}

	printf("%d", sum);*/
	
	/*int T;
	scanf("%d", &T);
	int k, n;
	int sum = 0;
	int A[15][15] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
	
	for (int i = 1; i < 15; i++)
	{
		for (int j = 1; j < 15; j++)
		{
			sum = sum + A[i-1][j];
			A[i][j] = sum;
		}
		sum = 0;
	}

	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &k, &n);
		printf("%d\n", A[k][n]);
	}
		*/
	
	/*int N;
	scanf("%d", &N);
	int max = 0;
	int min = 0;

	int* A = (int*)calloc(N, sizeof(int));
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
		if (max < A[i]) max = A[i];
		if (min > A[i]) min = A[i];
	}

	int range = max - min + 1;

	int* B = (int*)calloc(range, sizeof(int));
	int* C = (int*)calloc(N, sizeof(int));

	sort(N, max, min, A, B, C);
	for (int i = 0; i < N; i++)
	{
		printf("%d\n", C[i]);
	}

	free(A);
	free(B);
	free(C);*/

	//int N; 
	//scanf("%d", &N);
	//int(*physical)[2] = (int(*)[2])calloc(N, sizeof(int[2])); 
	//int* place = (int*)calloc(N, sizeof(int)); 

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < 2; j++)		
	//		scanf("%d", &physical[i][j]);
	//}

	//for (int i = 0; i < N; i++)
	//{
	//	for (int j = 0; j < N; j++)
	//	{
	//		if (i != j)
	//		{
	//			if (physical[i][0] < physical[j][0] && physical[i][1] < physical[j][1])
	//				place[i]++;
	//		}
	//	}
	//}
	//	
	//for (int i = 0; i < N; i++)
	//{
	//	printf("%d ", place[i] + 1);
	//}

	//free(physical);
	//free(place);

	/*int N;
	scanf("%d", &N);
	INFO* info = (INFO*)malloc(N * sizeof(INFO));

	for (int i = 0; i < N; i++)
	{
		scanf("%d %s", &info[i].age, info[i].id);
	}

	qsort(info, N, sizeof(INFO), compare);

	for (int i = 0; i < N; i++)
	{
		printf("%d %s\n", info[i].age, info[i].id);
	}
	

	free(info);*/	
	
	/*int N;
	scanf("%d", &N);

	int(*coord)[2] = (int(*)[2])calloc(N, sizeof(int[2]));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2; j++)
			scanf("%d", &coord[i][j]);
	}

	qsort(coord, N, sizeof(coord[0]), compare2);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d ", coord[i][j]);
		}
		printf("\n");
	}

	free(coord);*/

	int N;
	scanf("%d", &N);

	char(*S)[51] = (char(*)[51])malloc(N * sizeof(char[51]));

	for (int i = 0; i < N; i++)
	{
		scanf("%s", S[i]);
	}

	qsort(S, N, sizeof(S[0]), compare3);

	printf("%s\n", S[0]);
	for (int i = 1; i < N; i++)
	{
		if(strcmp(S[i], S[i-1]) != 0)
		printf("%s\n", S[i]);
	}

	free(S);
}

	


