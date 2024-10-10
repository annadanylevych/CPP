#pragma once

#include <iostream>
#include <string.h>

class Data
{
    private:
        std::string str;
        int i;
    public:
        Data();
        Data(std::string str, int i);
        Data(const Data&  another);
        ~Data();
        Data& operator=(const Data& another);
};