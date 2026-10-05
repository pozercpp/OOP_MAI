#pragma once

#include <memory>
#include <initializer_list>
#include <cstddef>
#include <memory_resource>

#include <allocator.h>

template<class T, class Alloc = std::pmr::polymorphic_allocator<T>>
class Array {
    using traits = std::allocator_traits<Alloc>;
    size_t sz = 0;
    size_t cap = 0;
    T* v = nullptr;
    Alloc alloc;

public:
    using iterator = T*;
    using const_iterator = const T*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    Array();
    Array(size_t size, const Alloc& a = Alloc());
    Array(size_t size, const T& value, const Alloc& a = Alloc());
    Array(const std::initializer_list<T>& lst, const Alloc& a = Alloc());
    Array(const Array& other);
    Array(Array&& other) noexcept;
    ~Array();

    void resize(size_t new_size);
    void reserve(size_t new_cap);
    void push(const T& value);
    void pop();
    void erase(size_t ind);
    void clear();

    size_t size() const;
    size_t capacity() const;

    T& operator[](size_t i);
    const T& operator[](size_t i) const;

    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;

    iterator begin() noexcept;
    iterator end() noexcept;
    const_iterator begin() const noexcept;
    const_iterator end() const noexcept;
    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;

    reverse_iterator rbegin() noexcept;
    reverse_iterator rend() noexcept;
    const_reverse_iterator rbegin() const noexcept;
    const_reverse_iterator rend() const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend() const noexcept;
};

#include <array.ipp>