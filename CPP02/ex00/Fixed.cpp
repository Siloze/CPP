#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed( void ) :
value(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed( int const nb ) :
value(nb)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::~Fixed ( void )
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed::Fixed( Fixed const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    this->value = src.getRawBits();
    return ;
}

Fixed &Fixed::operator=(Fixed const &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->value = src.getRawBits();
    return (*this);
}

int Fixed::getRawBits ( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->value);
}

void Fixed::setRawBits ( int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

const int Fixed::bits_fractionary = 8;