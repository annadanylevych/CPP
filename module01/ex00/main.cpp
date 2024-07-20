#include <iostream>
#include "Zombie.hpp"

int main()
{
    Zombie  Jonny;
    Zombie  *Max = newZombie("Max");
    randomChump("Laia");
    Jonny.setname("Jonny");
    Jonny.announce();
    Max->announce();
    delete Max;
    return(0);
}