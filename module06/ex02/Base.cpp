#include "Base.hpp"

Base::~Base() {}

Base* generate(void)
{
    srand(static_cast<unsigned int>(time(0)));
    int num = rand() % 3;
    switch(num)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return nullptr;
    }
}

void    identify(Base *p)
{
    if (dynamic_cast<A>(&p))
}