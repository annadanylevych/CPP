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
/*    if (s == "-inff" || s == "+inff" || s == "nanf")
        return (true);
    if (s.empty())
        return (false);
    if (s.at(s.length() - 1) != 'f')
        return (false);
    double  d;
    char    *end;
    d = std::strtod(s.c_str(), &end);
    if (end == s.c_str() || *end != '\0' || d > std::numeric_limits<float>::max()
        || d < -std::numeric_limits<float>::max() || std::isnan(d))
        return (false);
    return (true);*/

    unsigned long i = 0;
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


char    getType(const std::string& s)
{
    if (isInt(s))
        return ('i');
    else if (isFloat(s)) 
        return ('f');
    else if (isDouble(s))
        return ('d');
    else if (isChar(s))
        return ('c');
    return ('n');
}

void ScalarConverter::convert(const std::string& s)
{
    if (getType(s) == 'c')
    {
        if (isprint(static_cast<int>(s[0])))
            std::cout << "char: " << static_cast<char>(s.at(0)) << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(s.at(0)) << std::endl;
        std::cout << "float: " << static_cast<float>(s.at(0)) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(s.at(0)) << ".0" << std::endl;
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
        std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
    }
    else if (getType(s) == 'd')
    {
        double  d;
        char    *end;
        d = std::strtod(s.c_str(), &end);
        if (d == static_cast<int>(d) && d > 32 && d < 127)
            std::cout << "char: " << static_cast<char>(d) << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        if (d != '\0' || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
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
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(d) << std::endl;
        }  
    }
    else if (getType(s) == 'f')
    {
        double  d;
        char    *end;
        d = std::strtod(s.c_str(), &end);

        if (d == static_cast<int>(d))
            std::cout << "char: " << static_cast<char>(d) << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        if (d != '\0' || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
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
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(d) << std::endl;
        }  
    }
}




