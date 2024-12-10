#include <iostream>
using namespace std;

template <typename T>
void mySwap(T &a, T &b)
{
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a = 4, b = 5;
    mySwap(a, b);
    cout << "a = " << a << ", b = " << b << endl;
    double c = 0.3 , d = 12.5;
    cout << "c = " << c << ", d = " << d << endl;
}