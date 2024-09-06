#pragma once

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool    isSigned;
        const int   gradeSign;
        const int   gradeExec;
    public:
        AForm();
        AForm(const std::string name, const int gradeSign, const int gradeExec);
        AForm(const Form& another);
        virtual ~AForm();
        AForm& operator=(const AForm& another);
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
        virtual void    execute(Bureaucrat const& executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);