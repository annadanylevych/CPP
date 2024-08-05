#pragma once

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &another);
        FragTrap& operator=(FragTrap& another);
        ~FragTrap();
        void highFivesGuys();
};