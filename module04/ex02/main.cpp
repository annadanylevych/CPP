#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

int main()
{
    Animal *animals[10];

    for (int i = 0; i < 5; i++)
        animals[i] = new Dog;
    for (int i = 5; i < 10; i++)
        animals[i] = new Cat;

    std::cout << " " << std::endl;

    Dog *basic = new Dog;
    Dog tmp = *basic;
    delete basic;
    std::cout << " " << std::endl;

    for(int i = 0; i < 10; i++)
        delete animals[i];
    
    std::cout << " " << std::endl;
    return(0);
}