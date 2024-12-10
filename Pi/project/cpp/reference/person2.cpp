#include <iostream>
#include <cstring>
#include "person2.h"
using namespace std;

Person::Person(int id, const char *name)
{
    this->id = id;
    int len = strlen(name);
    this->name = new char[len+1];
    strcpy(this->name, name);
}

Person::Person(const Person &copy)
{
    this->id = copy.id;
    int len = strlen(copy.name);
    this->name = new char[len+1];
    strcpy(this->name, copy.name);
}

Person::~Person()
{
    if(name)
    {
        delete [] name;
    }
}

void Person::changeName(const char *name)
{ 
    if(name)
        delete [] this->name;

    int len = strlen(name);
    this->name = new char[len+1];
    strcpy(this->name, name);
}

void Person::show()
{
    cout << this->name << '\n';
}
