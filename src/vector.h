#pragma once

#include <iostream>
#include <string>

template<typename T>
class Vector {

private:
    T *data = nullptr;
    unsigned size = 0;
    int last = 0;

public:
    Vector();

    Vector(unsigned size);

    Vector(const Vector<T> &other);

    ~Vector();

    void resize(unsigned newSize, const std::nothrow_t &) noexcept;

    void push_back(const T &item);

    void print() const;

    void operator=(const Vector &other);

    int operator[](unsigned index);

    Vector operator+(const Vector &other);
};

#include "vector.cpp"