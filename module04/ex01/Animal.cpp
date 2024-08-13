#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(std::string type): type(type)
{
    std::cout << "Animal " << type << " constructor called." << std::endl;
}

Animal::Animal(const Animal& another)
{
    this->type = another.type;
    std::cout << "Animal copy constructor called." << std::endl;
}

Animal& Animal::operator=(Animal& another)
{
    if(this != &another)
        this->type = another.type
}