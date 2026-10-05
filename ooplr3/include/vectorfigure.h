#pragma once
#include <iostream>
#include<figure.h>

class Vectorfigure {
private:
  size_t size;
  size_t capacity;
  Figure** v;
  void resize(size_t sz);
public:
  void push(Figure*);
  void pop();
  void clear();
  void erase(size_t);

  Figure* get(size_t);
  
  size_t len();

  Vectorfigure(Vectorfigure&&) noexcept;
  Vectorfigure(const Vectorfigure&);
  Vectorfigure();
  ~Vectorfigure();
};