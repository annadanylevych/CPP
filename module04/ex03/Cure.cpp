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
    return (new Cure());
}

void    Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds*" << std::endl;
}