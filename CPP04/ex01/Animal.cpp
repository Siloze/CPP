#include "Animal.hpp"

Animal::Animal() :
type("Default")
{
	std::cout << "ANIMAL CONSTRUCTOR" << std::endl;
	return ;
}

Animal::Animal( const Animal & src ) :
type("Default")
{
	std::cout << "ANIMAL COPIE CONSTRUCTOR" << std::endl;
	return ;
}

Animal::~Animal()
{
	std::cout << "ANIMAL DESTRUCTOR" << std::endl;
	return ;
}

Animal &Animal::operator=( Animal const & src )
{
	std::cout << "ANIMAL CPY" << std::endl;
	this->setType(src.getType());
	return *this;
}

void Animal::makeSound( void ) const
{
	std::cout << this->getType() << " make a weird sound.." << std::endl;
	return ;
}

std::string Animal::getType( void ) const
{
	return (this->type);
}

void		Animal::setType( std::string type)
{
	this->type = type;
	return ;
}