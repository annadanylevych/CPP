#pragma once

#include <string>
#include <iostream>
#include "AMateria.hpp"


class Ice : public AMateria
{
    public:
        Ice();
        ~Ice();
        Ice(const Ice& another);
        Ice& operator=(Ice& another);
        AMateria* clone() const;
        void use(ICharacter& target);
};