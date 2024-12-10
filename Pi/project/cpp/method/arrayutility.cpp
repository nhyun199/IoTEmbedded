#include <iostream>
#include <typeinfo>
using namespace std;

class ArrayUtility
{
public:
    static void intToDouble(int source[], double dest[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            dest[i] = (double)source[i];
        }
    }

    static void doubleToInt(double source[], int dest[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            dest[i] = (int)source[i];
        }
    }
};

int main()
{
    int x[] = {1, 2, 3, 4, 5};
    double y[5];
    double z[] = {9.9, 8.8, 7.7, 6.6, 5.6};

    ArrayUtility::intToDouble(x, y, 5);
    for (int i = 0; i < 5; i++)
        cout << y[i] << '(' << typeid(y[i]).name() << ") "; // double로 변환되었지만, 숫자만 출력하면 데이터 형식을 알 수 없어 typeid를 이용하여 데이터 형식도 함께 출력함
    cout << endl;

    ArrayUtility::doubleToInt(z, x, 5);
    for (int i = 0; i < 5; i++)
        cout << x[i] << '(' << typeid(x[i]).name() << ") ";
    cout << endl;
}