#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
    std::cout << name << " constructor called." << std::endl;
}

ClapTrap::ClapTrap()
{
    this->name = "Default";
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
    std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& another)
{
    this->name = another.name;
    this->HitPoints = another.HitPoints;
    this->EnergyPoints = another.EnergyPoints;
    this->AttackDamage = another.AttackDamage;
    std::cout << "Copy constructor called." << std::endl;
}

ClapTrap&   ClapTrap::operator=(ClapTrap& another)
{
    if(this != &another)
    {
        this->name = another.name;
        this->HitPoints = another.HitPoints;
        this->EnergyPoints = another.EnergyPoints;
        this->AttackDamage = another.AttackDamage;  
    }
    std::cout << "Copy assignment operator called" << std::endl; 
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called." << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->HitPoints > 0 && this->EnergyPoints > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->AttackDamage << " points of damage!" << std::endl;
        this->EnergyPoints--;
    }
    else
        std::cout << "ClapTrap " << this->name << " cannot attack." << std::endl;

}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= this->HitPoints)
    {
        std::cout << "ClapTrap " << this->name << " is killed." << std::endl;
        this->HitPoints = 0;
    }
    else
    {
        std::cout << "ClapTrap " << this->name << " lost " << amount << " hit points." << std::endl;
        this->HitPoints -= amount;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (EnergyPoints < 1)
        std::cout << "ClapTrap " << this->name << " cannot be repaired." << std::endl;
    else
    {
        std::cout << "ClapTrap " << this->name << " gained " << amount << " hit points." << std::endl;
        this->HitPoints +=amount;
        this->EnergyPoints--;
    }
}


