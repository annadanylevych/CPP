#include <cstdlib>
#include <iostream>
#include "FragTrap.hpp"

int main(void)
{
	FragTrap John("John");
	FragTrap Albert("Albert");

	std::cout << std::endl;

	John.attack("Albert");
	Albert.takeDamage(30);

	std::cout << std::endl;

	John.attack("Albert");
	Albert.takeDamage(30);

	std::cout << std::endl;

	John.attack("Albert");
	Albert.takeDamage(30);

	std::cout << std::endl;

	John.attack("Albert");
	Albert.takeDamage(30);

	std::cout << std::endl;

	Albert.beRepaired(100);

	std::cout << std::endl;

	Albert.highFivesGuys();

	std::cout << std::endl;

	Albert.takeDamage(100);

	return (0);
}