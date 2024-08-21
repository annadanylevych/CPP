#pragma once

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        ~Cure();
        Cure(const Cure& another);
        Cure& operator=(Cure& another);
        AMateria* clone() const;
        void use(ICharacter& target);
};