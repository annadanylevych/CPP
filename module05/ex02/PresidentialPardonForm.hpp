#pragma once
#include <string>
#include <fstream>
#include "AForm.hpp"
#include <ctime>
#include <cstdlib>


class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
    PresidentialPardonForm();
    ~PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& another);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& another);
    void execute(Bureaucrat const & executor) const;
    class FormNotSigned : public std::exception
    {
        public:
            const char* what() const throw();
    };
};