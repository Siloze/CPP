#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WRONG CAT CONSTRUCTOR" << std::endl;
	this->setType("WrongCat");
	return ;
}

WrongCat::WrongCat( const WrongCat & src )
{
	std::cout << "WRONG CAT COPY CONSTRUCTOR" << std::endl;
	this->setType("WrongCat");
	return ;
}

WrongCat::~WrongCat()
{
	std::cout << "WRONG CAT DESTRUCTOR" << std::endl;
	return ;
}

WrongCat &				WrongCat::operator=( WrongCat const & rhs )
{
	this->setType(rhs.getType());
	return *this;
}

void WrongCat::makeSound( void ) const
{
	std::cout << this->getType() << " MIAOUUUUU" << std::endl;
	return ;
}