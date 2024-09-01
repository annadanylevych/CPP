#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat  Sam("Sam", 5);
        Bureaucrat Mouse("Mouse", 180);
        Bureaucrat Linda;

        std::cout << Sam << std::endl;
        std::cout << Mouse << std::endl;
        std::cout << Linda << std::endl;

        Sam.decrement();
        Linda.increment();

        std::cout << Sam << std::endl;
        std::cout << Mouse << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}