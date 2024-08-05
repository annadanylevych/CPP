#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
    
    ScavTrap    Roberto("Roberto");
    ScavTrap    Ford("Ford");
    ScavTrap    random;
    ClapTrap    Audi("Audi");
    ClapTrap    lol;

    Roberto.attack("Ford");
    Ford.takeDamage(20);
    Ford.beRepaired(100);
    random.attack("lol");
    lol.takeDamage(20);
    lol.attack("Roberto");
    Roberto.takeDamage(0);
    Roberto.beRepaired(1);

    return (0);
}