#pragma once

#include <string>
#include <iostream>
#include <limits>

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& another);
        ScalarConverter& operator=(const ScalarConverter& another);
    public:
        static void convert(std::string& s);
};