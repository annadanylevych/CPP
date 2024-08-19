#pragma once

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat();
        ~Cat();
        Cat(const Cat& another);
        Cat& operator=(Cat& another);
        void makeSound()  const;
    private:
        Brain   *brain;
};