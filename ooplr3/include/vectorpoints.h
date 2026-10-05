#pragma once
#include <iostream>
#include<point.h>

class Vectorpoints {
private:
  size_t size;
  size_t capacity;
  Point* v;
public:
  void push(Point);
  void pop();
  void clear();
  void set(size_t, Point);
  void resize(size_t sz);

  Point get(size_t) const;

  size_t len() const;

  Vectorpoints(Vectorpoints&&) noexcept;
  Vectorpoints(const Vectorpoints&);
  Vectorpoints();
  Vectorpoints(size_t);
  ~Vectorpoints();
};