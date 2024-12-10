#include <iostream>
#include <string>
using namespace std;

class MyException : exception {
    int lineNo;
    string func, msg;
public :
    MyException(int n, string f, string m)
    {
        this->lineNo = n;
        this->func = f;
        this->msg = m;
    }
    void print()
    {

    }
};

int main()
{

    return 0;
}