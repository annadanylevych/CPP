#pragma once
#include <string>

class ClapTrap
{
protected:
    std::string name;
    unsigned int HitPoints;
    unsigned int EnergyPoints;
    unsigned int AttackDamage;
public:
    ClapTrap(std::string name);
    ClapTrap();
    virtual ~ClapTrap();
    ClapTrap(const ClapTrap& another);
    ClapTrap& operator=(ClapTrap& another);
    void virtual attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};