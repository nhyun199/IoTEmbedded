#include <iostream>
using namespace std;

class Shape {
private :
    Shape* next; // 객체가 담긴 주소
protected :
    // virtual void draw() 
    // {
    //     cout << "Shape\n";
    // }
    virtual void draw() = 0; // 순수 가상함수 => 파생 클래스에서 구현의 의무가 생김.
    
public :
    Shape() {next = NULL;}
    ~Shape();

    void paint() // 파생에서 draw 호출하기 위함 draw -> protected
    {
        draw();
    }

    Shape* add(Shape *p) // next에 새로운 객체를 추가?
    {
        this->next = p;
        return p;
    }
    
    Shape* getNext() {return next;}
    Shape* dequeue(Shape*& head) 
    {
        // 맨 앞 삭제 뒤로 연결
        if(head == NULL) return NULL;
        Shape *removed = head;
        head = head->next;

        removed->next = NULL;
        return removed;
    }

    Shape* pop(Shape* head, Shape*& last)
    {
        Shape* removed;

        if(last == NULL || head == NULL) return NULL;

        if(last == head)
        {
            removed = last;
            head = last = NULL;
            return removed;
        }

        Shape *curr = head;
        
        while(curr->next != last)
        {
            curr = curr->next;
        }

        removed = last;
        curr->next = NULL;
        last = curr;

        return removed;
    }

};

class Circle : public Shape{
protected :
    void draw() override
    {
        cout << "Circle\n";
    }
};

class Rect : public Shape{
protected :
    void draw() override
    {
        cout << "Rect\n";
    }
};

class Line : public Shape{
protected :
    void draw() override
    {
        cout << "Line\n";
    }
};

class Triangle : public Shape
{
protected :
    void draw() override
    {
        cout << "Triangle\n";
    }
};

int main()
{
    Shape* pStart = NULL;
    Shape* pLast = NULL;

    pStart = new Circle();
    pLast = pStart;
    pLast = pLast->add(new Rect());
    pLast = pLast->add(new Circle());
    pLast = pLast->add(new Line());
    pLast = pLast->add(new Rect());

    Shape *p = pStart;

    Shape* rValue = p->dequeue(p);

    Shape* rValue2 = p->pop(p ,pLast);

    rValue->paint();
    rValue2->paint();

    cout << "===========\n";

    while (p != NULL)
    {
        p->paint();
        p = p->getNext();
    }
    
}