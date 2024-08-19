#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
    type = "WrongCat";
    std::cout << "WrongCat constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& another)
{
    this->type = another.type;
    std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destroyed." << std::endl;
}

WrongCat&    WrongCat::operator=(WrongCat& another)
{
    if (this != &another)
        this->type = another.type;
    std::cout << "WrongCat copy assignment operator called." << std::endl;
    return(*this);   
}

void    WrongCat::makeSound() const
{
    std::cout << "(wrong)MEOW!!!!!" << std::endl;
}