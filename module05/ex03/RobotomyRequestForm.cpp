#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& another) : AForm(another), target(another.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& another)
{
    if (this != &another)
        AForm::operator=(another);
    return (*this);
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (this->getSign() == false) throw FormNotSigned();
    if (executor.getGrade() >= this->getExecGrade()) throw AForm::GradeTooLowException();
    std::cout << "drllldrlllldrllllllddrrrrllllll..........." << std::endl;
    std::srand(std::time(0));
    if (std::rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "The robotomy failed." << std::endl;
}

const char* RobotomyRequestForm::FormNotSigned::what() const throw()
{
    return("Form not signed");
}