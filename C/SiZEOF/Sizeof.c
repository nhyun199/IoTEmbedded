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
	printf("char[] = %d\n", sizeof(f)); // sizeof(배열이름)을 사용하면 해당하는 자료형의 메모리 크기에 요소의 개수를 곱해서 전체 메모리를 계산함
	printf("int[] = %d\n", sizeof(g)); //  따라서 위의 char형 배열의 sizeof연산자의 결과는 1 * 10 = 10, int형 배열의 sizeof연산자의 결과는 4 * 10 = 40이 된다./
}