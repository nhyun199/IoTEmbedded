#include <iostream>
#include "circle.h"
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int p[n];

    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;

    for(int i = 0; i < 5; i++)
    {
        cout << p[i] << endl;
    }
    
    
    //Circle pArray2[n];

    //Circle *pArray = new Circle[n];

    //pArray[0].setRadius(10);
    //pArray[1].setRadius(20);
    //pArray[2].setRadius(30);

    // for(int i = 0; i < 3; i++)
    // {
    //     cout << pArray[i].getArea() << '\n';
    // }

    //delete [] pArray;
    return 0;
}