#include <iostream>

template <typename T> class Array
{
    private:
        T*  arr;
        unigned int  arr_size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& another);
        Array& operator=(const Array& another);
        ~Array();
};