#include "my_reverse_iterator.h"

template<typename T>
My_reverse_iterator<T>::My_reverse_iterator(T* p) : ptr(p) {}

template<typename T>
My_reverse_iterator<T>::~My_reverse_iterator() = default;

template<typename T>
T &My_reverse_iterator<T>::operator*() const {
    return *ptr;
}

template<typename T>
T *My_reverse_iterator<T>::operator->() const {
    return ptr;
}

template<typename T>
My_reverse_iterator<T> My_reverse_iterator<T>::operator++(int) {
    My_reverse_iterator temp = *this;
    --ptr;
    return temp;
}

template<typename T>
My_reverse_iterator<T> &My_reverse_iterator<T>::operator++() {
    --ptr;
    return *this;
}

template<typename T>
My_reverse_iterator<T> &My_reverse_iterator<T>::operator--() {
    ++ptr;
    return *this;
}

template<typename T>
My_reverse_iterator<T> My_reverse_iterator<T>::operator--(int) {
    My_reverse_iterator temp = *this;
    ++ptr;
    return temp;
}

template<typename T>
My_reverse_iterator<T> My_reverse_iterator<T>::operator+(int n) const
{
    return My_reverse_iterator(ptr - n);
}

template<typename T>
My_reverse_iterator<T> My_reverse_iterator<T>::operator-(int n) const
{
    return My_reverse_iterator(ptr + n);
}

template<typename T>
My_reverse_iterator<T>& My_reverse_iterator<T>::operator+=(int n) {
    ptr -= n;
    return *this;
}

template<typename T>
My_reverse_iterator<T>& My_reverse_iterator<T>::operator-=(int n) {
    ptr += n;
    return *this;
}

template<typename T>
T &My_reverse_iterator<T>::operator[](int n) const
{
    return ptr[-n];
}

template<typename T>
bool My_reverse_iterator<T>::operator==(const My_reverse_iterator &other) const
{
    return ptr == other.ptr;
}

template<typename T>
bool My_reverse_iterator<T>::operator!=(const My_reverse_iterator &other) const {
    return ptr != other.ptr;
}
