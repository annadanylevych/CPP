#pragma once

#include <iostream>
#include <string>

class Base
{
    private:
    public:
        Base();
        Base(const Base& another);
        Base& operator=(const Base& another);
        ~Base();
        Base* generate(void);
        void identify(Base* p);
        void identify(Base& p);
};