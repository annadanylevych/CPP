#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
std::cout << "42 TESTS" << std::endl;
IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
ICharacter* me = new Character("me");
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);
delete bob;
delete me;
delete src;

std::cout << "MY TESTS" << std::endl;
IMateriaSource* mat = new MateriaSource();
mat->learnMateria(new Ice());
mat->learnMateria(new Cure());
mat->learnMateria(new Ice());
mat->learnMateria(new Cure());
Character* rosalia = new Character("rosalia");
ICharacter* ben = new Character("ben");
AMateria* temp;
temp = src->createMateria("ice");
rosalia->equip(temp);
temp = src->createMateria("cure");
rosalia->equip(temp);
rosalia->equip(temp);
rosalia->unequip(2);
rosalia->use(0, *ben);
rosalia->use(1, *ben);
ICharacter* lili = new Character(*rosalia);
delete rosalia;
lili->use(1, *ben);
delete ben;
delete mat;
return 0;
}