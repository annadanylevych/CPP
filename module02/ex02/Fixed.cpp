#include "Fixed.hpp"

Fixed::Fixed(): value(0){}

Fixed::~Fixed(){}

Fixed::Fixed (const Fixed &another): value(another.value){}

Fixed&  Fixed::operator=(const Fixed &another)
{
    if(this != &another)
        this->value = another.value;
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return(value);
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

Fixed::Fixed(const int integer)
{
    value = integer << fracBits;
}

Fixed::Fixed(const float floating)
{
    value = (std::roundf(floating *(1 << fracBits)));
}

float   Fixed::toFloat(void) const
{
    return (static_cast<float>(value) / (1 << fracBits));
}

int Fixed::toInt(void) const
{
    int num;

    num = value >> fracBits;
    return(num);
}

std::ostream	&operator<< (std::ostream &out, const Fixed &num)
{
	return (out << num.toFloat());
}

bool Fixed::operator>(const Fixed &another)
{
    return(this->value > another.value);
}

bool Fixed::operator<(const Fixed &another)
{
    return(this->value < another.value);
}

bool Fixed::operator>=(const Fixed &another)
{
    return(this->value >= another.value);
}

bool Fixed::operator<=(const Fixed &another)
{
    return(this->value <= another.value);
}

bool Fixed::operator==(const Fixed &another)
{
    return(this->value == another.value);
}

bool Fixed::operator!=(const Fixed &another)
{
    return(this->value != another.value);
}

Fixed   