#include "Weapon.hpp"
#include <string>


Weapon::Weapon(){};

Weapon::Weapon(std::string type)
{
    setType(type);
}

Weapon::~Weapon(){};


void Weapon::setType(std::string newType)
{
    this->type = newType;
}

const std::string&  Weapon::getType()
{
    std::string& typeRef = this->type;
    return(typeRef);
}