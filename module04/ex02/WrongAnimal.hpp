#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(std::string type);
    WrongAnimal(const WrongAnimal& another);
    WrongAnimal& operator=(WrongAnimal& another);
    std::string getType() const;
    virtual ~WrongAnimal();
    void    makeSound()const;
};