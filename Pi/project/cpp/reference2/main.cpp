#include "person3.h"
#include <iostream>
using namespace std;

int main()
{
    Person father(1, "Kitae");
    Person daughter(father);

    cout << "-----before\n";
    father.show();
    daughter.show();

    daughter.changeName("Grace");
    cout << "-----after\n";
    father.show();
    daughter.show();

    return 0;
}