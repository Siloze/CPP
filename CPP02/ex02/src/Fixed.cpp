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

bool Fixed::operator==(const Fixed &rhs) const
{
    return (this->_value == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const
{
    return (this->_value != rhs.getRawBits());
}

bool Fixed::operator>(const Fixed &rhs) const
{
    return (this->_value > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const
{
    return (this->_value < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const
{
    return (this->_value >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const
{
    return (this->_value <= rhs.getRawBits());
}

Fixed Fixed::operator+(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed &Fixed::operator++(void)
{
    this->_value++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->_value++;
    return (tmp);
}

Fixed &Fixed::operator--(void)
{
    this->_value--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->_value--;
    return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b ? a : b);
}
int Fixed::getRawBits(void) const
{
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->_value / (1 << this->_bits));
}

int Fixed::toInt(void) const
{
    return (this->_value >> this->_bits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
    o << rhs.toFloat();
    return (o);
}
