#include <stdio.h>

int main()
{
	short a = 3;
	int b= 20;
	float c = 1.5f;
	double d = 44.0;
	char e = 'A';
	char f[10] = {'a', 'b'};
	int g[10] = { 1, 2, 3 };

	printf("short = %d\n", sizeof(a));
	printf("int = %d\n", sizeof(b));
	printf("float = %d\n", sizeof(c));
	printf("double = %d\n", sizeof(d));
	printf("char = %d\n", sizeof(e));
	printf("char[] = %d\n", sizeof(f)); // sizeof(�迭�̸�)�� ����ϸ� �ش��ϴ� �ڷ����� �޸� ũ�⿡ ����� ������ ���ؼ� ��ü �޸𸮸� �����
	printf("int[] = %d\n", sizeof(g)); //  ���� ���� char�� �迭�� sizeof�������� ����� 1 * 10 = 10, int�� �迭�� sizeof�������� ����� 4 * 10 = 40�� �ȴ�./
}