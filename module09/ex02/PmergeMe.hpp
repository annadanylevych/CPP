#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cmath>
#include <sstream>
#include <deque>
#include <list>
#include <utility>
#include <ctime>

bool isNum(std::string str);
std::list<int> sortList(std::list<int> unsorted);
std::deque<int>	mergeInsertSortDeque(std::deque<int> unsortedDeque);
void	insertionSortPairs(std::deque<std::pair<int, int> > & pairs);
void    sortPairsList(std::list<std::pair<int, int > >& pairs);
void binarySearchInsertionList(std::list<int>& cont, std::list<int>::iterator left, std::list<int>::iterator right, int target);
void binarySearchInsertion(std::deque<int> &cont, int left, int right, int target);

template <typename T>
void    printArr(T arr)
{
    for (typename T::iterator it = arr.begin(); it != arr.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename T>
T   convert(int argc, char **argv)
{
    T   res;

    for (int i = 1; i < argc; ++i)
    {
        if (!isNum(argv[i]))
            throw (std::invalid_argument("Error: Invalid character found"));
        res.insert(res.end(), atoi(argv[i]));
    }
    return (res);
}

template <typename T>
bool isSorted(T arr)
{
    int aux;
    typename T::iterator it = arr.begin();
    aux = *it;
    ++it;
    for (; it != arr.end(); ++it)
    {
        if (*it < aux)
            return (false);
        aux = *it;
    }
    return (true);
}