#include <iostream>

using namespace std;

extern "C"
{
    #include "get.c"
}

int main()
{
    int a = get();
    int b= get();
    cout << "곱은 " << a * b << "입니다.\n";
    return 0;
}