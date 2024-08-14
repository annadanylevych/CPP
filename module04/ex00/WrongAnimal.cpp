#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("unknown")
{
    std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): type(type)
{
    std::cout << "WrongAnimal " << type << " constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal " << type << "destroyed." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& another)
{
    this->type = another.type;
    std::cout << "WrongAnimal copy constructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal& another)
{
    if(this != &another)
        this->type = another.type;
    std::cout << "Animal copy assignment operator called." << std::endl;
    return(*this);
}

std::string WrongAnimal::getType() const
{
    return(this->type);
}

void    WrongAnimal::makeSound() const
{
    std::cout << "~Generic wrong animal sound~" << std::endl;
}