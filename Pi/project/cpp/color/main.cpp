#include <iostream>
#include "color.h"
using namespace std;

int main()
{
    Color screenColor(255, 0, 0);
    Color *p;
    p = &screenColor;
    p->show();
    Color colors[3];
    p = colors;

    p[0].setColor(255, 0, 0);
    p[1].setColor(0, 255, 0);
    p[2].setColor(0, 0, 255);

    for(int i = 0; i < 3; i++)
        p[i].show();
}