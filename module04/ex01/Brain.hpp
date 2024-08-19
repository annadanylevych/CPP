#pragma once

#include <string>
#include <iostream>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain& another);
        Brain& operator=(Brain& another);
        ~Brain();
};