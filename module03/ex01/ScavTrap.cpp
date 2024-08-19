#include "ScavTrap.hpp"
#include <string>

ScavTrap::ScavTrap() : ClapTrap("Default")
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "ScavTrap" << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) 
{
    std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap&   ScavTrap::operator=(ScavTrap& another)
{
    if (this != &another)
        ClapTrap::operator=(another);
    std::cout << "ScavTrap assignment operator called." << std::endl;
    return (*this);  
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor has been called" << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->HitPoints > 0 && this->EnergyPoints > 0)
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->AttackDamage << " points of damage!" << std::endl;
        this->EnergyPoints--;
    }
    else
        std::cout << "ScavTrap " << this->name << " cannot attack." << std::endl;
}

void ScavTrap::guardGate()
{
    if (HitPoints < 1)
        std::cout << "ScavTrap " << this->name << " is dead." << std::endl;
    else
        std::cout << "ScavTrap " << name << " is now guarding the gate." << std::endl;
}
