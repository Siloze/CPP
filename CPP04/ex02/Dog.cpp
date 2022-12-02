#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "DOG CONSTRUCTOR" << std::endl;
	this->brain = new Brain;
	this->setType("Dog");
	return ;
}

Dog::Dog( const Dog & src )
{
	std::cout << "DOG COPY CONSTRUCTOR" << std::endl;
	this->brain = new Brain;
	this->setType("Dog");
	return ;
}

Dog::~Dog()
{
	std::cout << "DOG DESTRUCTOR" << std::endl;
	delete this->brain;
	return ;
}

Dog &				Dog::operator=( Dog const & rhs )
{
	std::cout << "DOG CPY" << std::endl;
	this->setType(rhs.getType());
	*(this->brain) = *(rhs.getBrain());
	return *this;
}

AAnimal &				Dog::operator=( AAnimal const & rhs )
{
	std::cout << "DOG ANIMAL CPY" << std::endl;
	this->setType(rhs.getType());
	*(this->brain) = *(rhs.getBrain());
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout << this->getType() << " GGRRRRRR WAAAF" << std::endl;
	return ;
}

Brain *Dog::getBrain( void ) const
{
	return (this->brain);
}