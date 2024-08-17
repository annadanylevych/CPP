#include <iostream>
#include <string>
#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void    Harl::debug()
{
    std::cout << "Debugging" << std::endl;
}

void    Harl::error()
{
    std::cout << "Erroring" << std::endl;
}

void    Harl::info()
{
    std::cout << "Infoing" << std::endl;
}

void    Harl::warning()
{
    std::cout << "Warning" << std::endl;
}


void    Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    option  options[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int i = 0;

    while (i < 4 && levels[i] != level)
        i++;
    switch (i)
    {
        case 0:
            (this->*options[0])();
        case 1:
            (this->*options[1])();
        case 2:
            (this->*options[2])();
        case 3:
            (this->*options[3])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}