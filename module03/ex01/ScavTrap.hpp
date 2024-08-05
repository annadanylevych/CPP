#pragma once
#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
    public: 
        ScavTrap();
        ScavTrap(std::string name);
        ~ScavTrap();
        ScavTrap& operator=(ScavTrap &another);
        ScavTrap(const ScavTrap& another);
        void    guardGate();
        void    attack(const std::string& target);
};