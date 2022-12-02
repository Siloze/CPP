#include "AAnimal.hpp"

AAnimal::AAnimal() :
type("Default")
{
	std::cout << "ANIMAL CONSTRUCTOR" << std::endl;
	return ;
}

AAnimal::AAnimal( const AAnimal & src ) :
type("Default")
{
	std::cout << "ANIMAL COPIE CONSTRUCTOR" << std::endl;
	return ;
}

AAnimal::~AAnimal()
{
	std::cout << "ANIMAL DESTRUCTOR" << std::endl;
	return ;
}

std::string AAnimal::getType( void ) const
{
	return (this->type);
}

void		AAnimal::setType( std::string type)
{
	this->type = type;
	return ;
}