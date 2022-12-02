#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "DOG CONSTRUCTOR" << std::endl;
	this->setType("Dog");
	return ;
}

Dog::Dog( const Dog & src )
{
	std::cout << "DOG COPY CONSTRUCTOR" << std::endl;
	this->setType("Dog");
	return ;
}

Dog::~Dog()
{
	std::cout << "DOG DESTRUCTOR" << std::endl;
	return ;
}

Dog &				Dog::operator=( Dog const & rhs )
{
	this->setType(rhs.getType());
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout << this->getType() << " GGRRRRRR WAAAF" << std::endl;
	return ;
}