#pragma once

class Circle
{
private :
    int radius;

public :
    Circle();
    Circle(int r);
    ~Circle();
    int getRadius();
    void setRadius(int r);
    double getArea();
    static double getPi();
};

