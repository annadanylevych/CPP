#pragma once
#include "Weapon.hpp"
#include <string>

class   HumanB
{
    private:

    Weapon *w;
    std::string name;

    public:

    HumanB(std::string hname);
    ~HumanB();
    
    void    setWeapon(Weapon &neww);
    void    attack();

};