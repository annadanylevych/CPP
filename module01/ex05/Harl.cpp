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

    for(i = 0; i < 4; i++)
    {
        if(level == levels[i])
        {
            (this->*options[i])();
            return ;
        }
    }
    if (i == 4)
    {
        std::cerr << "The parameter is invalid." << std::endl;
        exit(1);
    }
}