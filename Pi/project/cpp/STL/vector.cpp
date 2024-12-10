#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;

    for (int i = 0; i < 10; i++)
        v.push_back(i);

    for(int i = 0; i < v.size(); i++)
        cout << v.at(i) << " ";
    cout << endl;
    
    vector<int>::iterator it;
    it = v.begin();

    for(auto i = v.begin(); i != v.end(); i++)
    {
        it = v.erase(it);
    }

    for(int i = 0; i < v.size(); i++)
        cout << v.at(i) << " ";
    cout << endl;

    return 0;
}