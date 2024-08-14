#pragma once

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        ~Cat();
        Cat(const Cat& another);
        Cat& operator=(Cat& another);
        void makeSound()  const;
};