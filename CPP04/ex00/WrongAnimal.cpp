#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() :
type("Default")
{
	std::cout << "WRONG ANIMAL CONSTRUCTOR" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal( const WrongAnimal & src ) :
type("Default")
{
	std::cout << " WRONG ANIMAL COPIE CONSTRUCTOR" << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WRONG ANIMAL DESTRUCTOR" << std::endl;
	return ;
}

WrongAnimal &				WrongAnimal::operator=( WrongAnimal const & src )
{
	this->setType(src.getType());
	return *this;
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << this->getType() << " make a weird sound.." << std::endl;
	return ;
}

std::string WrongAnimal::getType( void ) const
{
	return (this->type);
}

void		WrongAnimal::setType( std::string type)
{
	this->type = type;
	return ;
}