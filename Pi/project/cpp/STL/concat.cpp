#include <iostream>
using namespace std;

template <typename T>
T* concat(T a[], int sizea, T b[], int sizeb)
{
    T *c = new T[sizea + sizeb];
    for(int i = 0; i < sizea; i++)
    {
        c[i] = a[i];
    }

    for(int i = 0; i < sizeb; i++)
    {
        c[sizea+i] = b[i];
    }

    return c;
}

int main()
{
    int a[] = {1, 2, 3, 4};
    int b[] = {5, 6, 7, 8};

    int *c = concat(a, 4, b, 4);

    for(int i = 0; i < 8; i++)
        cout << c[i] << ' ';
    cout << endl;
    double da[] = {1.1, 2.1, 3.1, 4.1};
    double db[] = {5.1, 6.1, 7.1, 8.1};

    double *dc = concat(da, 4, db, 4);

    for(int i = 0; i < 8; i++)
        cout << dc[i] << ' ';

    return 0;
}