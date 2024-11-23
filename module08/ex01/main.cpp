#include "span.hpp"

int main()
{
    Span    sp(10001);
    try
    {
        for (int i = 0; i < 10001; i++)
            sp.addNumber(i);
        sp.addNumber(1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << sp.longestSpan() << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    Span spi = Span(5);
    spi.addNumber(6);
    spi.addNumber(3);
    spi.addNumber(17);
    spi.addNumber(9);
    spi.addNumber(11);
    std::cout << spi.shortestSpan() << std::endl;
    std::cout << spi.longestSpan() << std::endl;
}
    