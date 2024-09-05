#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;
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
        void increment();
        void decrement();
        void signForm(Form& f);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);


