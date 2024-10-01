#pragma once

#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <iomanip>

const float FLOAT_MIN = -3.40282347e+38F;

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& another);
        ScalarConverter& operator=(const ScalarConverter& another);
    public:
        static void convert(const std::string& s);
};