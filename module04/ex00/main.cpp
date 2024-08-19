#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

int main()
{
    Animal animal;
    Animal *giraffe = &animal;
    Animal *dog = new Dog;
    Animal *cat = new Cat;
    WrongAnimal *catt = new WrongCat;
    WrongAnimal heh;

    std::cout << animal.getType() << std::endl;
    std::cout << giraffe->getType() << std::endl;
    std::cout << cat->getType() << std::endl;
    std::cout << dog->getType() << std::endl;
    std::cout << catt->getType() << std::endl;
    std::cout << heh.getType() << std::endl;

    animal.makeSound();
    giraffe->makeSound();
    cat->makeSound();
    dog->makeSound();
    catt->makeSound();
    heh.makeSound();

    delete cat;
    delete dog;
    delete catt;

    return(0);
}