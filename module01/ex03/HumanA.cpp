#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string hname, Weapon &hw): name(hname), w(hw) {}

HumanA::~HumanA(){}

void    HumanA::attack()
{
    std::cout << name << ": attacks with their " << w.getType() << std::endl;
}