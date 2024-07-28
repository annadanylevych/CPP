#pragma once

#include <iostream>
#include <string>

class Fixed
{
    private:

    int value;
    static  const int fracBits = 8;

    public:
        Fixed();
        ~Fixed();
        Fixed (const Fixed &another);
        Fixed&  operator=(const Fixed &another);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};
