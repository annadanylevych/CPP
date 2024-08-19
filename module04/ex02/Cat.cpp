#include "Cat.hpp"

Cat::Cat(): Animal()
{
    type = "Cat";
    this->brain = new Brain;
    std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat& another)
{
    this->type = another.type;
    this->brain = another.brain;
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destroyed." << std::endl;
}

Cat&    Cat::operator=(Cat& another)
{
    if (this != &another)
    {
        this->brain = another.brain;
        this->type = another.type;
    }
    std::cout << "Cat copy assignment operator called." << std::endl;
    return(*this);   
}

void    Cat::makeSound() const
{
    std::cout << "MEOW!!!!!" << std::endl;
}