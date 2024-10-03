#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& another) 
{
    (void)another;
}

ScalarConverter&    ScalarConverter::operator=(const ScalarConverter& another)
{
    (void)another;
    return(*this);
}

bool    isChar(const std::string& s)
{
    if (s.length() == 1 && !isdigit(s.at(0)))
        return(true);
    return(false);
}

bool    isInt(const std::string& s)
{
    long    num;
    const char    *str = s.c_str();
    char    *endpoint;
    num = std::strtol(str, &endpoint, 10);
    if (*endpoint == '\0' && num >= std::numeric_limits<int>::min() && num <= std::numeric_limits<int>::max())
        return (true);
    return (false);
}

bool    isDouble(const std::string& s)
{
    if (s == "-inf" || s == "+inf" || s == "nan")
        return (true);
    if (s.empty())
        return (false);
    double  d;
    char    *end;
    d = std::strtod(s.c_str(), &end);
    if (end == s.c_str() || *end != '\0' || d == std::numeric_limits<double>::infinity()
        || d == -std::numeric_limits<double>::infinity() || std::isnan(d))
        return (false);
    return (true);
}

bool isFloat(const std::string& s)
{  
    if (s.empty())
        return false;
    std::string modifiedString = s;
    if (modifiedString.length() > 0 && modifiedString[modifiedString.length() - 1] == 'f')
        modifiedString.erase(modifiedString.length() - 1); 
    double f;
    char* end;
    f = std::strtod(modifiedString.c_str(), &end);
    if (end == modifiedString.c_str() || *end != '\0' || f < FLOAT_MIN || 
        f > std::numeric_limits<float>::max() || std::isnan(f))
        return (false);
    return (true);
}


char    getType(const std::string& s)
{
    if (isInt(s))
        return ('i');
    else if (isDouble(s))
        return ('d');
    else if (isFloat(s)) 
        return ('f');
    else if (isChar(s))
        return ('c');
    return ('n');
}

void ScalarConverter::convert(const std::string& s)
{
    double d = 0.0;

    if (getType(s) == 'c')
    {
        if (isprint(static_cast<int>(s[0])))
            std::cout << "char: " << static_cast<char>(s.at(0)) << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(s.at(0)) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(s.at(0)) << "f" << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(s.at(0)) << std::endl;
    }
    else if (getType(s) == 'i')
    {
        long    num;
        const char    *str = s.c_str();
        char    *endpoint;
        num = std::strtol(str, &endpoint, 10);
        if (num > 32 && num < 127)
            std::cout << "char: " << static_cast<char>(num) << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(num) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(num) << "f" << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(num) << std::endl;
    }
    else if (getType(s) == 'd')
    {
        char    *end;
        d = std::strtod(s.c_str(), &end);
        if (end == s.c_str() || *end != '\0' || d == std::numeric_limits<double>::infinity()
        || d == -std::numeric_limits<double>::infinity() || std::isnan(d))
        {
            std::cout << "Please provide the valid argument" << std::endl;
            return ;
        }
        if (d == static_cast<int>(d) && d > 32 && d < 127)
            std::cout << "char: " << static_cast<char>(d) << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        if (s == "-inf" || s == "+inf" || s == "nan")
        {
            std::cout << "float: " << s << "f" << std::endl;
            std::cout << "double: " << s << std::endl;
        }
        else
        {
            if (d < FLOAT_MIN || d > std::numeric_limits<float>::max())
                std::cout << "float: impossible" << std::endl;
            else
            {
                std::cout << std::fixed << std::setprecision(1);
                std::cout << "float: " << static_cast<float>(d) << "f"<< std::endl;
            }
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "double: " << static_cast<double>(d) << std::endl;
        } 
    }
    else if (getType(s) == 'f')
    {
        char    *end;
        d = std::strtod(s.c_str(), &end);
        if (end == s.c_str() || *end != '\0' || d < FLOAT_MIN
        || d > std::numeric_limits<float>::max() || std::isnan(d))
        {
            std::cout << "Please provide the valid argument" << std::endl;
            return ;
        }
        if (d == static_cast<int>(d) && d > 32 && d < 127)
            std::cout << "char: " << static_cast<char>(d) << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;
        if (s == "-inff" || s == "+inff" || s == "nanf")
        {
            std::cout << "float: " << s << "f" << std::endl;
            std::cout << "double: " << s << std::endl;
        } 
        else
        {
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "double: " << static_cast<double>(d) << std::endl;
        }
    }
    else
    {
        std::cout << "Please provide valid argument" << std::endl;
        return ;
    }
}




