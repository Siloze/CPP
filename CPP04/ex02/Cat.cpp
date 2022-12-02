#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "CAT CONSTRUCTOR" << std::endl;
	this->brain = new Brain;
	this->setType("Cat");
	return ;
}

Cat::Cat( const Cat & src )
{
	std::cout << "CAT COPY CONSTRUCTOR" << std::endl;
	this->brain = new Brain;
	this->setType("Cat");
	return ;
}

Cat::~Cat()
{
	std::cout << "CAT DESTRUCTOR" << std::endl;
	delete this->brain;
	return ;
}

Cat &				Cat::operator=( Cat const & rhs )
{
	std::cout << "CAT CPY" << std::endl;
	this->setType(rhs.getType());
	*(this->brain) = *(rhs.getBrain());
	return *this;
}

AAnimal &				Cat::operator=( AAnimal const & rhs )
{
	std::cout << "CAT ANIMAL CPY" << std::endl;
	this->setType(rhs.getType());
	*(this->brain) = *(rhs.getBrain());
	return *this;
}


void Cat::makeSound( void ) const
{
	std::cout << this->getType() << " MIAOUUUUU" << std::endl;
	return ;
}

Brain *Cat::getBrain( void ) const
{
	return (this->brain);
}