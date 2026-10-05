#pragma once

#include <initializer_list>
#include <myvector.h>

class Decimal {
public:
  Decimal();
  Decimal(std::initializer_list<unsigned char>);
  Decimal(unsigned long long);
  Decimal(unsigned int);

  ~Decimal() noexcept;
  Decimal(const Decimal &);
  Decimal(Decimal &&) noexcept;

  unsigned char get(size_t) const;

  int len() const;

  void print();

  MyVector v;

  static Decimal plus(const Decimal&, const Decimal&);
  static Decimal sub(const Decimal&, const Decimal&);

  static bool equals(const Decimal&, const Decimal&);
  static bool greater(const Decimal&, const Decimal&);
  static bool less(const Decimal&, const Decimal&);
  static bool equalsgreater(const Decimal&, const Decimal&);
  static bool equalsless(const Decimal&, const Decimal&);
  static bool notequals(const Decimal&, const Decimal&);
};