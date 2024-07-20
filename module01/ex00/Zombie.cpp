#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}

Zombie::~Zombie() 
{
    std::cout << name << ": I am destroyed :(" << std::endl;
}

void    Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setname(std::string str)
{
    this->name = str;
}

std::string Zombie::getname()
{
    return(this->name);
}

