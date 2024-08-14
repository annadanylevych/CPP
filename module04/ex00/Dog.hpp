#pragma once

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        ~Dog();
        Dog(const Dog& another);
        Dog& operator=(Dog& another);
        void makeSound() const;
};