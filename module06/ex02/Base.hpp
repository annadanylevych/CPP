#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "class.hpp"

class Base
{
    public:
        ~Base();
};

Base* generate(void);

void identify(Base* p);

void identify(Base& p);

