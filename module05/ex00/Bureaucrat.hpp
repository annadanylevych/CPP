#pragma once

#include <string>
#include <iostream>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& another);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& another);
        std::string getName();
        int getGrade();
        void increment();
        void decrement();
};