#pragma once

#include <iostream>
#include <cmath>
#include <string>

class Fixed
{
    private:

    int value;
    static  const int fracBits = 8;

    public:
        Fixed(const int num);
        Fixed();
        ~Fixed();
        Fixed (const Fixed &another);
        Fixed&  operator=(const Fixed &another);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        Fixed(const float num);
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream	&operator<< (std::ostream &out, const Fixed &num);
