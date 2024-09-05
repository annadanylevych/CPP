#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool    isSigned;
        const int   gradeSign;
        const int   gradeExec;
    public:
        Form();
        Form(const std::string name, const int gradeSign, const int gradeExec);
        Form(const Form& another);
        ~Form();
        Form& operator=(const Form& another);
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        
        std::string getName() const;
        bool getSign() const;
        int getSignGrade() const;
        int getExecGrade() const;
        void    beSigned(Bureaucrat& b);

};

std::ostream& operator<<(std::ostream& os, const Form& form);