#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        ShrubberyCreationForm l;
        Bureaucrat k("k", 14);
        RobotomyRequestForm r;
        PresidentialPardonForm p;

        k.signForm(l);
        k.executeForm(l);
        k.signForm(r);
        k.executeForm(r);
        k.signForm(p);
        k.executeForm(p);
    }
    catch(const std::exception& e)
    {
        std::cerr << "EXCEPTION: " << e.what() << std::endl;
    }  
    return (0);
}