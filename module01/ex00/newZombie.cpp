#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie  *newz = new Zombie();
    newz->setname(name);
    return(newz);
}