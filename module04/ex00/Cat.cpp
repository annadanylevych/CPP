#include "Cat.hpp"

Cat::Cat(): Animal()
{
    type = "Cat";
    std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat& another)
{
    this->type = another.type;
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destroyed." << std::endl;
}

Cat&    Cat::operator=(Cat& another)
{
    if (this != &another)
        this->type = another.type;
    std::cout << "Cat copy assignment operator called." << std::endl;
    return(*this);   
}

void    Cat::makeSound() const
{
    std::cout << "MEOW!!!!!" << std::endl;
}