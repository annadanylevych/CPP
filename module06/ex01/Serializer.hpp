#pragma once

#include <string>
#include <iostream>
#include <stdint.h>

typedef struct Data
{
        std::string str;
        int i;
}   Data;

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