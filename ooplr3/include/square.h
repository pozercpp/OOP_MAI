#pragma once
#include<iostream>
#include<figure.h>

class Square : public Figure {
public:
    Square();
    ~Square();
    Square(Point, Point, Point, Point);
    long double Area();
    Point Centr();
};