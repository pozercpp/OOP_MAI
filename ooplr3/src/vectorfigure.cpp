#include<vectorfigure.h>
#include<figure.h>

Vectorfigure::Vectorfigure() : size(0), capacity(1), v(new Figure*[capacity]) {}

Vectorfigure::Vectorfigure(const Vectorfigure& other)
    : size(other.size), capacity(other.capacity),
      v(new Figure*[capacity]) {
  std::copy(other.v, other.v + size, v);
}

Vectorfigure::Vectorfigure(Vectorfigure&& other) noexcept
    : size(other.size), capacity(other.capacity), v(other.v) {
  other.clear();
}

Vectorfigure::~Vectorfigure() { delete[] v; }

void Vectorfigure::resize(size_t newsize) {
  capacity = newsize;
  Figure** t = new Figure*[capacity];
  std::copy(v, v + size, t);
  delete[] v;
  v = t;
}

void Vectorfigure::erase(size_t ind) {
  for (size_t i = ind; i < size; ++i) {
    v[i] = v[i + 1];
  }
  --size;
}

void Vectorfigure::push(Figure* c) {
  if (size >= capacity) {
    resize(2 * capacity);
  }
  v[size++] = c;
}

void Vectorfigure::pop() {
  if (size) {
    --size;
  }
}

Figure* Vectorfigure::get(size_t i) { return v[i]; }

size_t Vectorfigure::len() { return size; }

void Vectorfigure::clear() {
  size = 0;
  capacity = 1;
  delete[] v;
  v = new Figure*[capacity];
}