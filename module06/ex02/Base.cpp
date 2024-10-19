#include "Base.hpp"

Base::~Base() {}

Base* generate(void)
{
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
            return NULL;
    }
}

void    identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void    identify(Base &p)
{
    try
    {
        A a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch(const std::exception &e) {};
    try
    {
        B b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
    catch(const std::exception &e) {};
    try
    {
        C c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    }
    catch(const std::exception &e) {}; 
}