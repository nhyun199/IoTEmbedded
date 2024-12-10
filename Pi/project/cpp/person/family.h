#include "person.h"

class Family{
    Person *p;
    int size;
public :
    Family(string name, int size);
    void setName(int i, string name);
    void show();
    ~Family();
};