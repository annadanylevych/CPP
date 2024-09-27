#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& another) 
{
    (void)another;
}

ScalarConverter&    ScalarConverter::operator=(const ScalarConverter& another)
{
    return(*this);
}

bool    isChar(std::string& s)
{
    if (s.length() == 1 && !isdigit(s.at(0)))
        return(true);
    return(false);
}

bool    isInt(std::string& s)
{
    long    num;
    const char    *str = s.c_str();
    char    *endpoint;
    num = std::strtol(str, &endpoint, 10);
    if (*endpoint == '\0' && num >= std::numeric_limits<int>::min() && num <= std::numeric_limits<int>::max())
        return (true);
    return (false);
}

bool    isDouble(std::string& s)
{
    int i = 0;
    bool decPoint = false;
    if (s == "-inf" || s == "+inf" || s == "nan")
        return (true);
    if (s.empty())
        return (false);
    if (s.at(i) == '-' || s.at(i) == '+')
        i++;
    if (i == s.length())
        return (false);
    while (i < s.length())
    {
        if (s.at(i) == '.')
        {
            if (decPoint || i == s.length() - 1)
                return (false);
            decPoint = true;
        }
        else if (!isdigit(s.at(i)))
            return (false);
        i++;
    }
    if (!decPoint)
        return (false);
    return (true);
}

bool isFloat(std::string& s)
{
    int i = 0;
    bool decPoint = false;
    bool f = false;
    if (s == "-inff" || s == "+inff" || s == "nanf")
        return (true);
    if (s.empty())
        return (false);
    if (s.at(i) == '-' || s.at(i) == '+')
        i++;
    if (i == s.length())
        return (false);
    while (i < s.length())
    {
        if (s.at(i) == '.')
        {
            if (decPoint || i == s.length() - 1)
                return (false);
            decPoint = true;
        }
        if (s.at(i) == 'f')
        {
            if (i != s.length() - 1 || f)
                return (false);
            f = true;
        }
        if (!isdigit(s.at(i)) && s.at(i) != 'f' && s.at(i) != '.')
            return (false);
        i++;
    }
    if (!decPoint || !f)
        return(false);
    return (true);
}


char    getType(std::string& s)
{
    if (isInt(s))
        return ('i');
    else if (isFloat(s)) 
        return ('f');
    else if (isDouble(s))
        return ('d');
    else if (isChar(s))
        return ('c');
}

void ScalarConverter::convert(std::string& s)
{
    if (getType(s) == 'c')
    {
        if (isprint(static_cast<int>(s[0])))
            std::cout << "char: " << static_cast<char>(s.at(0)) << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(s.at(0)) << std::endl;
        std::cout << "float: " << static_cast<float>(s.at(0)) << std::endl;
        std::cout << "double: " << static_cast<double>(s.at(0)) << std::endl;
    }    


}




