#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    for(int i = 0; i < 100; i++)
    {
        v.push_back(rand() % 100);
    }

    for(int i = 0; i < 100; i ++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    sort(v.begin(), v.end());

    for(int i = 0; i < 100; i ++)
    {
        cout << v[i] << " ";
    }
}