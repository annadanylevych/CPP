#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer& another) 
{
    (void)another;
}

Serializer& Serializer::operator=(const Serializer& another)
{
    (void)another;
    return(*this);
}

uintptr_t   Serializer::serialize(Data* ptr)
{
    return(reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return(reinterpret_cast<Data*>(raw));
}
