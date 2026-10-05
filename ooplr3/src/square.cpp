#include<square.h>

Square::Square() {
    for (int i = 0; i < 4; ++i) {
        v.push(Point(0, 0));
    }
}

Square::Square(Point p1, Point p2, Point p3, Point p4) {
    v.push(p1);
    v.push(p2);
    v.push(p3);
    v.push(p4);
}

long double Square::Area() { return CalcArea(v); }

Point Square::Centr() { return CalcCentr(v); }

Square::~Square() {}