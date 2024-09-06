#include "AForm.hpp"

AForm::AForm() : name("Default"), isSigned(false), gradeSign(150), gradeExec(150) {}

AForm::AForm(const std::string name, const int gradeSign, const int gradeExec): name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
    if (gradeSign > 150 || gradeExec > 150) throw GradeTooLowException();
    else if (gradeSign < 1 || gradeExec < 1) throw GradeTooHighException();
}

AForm::AForm(const AForm& another) : name(another.name), isSigned(another.isSigned), gradeSign(another.gradeSign), gradeExec(another.gradeExec) {}

AForm&   AForm::operator=(const AForm& another)
{
    if(this != &another)
        isSigned = another.isSigned;
    return (*this);
}

AForm::~AForm() {}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

std::string AForm::getName() const
{
    return (this->name);
}

bool    AForm::getSign() const
{
    return (isSigned);
}

int AForm::getSignGrade() const
{
    return (this->gradeSign);
}

int AForm::getExecGrade() const
{
    return (this->gradeExec);
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << form.getName() << ", sign grade: " << form.getSignGrade() << ", execute grade: " << form.getExecGrade() << ", status: " << form.getSign();
    return (os);
}

void    AForm::beSigned(Bureaucrat& b)
{
    if (b.getGrade() > gradeSign)
        throw GradeTooLowException();
    isSigned = true;
}