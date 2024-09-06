#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& another) : AForm(another), target(another.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& another)
{
    if (this != &another)
        AForm::operator=(another);
    return (*this);
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (this->getSign() == false) throw FormNotSigned();
    if (executor.getGrade() >= this->getExecGrade()) throw AForm::GradeTooLowException();
    std::ofstream   file;
    file.open((target + "_shrubbery").c_str());
    if (file.is_open())
    {
        file << "   oxoxoo    ooxoo   \n"
                "  ooxoxo oo  oxoxooo \n"
                " oooo xxoxoo ooo ooox\n"
                " oxo o oxoxo  xoxxoxo\n"
                "  oxo xooxoooo o ooo \n"
                "   ooo\\oo\\  /o/o   \n"
                "       \\  \\/ /     \n"
                "        |   /        \n"
                "        |  |         \n"
                "        | D|         \n"
                "        |  |         \n"
                "        |  |         \n"
                " ______/____\\____   \n";
      }
    else
        std::cout << "Unable to open the file." << std::endl;
}

const char* ShrubberyCreationForm::FormNotSigned::what() const throw()
{
    return("Form not signed");
}