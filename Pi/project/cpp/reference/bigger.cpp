#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big)
{
    if(a == b)
    {
        
        return true;
    }
    else
    {
        a > b ? big = a : big = b;
        
        return false;
    }
}

int main()
{
    int a, b;
    int big;
    cin >> a >> b;
    if(bigger(a, b, big))
    {
        cout << "a와 b는 같습니다.\n";
    }
    else
    {
        cout << "큰 수는 " << big << "입니다.\n";
    }
    
}