#pragma once

#include <string>
#include <iostream>

class ScalarConverter
{
    private:
        char    type;
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& another);
        ScalarConverter& operator=(const ScalarConverter& another);
    public:
        static void convert(std::string& s);
};