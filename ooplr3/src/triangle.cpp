#include<triangle.h>

Triangle::Triangle() {
    for (int i = 0; i < 3; ++i) {
        v.push(Point(0, 0));
    }
}

Triangle::Triangle(Point p1, Point p2, Point p3) {
    v.push(p1);
    v.push(p2);
    v.push(p3);
}

long double Triangle::Area() { return CalcArea(v); }

Point Triangle::Centr() { return CalcCentr(v); }

Triangle::~Triangle() {}