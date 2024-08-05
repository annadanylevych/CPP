#pragma once
#include <string>
#include "Weapon.hpp"

class HumanA
{
    private:

    std::string name;
    Weapon  &w;

    public:

    HumanA(std::string hname, Weapon &hw);
    ~HumanA();

    void    attack();

};