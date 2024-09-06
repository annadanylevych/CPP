#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 72, 45), target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 72, 45), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& another) : AForm(another), target(another.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& another)
{
    if (this != &another)
        AForm::operator=(another);
    return (*this);
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (this->getSign() == false) throw FormNotSigned();
    if (executor.getGrade() >= this->getExecGrade()) throw AForm::GradeTooLowException();
    std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

const char* PresidentialPardonForm::FormNotSigned::what() const throw()
{
    return("Form not signed");
}