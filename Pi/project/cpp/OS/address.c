#include <stdio.h>
//#define _CRT_SECURE_NO_WRNINGS;

int main()
{
    int x = 5, y = 6, z = 7;
    //int *ptrx = &x, *ptry = &y, *ptrz = &z;
    char a = 'a', b = 'b', c = 'c';
    //char *ptra = &a, *ptrb = &b, *ptrc = &c;
    double dx = 0.3, dy = 6.6, dz = 5902.4;
    printf("This address is \"Logical address\"\n");
    printf("x : %p, y : %p,  z : %p\n", &x, &y, &z);
    printf("a : %p, b : %p,  c : %p\n", &a, &b, &c);
    printf("dx : %p, dy : %p,  dz : %p\n", &dx, &dy, &dz);

    return 0;
}