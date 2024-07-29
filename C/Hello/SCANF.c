#include <stdio.h>

void main()
{
	/*char szBuffer[128] = { 0 };
	printf("Input string: ");

	scanf_s("%s", &szBuffer, 128);
	puts(szBuffer);*/

	/*char szBuffer[20] = { 0 };
	printf("Input string: ");

	scanf_s("%s", &szBuffer, 20);
	puts(szBuffer);*/
		
	/*char ch;
	ch = getchar();
	ch = getchar();
	printf("%c", ch);
	ch = getchar();*/

	/*char ch[32] = { 0 };
	gets(ch);
	printf("주소 : %p %s",&ch,ch);*/

	// 윤년 판단하기
	int Year;
	printf("계산할 연도를 입력하세요 :");
	scanf_s("%d", &Year);

	if ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0)
	{
		printf("%d년은 윤년입니다.", Year);
	}
	else
		printf("%d년은 윤년이 아닙니다.", Year);
	
}