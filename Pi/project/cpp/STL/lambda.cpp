#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline void print(int n)
{
    cout << n << " ";
}


int main()
{
    //vector<int> v = {1,2,3,4,5};
    //for_each(v.begin(), v.end(), print);
    //for_each(v.begin(), v.end(), [] (int n) {cout << n << " ";});

    auto add = [](int x, int y){cout << x << '+' << y << '=' << x+y;};
    return 0;
}