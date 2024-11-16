#pragma once

#include <iostream>
#include <vector>

class Span
{
    private:
        unsigned int N;
        std::vector<int> vec;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& another);
        Span& operator=(const Span& another);
        ~Span();
        void addNumber();
};