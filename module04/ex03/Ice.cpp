#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice& Ice::operator=(Ice& another)
{
    if (this != &another)
        AMateria::operator=(another);
    return (*this);
}

Ice::Ice(const Ice& another) : AMateria(another) {}

AMateria* Ice::clone() const 
{
    return (new Ice(*this));
}

void    Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.name << "*" << std::endl;
}