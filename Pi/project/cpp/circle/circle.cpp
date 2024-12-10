#include <iostream>
#include "circle.h"
#include "circle.h"
#include "circle.h"

Circle::Circle()
{
    radius = 1;
    std::cout << "생성자 호출\n";
}

Circle::Circle(int r)
{
    setRadius(r);
    std::cout << "생성자 호출\n";
}

Circle::~Circle()
{
    std::cout << "소멸자 호출\n";
}

int Circle::getRadius()
{
    return radius;
}

void Circle::setRadius(int r)
{
    radius = r;
}

double Circle::getArea()
{
    return radius * radius * 3.14;
}

double Circle::getPi()
{
    return 3.14;
}
