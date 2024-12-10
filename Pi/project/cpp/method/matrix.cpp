#include <iostream>
using namespace std;

class Matrix
{
private:
    int matrix[4];

public:
    Matrix()
    {
        for (int i = 0; i < 4; i++)
        {
            this->matrix[i] = 0;
        }
    }
    Matrix(int a, int b, int c, int d)
    {
        this->matrix[0] = a;
        this->matrix[1] = b;
        this->matrix[2] = c;
        this->matrix[3] = d;
    }
    void show()
    {
        cout << "Matrix = { ";
        for (int i = 0; i < 4; i++)
        {
            cout << this->matrix[i] << ' ';
        }
        cout << "}\n";
    }

    // Matrix operator+(Matrix op1)
    // {
    //     Matrix tmp;
    //     for (int i = 0; i < 4; i++)
    //     {
    //         tmp.matrix[i] = matrix[i] + op1.matrix[i];
    //     }
    //     return tmp;
    // }

    // Matrix& operator+=(Matrix op1)
    // {
    //     for(int i = 0; i < 4; i++)
    //     {
    //         matrix[i] += op1.matrix[i];
    //     }
    //     return *this;
    // }

    // bool operator==(Matrix op1)
    // {
    //     bool correct = true;
    //     for(int i = 0; i < 4; i++)
    //     {
    //         if(matrix[i] == op1.matrix[i])
    //             correct = true;
    //         else
    //         {
    //             correct = false;
    //             break;
    //         }
    //     }
    //     return correct;
    // }

    friend Matrix operator+(Matrix op1, Matrix op2);
    friend Matrix operator+=(Matrix &op1, Matrix op2);
    friend bool operator==(Matrix op1, Matrix op2);
};

int main()
{
    Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
    c = a + b;
    a += b;
    a.show();
    b.show();
    c.show();
    if (a == c)
        cout << "a and c are the same" << endl;
}

Matrix operator+(Matrix op1, Matrix op2)
{
    Matrix tmp;
    for (int i = 0; i < 4; i++)
    {
        tmp.matrix[i] = op1.matrix[i] + op2.matrix[i];
    }
    return tmp;
}

Matrix operator+=(Matrix &op1, Matrix op2)
{
    for (int i = 0; i < 4; i++)
    {
        op1.matrix[i] += op2.matrix[i];
    }
    return op1;
}

bool operator==(Matrix op1, Matrix op2)
{
    bool correct = true;
    for (int i = 0; i < 4; i++)
    {
        if (op1.matrix[i] == op2.matrix[i])
            correct = true;
        else
        {
            correct = false;
            break;
        }
    }
    return correct;
}
