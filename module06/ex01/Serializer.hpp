#pragma once

#include <string>
#include <iostream>
#include "Data.hpp"

class Serializer
{
    public:
        static uintptr_t    serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    private:
        Serializer();
        Serializer(const Serializer& another);
        ~Serializer();
        Serializer& operator=(const Serializer& another);   
};