#pragma once
#include<iostream>
#include<figure.h>

class Triangle : public Figure {
public:
    Triangle();
    ~Triangle();
    Triangle(Point, Point, Point);
    long double Area();
    Point Centr();
};