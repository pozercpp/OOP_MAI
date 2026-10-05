#include "decimal.h"
#include <iostream>

int main() {
  unsigned long long aa;
  std::cin >> aa;
  Decimal a(aa);
  Decimal res1 = Decimal::plus(a, {1, 2, 3});
  res1.print();
  std::cout << std::endl;
  Decimal res2 = Decimal::sub(a, {1, 2, 3});
  res2.print();
  std::cout << std::endl;
  return 0;
}