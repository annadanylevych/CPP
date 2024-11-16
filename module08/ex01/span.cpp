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

void    Span::addNumber()
{
    if (this->vec[N - 1])
}