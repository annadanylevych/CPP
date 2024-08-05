#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(std::string hname): name(hname) 
{
    w = NULL;
}


HumanB::~HumanB(){}

void    HumanB::setWeapon(Weapon &neww)
{
    w = &neww;
}

void    HumanB::attack()
{
    if (w)
        std::cout << name << ": attacks with their " << w->getType() << std::endl;
    else
        std::cout << name << ": doesn't attack." << std::endl;
}