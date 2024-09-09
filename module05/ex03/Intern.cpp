#include "Intern.hpp"

Intern::Intern() {}

Intern:: ~Intern() {}

Intern::Intern(const Intern& another) {}

Intern& Intern::operator=(const Intern& another)
{
    return (*this);
}

AForm*  Intern::makeForm(std::string form, std::string target)
{
    std::string forms[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    int i = 0;
    AForm *res;

    while (i < 4 && form != forms[i])
        i++;
    switch (i)
    {
    case 1:
        res = new PresidentialPardonForm(target);
        return(res);
    case 2:
        res = new RobotomyRequestForm(target);
        return(res);
    case 3:
        res = new ShrubberyCreationForm(target);
        return(res);
    default:
        std::cout << "Please enter a valid form" << std::endl;
        break;
    }
    delete res;
    return (NULL);
}