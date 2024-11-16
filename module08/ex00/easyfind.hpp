#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <exception>
#include <algorithm>

template <typename T> void  easyfind(T arr, int i)
{
    if (std::find(arr.begin(), arr.end(), i) == arr.end())
        throw (std::out_of_range("Index not valid"));
    std::cout << "Found!" << std::endl;
}
