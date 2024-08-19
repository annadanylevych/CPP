#include "Animal.hpp"

Animal::Animal() : type("unknown")
{
    std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(std::string type): type(type)
{
    std::cout << "Animal " << type << " constructor called." << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal " << type << "destroyed." << std::endl;
}

Animal::Animal(const Animal& another)
{
    this->type = another.type;
    std::cout << "Animal copy constructor called." << std::endl;
}

Animal& Animal::operator=(Animal& another)
{
    if(this != &another)
        this->type = another.type;
    std::cout << "Animal copy assignment operator called." << std::endl;
    return(*this);
}

std::string Animal::getType() const
{
    return(this->type);
}

void    Animal::makeSound() const
{
    std::cout << "~Generic animal sound~" << std::endl;
}