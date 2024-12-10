#include <iostream>
#include <string>
using namespace std;

class Person
{
    int id;
    string name;

public :
    Person(int id, const string name);
    ~Person();
    void changeName(const string name);
    void show();
};

