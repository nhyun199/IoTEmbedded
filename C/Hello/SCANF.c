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
	printf("�ּ� : %p %s",&ch,ch);*/

	// ���� �Ǵ��ϱ�
	int Year;
	printf("����� ������ �Է��ϼ��� :");
	scanf_s("%d", &Year);

	if ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0)
	{
		printf("%d���� �����Դϴ�.", Year);
	}
	else
		printf("%d���� ������ �ƴմϴ�.", Year);
	
}