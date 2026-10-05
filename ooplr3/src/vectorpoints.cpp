#include<vectorpoints.h>
#include<point.h>

Vectorpoints::Vectorpoints() : size(0), capacity(1), v(new Point[capacity]) {}

Vectorpoints::Vectorpoints(size_t n) : size(n), capacity(2 * n), v(new Point[capacity]) {}

Vectorpoints::Vectorpoints(const Vectorpoints& other)
    : size(other.size), capacity(other.capacity),
      v(new Point[capacity]) {
  std::copy(other.v, other.v + size, v);
}

Vectorpoints::Vectorpoints(Vectorpoints&& other) noexcept
    : size(other.size), capacity(other.capacity), v(other.v) {
  other.clear();
}

Vectorpoints::~Vectorpoints() { delete[] v; }

void Vectorpoints::resize(size_t newsize) {
  capacity = newsize;
  Point *t = new Point[capacity];
  std::copy(v, v + size, t);
  delete[] v;
  v = t;
}

void Vectorpoints::push(Point c) {
  if (size >= capacity) {
    resize(2 * capacity);
  }
  v[size++] = c;
}

void Vectorpoints::pop() {
  if (size) {
    --size;
  }
}

void Vectorpoints::set(size_t i, Point p) { v[i] = p; }

Point Vectorpoints::get(size_t i) const { return v[i]; }

size_t Vectorpoints::len() const { return size; }

void Vectorpoints::clear() {
  size = 0;
  capacity = 1;
  delete[] v;
  v = new Point[capacity];
}