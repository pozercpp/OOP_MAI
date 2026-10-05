#include "myvector.h"

MyVector::MyVector() : size(0), capacity(1), v(new unsigned char[capacity]) {}

MyVector::MyVector(const MyVector &other)
    : size(other.size), capacity(other.capacity),
      v(new unsigned char[capacity]) {
  std::copy(other.v, other.v + size, v);
}

MyVector::MyVector(MyVector&& other) noexcept
    : size(other.size), capacity(other.capacity), v(other.v) {
  other.clear();
}

MyVector::~MyVector() noexcept { delete[] v; }

void MyVector::resize(size_t newsize) {
  capacity = newsize;
  unsigned char *t = new unsigned char[capacity];
  std::copy(v, v + size, t);
  delete[] v;
  v = t;
}

void MyVector::push(unsigned char c) {
  if (size >= capacity) {
    resize(2 * capacity);
  }
  v[size++] = c;
}

void MyVector::pop() {
  if (size) {
    --size;
  }
}

unsigned char MyVector::get(size_t i) const { return v[i]; }

size_t MyVector::len() const { return size; }

void MyVector::swap(size_t i, size_t j) {
  unsigned char c = v[i];
  v[i] = v[j];
  v[j] = c;
}

void MyVector::clear() {
  size = 0;
  capacity = 1;
  delete[] v;
  v = new unsigned char[capacity];
}