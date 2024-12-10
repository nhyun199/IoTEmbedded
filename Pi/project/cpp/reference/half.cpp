#include <iostream>
using namespace std;

double half(double& n)
{
    return n /= 2.0;
}

int main()
{
    double n = 20;
    half(n);
    cout << n << '\n';
}