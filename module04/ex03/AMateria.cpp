#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria& another) : type(another.type) {}

AMateria& AMateria::operator=(AMateria& another)
{
    if (this != &another)
        this->type = another.type;
    return(*this);
}

std::string const&  AMateria::getType() const
{
    return(this->type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* awkward dance for " << target.getName() << " *" << std::endl;
}