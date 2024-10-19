#include "Base.hpp"

int main()
{
    A hey;
    Base *bas;

    srand(static_cast<unsigned int>(time(0)));
    bas = generate();
    identify(bas);
    identify(*bas);

    Base *k = new A;
    identify(&hey);
    identify(k);

    delete bas;
    delete k;
}