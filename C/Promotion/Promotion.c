#include <stdio.h>

int main()
{
	// 형변환(Casting) : 자료형을 강제로 바꿈, 암시적(묵시적, 암묵적)형변환, 명시적 형변환이 있음
	// 승격(Promtion) : 작은 범위의 자료형을 큰 범위의 자료형으로 변환
	// 정수 / 정수 = 정수 -> 소수점 아래는 버려진다.
	// 자료형이 다른 수들의 연산에서 자료형은 큰 값에 맞춰진다.

	char ch = 'A';
	int nData = 25;
	float fData1 = 2.5f;	
	
	printf("%d\n", ch + 1); // char 자료형의 ch를 int 자료형으로 승격하고 연산을 수행
	printf("%c\n", ch + 1); // 연산을 수행한 결과를 다시 char 자료형으로 출력함
	printf("%.3f\n", nData * fData1); // int 자료형의 nData를 float 자료형으로 승격하고 연산을 수행, 소수점 아래 세자리까지 출력함
	printf("%f\n", (float)nData / 10 * fData1); // nData를 float로 형변환 한 후 연산을 수행하고 결과를 출력
	printf("%d\n", (int)((float)nData / 10 * fData1)); // 위와 같으나 결과값을 int 자료형으로 강제 변환하여 소수점 아래가 소실됨
	printf("%f\n", (float)(nData / 5)); // 정수 / 정수 = 정수이나 float로 형변환하여 float 형태로 출력함/

}