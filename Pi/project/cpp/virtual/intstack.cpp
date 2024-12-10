#include <iostream>
using namespace std;

class AbstractStack {
public :
    virtual bool push(int n) = 0;
    virtual bool pop(int& n) = 0;
    virtual int size() = 0;
};

class IntStack : public AbstractStack {
private :
    int* stack;
    int capacity;
    int curr_size = 0;
public :
    IntStack(int capacity) 
    {
        this->capacity = capacity;
        stack = new int[capacity]();
    }

    bool push(int n) override
    {
        if(curr_size == capacity)
        {
            cout << "Stack is Full !!\n";
            return false;
        }

        stack[curr_size++] = n;
        cout << "PUSH : " << n << '\n';
        return true;
    }

    bool pop(int& n) override
    {
        if(curr_size == 0)
        {
            cout << "Stack is Empty !!\n";
            return false;
        }

        n = stack[curr_size-1];
        stack[curr_size-1] = 0;
        curr_size--;
        cout << "POP : " << n << '\n';
        return true;
    }

    int size() override {return this->curr_size;}

    void show()
    {
        if(curr_size == 0)
            cout << "Stack is Empty\n";
        else
        {
            for(int i = 0; i < this->size(); i++)
                cout << this->stack[i] << ' ';
            cout << endl;
        }
    }
};

int main()
{
    IntStack stk(10);
    
    int n = 0;

    for(int i = 1; i <= 7; i++)
        stk.push(i);
    
    stk.show();

    cout << "n is " << n << endl;
    cout << "size is " << stk.size() << '\n';

    for(int i = 0; i < 10; i++)
    {
        stk.pop(n);
        cout << "n is " << n << endl;
    }
    stk.show();
    cout << stk.size() << '\n';
}