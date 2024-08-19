#include "Dog.hpp"

Dog::Dog(): Animal()
{
    type = "Dog";
    this->brain = new Brain;
    std::cout << "Dog constructor called." << std::endl;
}

Dog::Dog(const Dog& another)
{
    this->type = another.type;
    this->brain = new Brain(*another.brain);
    std::cout << "Dog copy constructor called." << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destroyed." << std::endl;
}

Dog&    Dog::operator=(Dog& another)
{
    if (this != &another)
    {
        delete this->brain;
        this->brain = new Brain(*another.brain);
        this->type = another.type;
    }
    std::cout << "Dog copy assignment operator called." << std::endl;
    return(*this);   
}

void    Dog::makeSound() const
{
    std::cout << "WOOOF!!!!!" << std::endl;
}