#include "Fixed.hpp"

Fixed::Fixed(void)
{
    this->_value = 0;
}

Fixed::Fixed(const int value)
{
    this->_value = value << this->_bits;
}

Fixed::Fixed(const float value)
{
    this->_value = roundf(value * (1 << this->_bits));
}

Fixed::Fixed(const Fixed &src)
{
    *this = src;
}

Fixed::~Fixed(void)
{
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
    this->_value = rhs.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}
