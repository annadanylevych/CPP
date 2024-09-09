#pragma once
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

class Intern
{
    public:
        Intern();
        ~Intern();
        Intern(const Intern& another);
        Intern& operator=(const Intern& another);
        AForm*    makeForm(std::string form, std::string target);
};