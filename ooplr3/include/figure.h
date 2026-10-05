#pragma once
#include<iostream>
#include<vectorpoints.h>

using namespace std;

class Figure {
public:
    Vectorpoints v;
    Figure();
    virtual ~Figure();
    void ReadPoints(std::istream&);
    void PrintPoints(std::ostream&);
    virtual long double Area();
    friend bool operator==(Figure, Figure);
    friend bool operator!=(Figure, Figure);
protected:
    long double CalcArea(const Vectorpoints&) const;
    Point CalcCentr(const Vectorpoints&) const;
};
std::istream& operator>>(std::istream&, Figure&);
std::ostream& operator<<(std::ostream&, Figure&);