#include "Character.hpp"

Character::Character(std::string name)
{
    this->name = name;
    for (int i = 0; i < 4; i++)
        this->inv[i] = NULL;
} 

Character::Character()
{
    this->name = "Default";
    for (int i = 0; i < 4; i++)
        this->inv[i] = NULL;
}

Character::~Character() 
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inv[i])
            delete this->inv[i];
    }
}

Character::Character(const Character& another)
{
    this->name = another.getName();
    for (int i = 0; i < 4; i++)
        this->inv[i] = another.inv[i];
}

Character&  Character::operator=(Character& another)
{
    if (this != &another)
    {
        this->name = another.getName();
        for (int i = 0; i < 4; i++)
            this->inv[i] = another.inv[i];
    }
    return (*this);
}

std::string const& Character:: getName() const
{
    return(this->name);
}

void    Character::equip(AMateria *m)
{
    int i = 0;
    do 
    {
        if (!inv[i])
        {
            inv[i] = m;
            break;
        }
        i++;
    } while (i < 4);
}

void    Character::unequip(int idx)
{
    if(inv[idx])
        
}

