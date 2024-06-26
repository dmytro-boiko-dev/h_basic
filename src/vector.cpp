#ifndef VECTOR_CPP
#define VECTOR_CPP

#include "vector.h"

template<typename T>
Vector<T>::Vector() = default;

template<typename T>
Vector<T>::Vector(unsigned size) {
    data = new T[size]();
    this->size = size;
}

template<typename T>
Vector<T>::Vector(const Vector<T>& other) : size(other.size), last(other.last) {
    data = new T[size];
    for (int i = 0; i < last; i++) {
        data[i] = other.data[i];
    }
}

template<typename T>
Vector<T>::~Vector() {
    std::cout << "Vector with size " << size << " destroyed." << std::endl;
    delete[] data;
}

template<typename T>
void Vector<T>::resize(unsigned newSize, const std::nothrow_t &) noexcept {
    if (newSize > size) {
        T *temp = new T[newSize]();
        int tempLast = last;

        for (int i = 0; i < last; i++) {
            temp[i] = data[i];
        }

        delete[] data;

        last = tempLast;
        size = newSize;
        data = temp;
    }
}

template<typename T>
void Vector<T>::push_back(const T &item) {
    if (last < size) {
        data[last] = item;
        last++; // update last
    } else {
        std::cout << "Vector is full. \n";
    }
}

template<typename T>
void Vector<T>::print() const {
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void Vector<T>::operator=(const Vector &other) {

    if (this == &other) {
        return;
    }

    delete[] data;

    data = new T[other.size];
    size = other.size;
    last = other.last;

    if (other.last > 0) {
        for (int i = 0; i < other.last; i++) {
            data[i] = other.data[i];
        }
    }
}

template<typename T>
int Vector<T>::operator[](unsigned index) {
    // return value only if data is not null and index is less than size or zero
    if (index <= size && data) {
        return data[index];
    }
    return 0;
}

template<typename T>
Vector<T> Vector<T>::operator+(const Vector &other) {

    Vector new_vector(size + other.size);

    if (last > 0 && data) {
        for (int i = 0; i < last; i++) {
            new_vector.data[i] = data[i];
        }
        new_vector.last += last;
    }

    int totalLast = new_vector.last + other.last;
    if (other.last > 0) {

        // start from first array's last value (i) and iterate through second array (j)
        for (int i = new_vector.last, j = 0; i < totalLast; i++, j++) {
            new_vector.data[i] = other.data[j];
        }
        new_vector.last = totalLast;
    }

    return new_vector;
}

#endif // VECTOR_CPP