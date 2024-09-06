#pragma once
#include <string>
#include <fstream>
#include "AForm.hpp"
#include <ctime>
#include <cstdlib>


class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    public:
    RobotomyRequestForm();
    ~RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm& another);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& another);
    void execute(Bureaucrat const & executor) const;
    class FormNotSigned : public std::exception
    {
        public:
            const char* what() const throw();
    };
};