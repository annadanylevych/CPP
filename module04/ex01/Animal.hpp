#pragma once

#include <string>
#include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(std::string type);
    Animal(const Animal& another);
    Animal& operator=(Animal& another);
    std::string getType() const;
    virtual ~Animal();
    virtual void    makeSound()const;
};