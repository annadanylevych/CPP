#include "Data.hpp"

Data::Data(): str("default"), i(0) {}

Data::Data(std::string str, int i): str(str), i(i) {}

Data::Data(const Data& another): str(another.str), i(another.i) {}

Data::~Data(){}

Data& Data::operator=(const Data& another)
{
    if (this != &another)
    {
        this->i = another.i;
        this->str = another.str;
    }
    return (*this);
}

