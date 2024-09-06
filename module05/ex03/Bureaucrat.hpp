#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;
class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:

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

        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& another);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& another);
        std::string getName() const;
        int getGrade() const;
        void    increment();
        void    decrement();
        void    signForm(AForm& f);
        void    executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);


