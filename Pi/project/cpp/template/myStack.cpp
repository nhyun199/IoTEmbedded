#include <iostream>
using namespace std;

template <typename T>
class AbstractStack {
public :
    virtual bool push(T element) = 0;
    virtual bool pop(T& element) = 0;
    virtual int size() = 0;
};

template <typename T>
class MyStack : public AbstractStack<T> {
private:
    T *stack;
    int top = 0;
    int capacity;
public :
    MyStack<T>(int capacity) 
    {
        this->capacity = capacity;
        stack = new T[capacity];
    }
    ~MyStack() {delete [] stack;}

    bool push(T element) override 
    {
        if(top == capacity)
        {
            cout << "Stack is Full." << endl;
            return false;
        }

        stack[top++] = element;
        return true;
    }

    bool pop(T& element) override 
    {
        if(top == 0)
        {
            cout << "Stack is Empty." << endl;
            return false;
        }

        element = stack[--top];
        return true;
    }
    int size() override {return top;}
};

int main()
{
    MyStack<int> iStc(10);
    
    for(int i = 1; i < 11; i++)
        iStc.push(i);
    

}