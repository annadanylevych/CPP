#include "Fixed.hpp"

Fixed::Fixed(): value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed (const Fixed &another): value(another.value)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed&  Fixed::operator=(const Fixed &another)
{
    if(this != &another)
        this->value = another.value;
    std::cout << "Copy assignment operator called" << std::endl; 
    return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl; 
    return(value);
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}