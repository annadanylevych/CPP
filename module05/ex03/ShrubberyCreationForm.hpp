#pragma once
#include <string>
#include <fstream>
#include "AForm.hpp"


class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
    ShrubberyCreationForm();
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& another);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& another);
    void execute(Bureaucrat const & executor) const;
    class FormNotSigned : public std::exception
    {
        public:
            const char* what() const throw();
    };
};