#include "Character.hpp"

Character::Character(std::string name)
{
    this->name = name;
    for (int i = 0; i < 4; i++)
    {
        this->dropped[i] = NULL;
        this->inv[i] = NULL;
    }
} 

Character::Character()
{
    this->name = "Default";
    for (int i = 0; i < 4; i++)
    {
        this->dropped[i] = NULL;
        this->inv[i] = NULL;
    }
}

Character::~Character() 
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inv[i])
            delete this->inv[i];
        if (this->dropped[i])
            delete this->dropped[i];
    }
}

Character::Character(const Character& another)
{
    this->name = another.getName();
    for (int i = 0; i < 4; i++)
    {
        if (this->inv[i])
            delete this->inv[i];
        if (this->dropped[i])
            delete this->dropped[i];
        if (another.inv[i])
            this->inv[i] = another.inv[i]->clone();
        else 
            this->inv[i] = NULL;
    }
}

Character&  Character::operator=(Character& another)
{
    if (this != &another)
    {
        this->name = another.getName();
        for (int i = 0; i < 4; i++)
        {
            if (this->inv[i])
                delete this->inv[i];
            if (this->dropped[i])
                delete this->dropped[i];
            if (another.inv[i])
                this->inv[i] = another.inv[i]->clone();
            else 
                this->inv[i] = NULL;
        }
    }
    return (*this);
}

std::string const& Character:: getName() const
{
    return(this->name);
}

void    Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (!inv[i]) 
        {
            inv[i] = m;
            return ;
        }
    }
    std::cout << "Inventory is full. Cannot equip more Materia." << std::endl;
}
void    Character::unequip(int idx)
{
    if (inv[idx])
    {
        for (int i = 0; i < 4; ++i) 
        {
            if (!dropped[i]) 
            {
                dropped[i] = inv[idx]; 
                break;
            }
        }
        inv[idx] = NULL;
    }   
}

void    Character::use(int idx, ICharacter& target) 
{
    if (inv[idx])
        inv[idx]->use(target);
    else
        std::cout << "No Materia to use in slot " << idx << "." << std::endl;
}

