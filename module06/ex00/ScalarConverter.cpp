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
    int i = 0;
    if (s.empty())
        return (false);
    if (s.at(i) == '-' || s.at(i) == '+')
        i++;
    if (i == s.length())
        return (false);
    while (i < s.length())
    {
        if (!isdigit(s.at(i)))
            return (false);
        i++;
    }
    return (true);
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


void    getType(std::string& s)
{
    
}

void ScalarConverter::convert(std::string& s)
{

}*/




