#include "MyIntStack.h"

MyIntStack::MyIntStack()
{
    tos = -1;
}

bool MyIntStack::push(int n)
{
    if(tos < 9)
    {
        tos++;
        p[tos] = n;
        return true;
    }
    else
        return false;
}

bool MyIntStack::pop(int &n)
{
    if(tos >= 0)
    {
        n = p[tos];
        tos--;
        return true;
    }
    else
        return false;
    
}
