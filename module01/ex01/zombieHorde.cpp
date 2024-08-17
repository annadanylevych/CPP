#include "Zombie.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

Zombie* zombieHorde(int N, std::string name)
{
    if(N < 1)
    {
        std::cout << "Error: Please choose the positive number" << std::endl;
        exit (1);
    }
    Zombie *horde = new Zombie[N];
    for(int i = 0; i < N; i++)
        horde[i].setname(name);
    return(horde);
}