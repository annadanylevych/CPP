#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(1) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
    if (grade > 150) throw Bureaucrat::GradeTooHighException();
    else if (grade < 1) throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& another) : name(another.name), grade(another.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& another)
{
    if (this != &another)
        this->grade = another.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return(this->grade);
}

void    Bureaucrat::decrement()
{
    if (grade >= 150) throw GradeTooHighException();
    ++grade;
}

void    Bureaucrat::increment()
{
    if (grade <= 1) throw GradeTooHighException();
    --grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& a)
{
    os << a.getName() << ", bureaucrat grade " << a.getGrade();
    return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
    return ("Grade too low");
}