#pragma once
#include <iostream>


template <typename T> class Array
{
    private:
        T*  arr;
        unsigned int  arr_size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& another);
        Array& operator=(const Array& another);
        T& operator[](int i);
        unsigned int size();
        ~Array();
};