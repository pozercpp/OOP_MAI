#include"eliminate_unset_bits.h"
long eliminate_unset_bits(std::string& number) {
    long res{0}, cur{0};
    std::string s;
    for (char c : number) {
        if (c - '0') {
            res += ((long)1 << cur);
            ++cur;
            s += c;
        }
    }
    number = s;
    return res;
}