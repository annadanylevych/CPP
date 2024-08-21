#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure& Cure::operator=(Cure& another)
{
    if (this != &another)
        AMateria::operator=(another);
    return (*this);
}

Cure::Cure(const Cure& another) : AMateria(another) {}

AMateria* Cure::clone() const 
{
    return (new Cure(*this));
}

void    Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.name << "'s wounds*" << std::endl;
}