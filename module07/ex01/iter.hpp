#pragma once

#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

template <typename T> void iter(T* arr, size_t arr_len, void(*func)(T& arr))
{
    for (size_t i = 0; i < arr_len; i++)
        func(arr[i]);
}

template <typename T> void    print(T& arr)
{
    std::cout << arr << std::endl;
}

