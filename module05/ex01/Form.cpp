#include "Form.hpp"

Form::Form() : name("Default"), isSigned(false), gradeSign(150), gradeExec(150) {}

Form::Form(const std::string name, const int gradeSign, const int gradeExec): name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
    if (gradeSign > 150 || gradeExec > 150) throw GradeTooLowException();
    else if (gradeSign < 1 || gradeExec < 1) throw GradeTooHighException();
}

Form::Form(const Form& another) : name(another.name), isSigned(another.isSigned), gradeSign(another.gradeSign), gradeExec(another.gradeExec) {}

Form&   Form::operator=(const Form& another)
{
    if(this != &another)
        isSigned = another.isSigned;
    return (*this);
}

Form::~Form() {}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

std::string Form::getName() const
{
    return (this->name);
}

bool    Form::getSign() const
{
    return (isSigned);
}

int Form::getSignGrade() const
{
    return (this->gradeSign);
}

int Form::getExecGrade() const
{
    return (this->gradeExec);
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << form.getName() << ", sign grade: " << form.getSignGrade() << ", execute grade: " << form.getExecGrade() << ", status: " << form.getSign();
    return (os);
}

void    Form::beSigned(Bureaucrat& b)
{
    if (b.getGrade() > gradeSign)
        throw GradeTooLowException();
    isSigned = true;
}