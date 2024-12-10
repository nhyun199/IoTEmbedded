#include <iostream>
#include <string>
#include "person3.h"
using namespace std;

Person::Person(int id, const string name)
{
    this->id = id;
    this->name = name;
}

void Person::changeName(const string name)
{
    this->name = name;
}

Person::~Person()
{

}

void Person::show()
{
    cout << this->name << '\n';
}
