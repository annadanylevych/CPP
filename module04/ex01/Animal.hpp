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
    ~Animal();
    void    makeSound();
};