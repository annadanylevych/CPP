#pragma once

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter
{
    protected:
        std::string name;
        AMateria*   inv[4];
    public:
        Character();
        Character(std::string name);
        ~Character();
        Character(const Character& another);
        Character& operator=(Character& another);
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};