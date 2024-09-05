#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat  Sam("Sam", 5);
        Bureaucrat Mouse("Mouse", 140);
        Bureaucrat Linda;

        std::cout << Sam << std::endl;
        std::cout << Mouse << std::endl;
        std::cout << Linda << std::endl;

        Sam.decrement();
        Linda.increment();

        std::cout << Sam << std::endl;
        std::cout << Mouse << std::endl;

        Form    f;
        Form    formi("Form", 6, 1);

        Sam.signForm(formi);
        Linda.signForm(f);
        Linda.signForm(formi);

        std::cout << f << std::endl;
        std::cout << formi << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}