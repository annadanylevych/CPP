#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try
    {
        Intern someRandomIntern;
        Bureaucrat  buro("buro", 4);
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        buro.signForm(*rrf);
        buro.executeForm(*rrf);
    }
    catch(const std::exception& e)
    {
        std::cerr << "EXCEPTION: " << e.what() << std::endl;
    }  
    return (0);
}