#include<iostream>
#include"eliminate_unset_bits.h"
int main() {
    std::string number;
    std::cin >> number;
    std::cout << eliminate_unset_bits(number) << std::endl;
    return 0;
}