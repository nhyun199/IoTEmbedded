#include <iostream>
using namespace std;

class Power
{
    int kick;
    int punch;

public:
    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }

    void show();

    Power operator-(Power op2);
    Power operator+(Power op2);
    Power operator+(int op1);
    friend Power operator+(int op1, Power op2);
    Power operator*(Power op2);

    Power &operator++();
    Power operator++(int);

    Power& operator<<(int op1);
};

void Power::show()
{
    cout << "kick = " << kick << ", " << "punch = " << punch << endl;
}

Power Power::operator-(Power op2)
{
    Power tmp;
    tmp.kick = this->kick - op2.kick;
    tmp.punch = this->punch - op2.punch;

    if (tmp.kick < 0)
        tmp.kick = 0;

    if (tmp.punch < 0)
        tmp.punch = 0;

    return tmp;
}

Power Power::operator+(Power op2)
{
    Power tmp;
    tmp.kick = this->kick + op2.kick;
    tmp.punch = this->punch + op2.punch;
    return tmp;
}

Power Power::operator+(int op1)
{
    Power tmp;
    tmp.kick = this->kick + op1;
    tmp.punch = this->punch + op1;
    return tmp;
}

Power Power::operator*(Power op2)
{
    Power tmp;
    tmp.kick = this->kick * op2.kick;
    tmp.punch = this->punch * op2.punch;
    return tmp;
}

Power &Power::operator++()
{
    ++kick;
    ++punch;
    return *this;
}

Power Power::operator++(int)
{
}

Power &Power::operator<<(int op1)
{
    this->kick += op1;
    this->punch += op1;
    return *this;
}

int main()
{
    Power a(3, 5), b(4, 6), c, d, e;
    c = a + b;
    d = a - b;
    e = a * b;
    a.show();
    b.show();
    cout << "\n--- instance plus ---\n";
    c.show();
    cout << "--- instance subtract ---\n";
    e.show();
    cout << "--- instance multiply ---\n";
    d.show();
    d = b - a;
    d.show();
}

Power operator+(int op1, Power op2)
{
    Power tmp;
    tmp.kick = op1 + op2.kick;
    tmp.punch = op1 + op2.punch;
    return tmp;
}
