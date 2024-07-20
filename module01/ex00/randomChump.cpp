#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie  newz = Zombie();
    newz.setname(name);
    newz.announce();
}