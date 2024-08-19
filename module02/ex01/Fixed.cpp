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
        this->value = another.getRawBits();
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

Fixed::Fixed(const int integer)
{
    std::cout << "Int constructor called" << std::endl;
    this->setRawBits(integer << fracBits);
}

Fixed::Fixed(const float floating)
{
    this->setRawBits(roundf(floating *(1 << fracBits)));
	std::cout << "Float constructor called" << std::endl;
}

float   Fixed::toFloat(void) const
{
    return (static_cast<float>(getRawBits()) / (1 << fracBits));
}

int Fixed::toInt(void) const
{
    int num;

    num = getRawBits() >> fracBits;
    return(num);
}

std::ostream	&operator<< (std::ostream &out, const Fixed &num)
{
	return (out << num.toFloat());
}