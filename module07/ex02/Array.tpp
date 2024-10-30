#include "Array.hpp"

template <typename T> Array<T>::Array(): arr(NULL), arr_size(0){}

template <typename T> Array<T>::Array(unsigned int n)
{
    this->arr_size = n;
    arr = new T[n];
}

template <typename T> Array<T>::Array(const Array& another)
{
    this->arr_size = another.arr_size;
    this->arr = new T[this->arr_size];
    for (unsigned int i = 0; i < static_cast<unsigned int>(arr_size); i++)
        this->arr[i] = another.arr[i];
}

template <typename T> Array<T>& Array<T>::operator=(const Array& another)
{
    if (this != &another)
    {
        delete[] this->arr;
        this->arr_size = another.arr_size;
        if (this->arr_size == 0)
            this->arr = NULL;
        else
            this->arr = new T[this->arr_size];
        for (unsigned int i = 0; i < arr_size; i++)
            this->arr[i] = another.arr[i];
    }
    return (*this);
}

template <typename T> Array<T>::~Array()
{
    if (arr)
        delete[] this->arr;
}

template <typename T> T& Array<T>::operator[](int i)
{
    if (i < 0 || i >= static_cast<int>(this->arr_size))
        throw (std::out_of_range("Index not valid"));
    return (this->arr[i]);
}

template <typename T> unsigned int Array<T>::size()
{
    return (this->arr_size);
}



