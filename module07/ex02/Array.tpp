#include "Array.hpp"

template <typename T> Array<T>::Array(): arr(NULL), arr_size(0){}

template <typename T> Array<T>::Array(unsigned int n)
{
    size = n;
    arr = new T[n];
}

template <typename T> Array<T>::Array(const Array& another)
{
    this->arr_size = another.arr_size;
    this->arr = new T[this->arr_size];
    for (unsigned int i = 0; i < arr_size; i++)
        this->arr[i] = another.arr[i];
}

template <typename T> Array<T>& Array<T>::operator=(const Array& another)
{
    if (*this != another)
}



