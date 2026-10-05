#pragma once

class MyVector {
private:
  size_t size;
  size_t capacity;
  unsigned char *v;
  void resize(size_t sz);

public:
  void push(unsigned char);
  void pop();
  void clear();

  unsigned char get(size_t) const;

  void swap(size_t, size_t);

  size_t len() const;

  MyVector(MyVector&&) noexcept;
  MyVector(const MyVector &);
  MyVector();
  ~MyVector() noexcept;
};