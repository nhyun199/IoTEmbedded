#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, string> myMap;
    string values[] = {"Cat", "Dog", "Bird", "Lion", "Tiger"};

    map<string, string>::iterator it;
    
    for(int i = 0; i < 5; i++)
        myMap.insert(make_pair(i+1, values[i]));

    for(int i = 1 ; i < 6; i++)
        cout << i << " : " << myMap[i] << endl;

    return 0;
}