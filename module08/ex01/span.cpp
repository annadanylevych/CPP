#include "span.hpp"


Span::Span() {}

Span::Span(unsigned int N): N(N) {}

Span&   Span::operator=(const Span& another)
{
    if (this != &another)
    {
        this->N = another.N;
        for (int i = 0; i < N; i++)
            this->vec[i] = another.vec[i];
    }
    return(*this);
}

Span::Span(const Span& another)
{
    this->N = another.N;
    for (int i = 0; i < N; i++)
        this->vec[i] = another.vec[i];
}

Span::~Span() {}

void    Span::addNumber(int i)
{
    if (vec.size() >= N)
        throw (std::out_of_range("Not possible to add more numbers"));
    vec.push_back(i);
}

int     Span::shortestSpan()
{
    if (vec.size() <= 2)
        throw(std::length_error("Not possible to find the span between 2 numbers"));
    std::vector<int>::iterator it = vec.begin(); 
    std::vector<int>::iterator itit = vec.begin() + 1; 
    int res;
    int defres = INT_MAX;
    while (it != vec.end())
    {
        itit = it + 1;
        while (itit != vec.end())
        {
            if (it > itit)
                res = *it - *itit;
            else
                res = *itit - *it;
            if (defres > res)
                defres = res;
            itit++;
        }
        it++;
    }
    return (defres);
}

int     Span::longestSpan()
{
    if (vec.size() <= 2)
        throw(std::length_error("Not possible to find the span between 2 numbers"));
    std::vector<int>::iterator max = std::max_element(vec.begin(), vec.end());
    std::vector<int>::iterator min = std::min_element(vec.begin(), vec.end());
    return (*max - *min);
}