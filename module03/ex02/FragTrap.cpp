#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default")
{
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
    std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
    std::cout << "FragTrap " << name << " constructor called." << std::endl;
}


FragTrap::FragTrap(const FragTrap &another): ClapTrap(another)
{
    std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap&   FragTrap::operator=(FragTrap& another)
{
    if(this != &another)
        ClapTrap::operator=(another);
    std::cout << "FragTrap assignment operator called." << std::endl;
    return (*this);    
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called." << std::endl;
}

void    FragTrap::highFivesGuys()
{
    if (HitPoints < 1)
        std::cout << "FragTrap " << this->name << " is dead." << std::endl;
    else
        std::cout << "FragTrap " << this->name << " says: Lets HIGH FIVE HEHEHE" << std::endl;
}

