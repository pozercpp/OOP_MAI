#include<iostream>
#include<figure.h>
#include<octagon.h>
#include<square.h>
#include<triangle.h>
#include<vectorfigure.h>
int main() {
    Vectorfigure v;
    std::cout << "INPUT VECTOR SIZE ";
    int n;
    std::cin >> n;
    std::cout << "1-Octagon\n2-Square\n3-Triangle\n";
    for (int i = 0; i < n; ++i) {
        char c;
        std::cin >> c;
        Figure* f;
        if (c == '1') {
            f = new Octagon();
        } else if (c == '2') {
            f = new Square();
        } else if (c == '3') {
            f = new Triangle();
        } else {
            std::cout << endl;
        }
        std::cin >> *f;
        v.push(f);
    }
    std::cout << "INPUT ERASE INDEX\n";
    size_t ind;
    std::cin >> ind;
    v.erase(ind);
    std::cout << v.len() << std::endl;
    for (size_t i = 0; i < v.len(); ++i) {
        std::cout << v.get(i)->Area() << std::endl;
    }
    return 0;
}