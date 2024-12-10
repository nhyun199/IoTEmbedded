#include <iostream>
#include <string>
using namespace std;

class Shape_2 {
protected :
    string name;
    int width, height;
public :
    Shape_2(string n = "", int w = 0, int h = 0) {name = n; width = w; height = h;}
    virtual double getArea() {return 0;}
    string getName() {return name;} 
};

class Oval : public Shape_2 {
public :
    Oval(string name, int w, int h) : Shape_2(name, w, h) {};
    double getArea() override
    {
        double area = 3.14 * width * height;
        return area;
    }
};

class Rect_2 : public Shape_2 {
public :
    Rect_2(string name, int w, int h) : Shape_2(name, w, h) {};
    double getArea() override
    {
        double area = width * height;
        return area;
    }
};

class Triangular : public Shape_2 {
public :
    Triangular(string name, int w, int h) : Shape_2(name, w, h) {};
    double getArea() override
    {
        double area = 0.5 * width * height;
        return area;
    }
};

int main()
{
    Shape_2 *p[3];
    p[0] = new Oval("빈대떡", 10, 20);
    p[1] = new Rect_2("찰떡", 30, 40);
    p[2] = new Triangular("토스트", 30, 40);

    for(int i = 0; i < 3; i++)
        cout << p[i]->getName() << " 넓이는 " << p[i]->getArea() << endl;

    for(int i = 0; i < 3; i++) delete p[i];
}