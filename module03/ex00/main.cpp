#include "ClapTrap.hpp"
#include <iostream>
#include <string>

int main()
{
    ClapTrap George("George");
    ClapTrap Kola("Kola");

    for(int i = 0; i < 5; i++)
        George.attack("Kola");
    for(int i = 0; i < 5; i++)
        Kola.takeDamage(4);
    George.beRepaired(10);
    Kola.beRepaired(10);
    return(0);
}