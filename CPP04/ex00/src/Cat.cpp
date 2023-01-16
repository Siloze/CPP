#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "CAT CONSTRUCTOR" << std::endl;
	this->setType("Cat");
	return ;
}

Cat::Cat( const Cat & src )
{
	std::cout << "CAT COPY CONSTRUCTOR" << std::endl;
	this->setType(src.getType());
	return ;
}

Cat::~Cat()
{
	std::cout << "CAT DESTRUCTOR" << std::endl;
	return ;
}

Cat &				Cat::operator=( Cat const & rhs )
{
	this->setType(rhs.getType());
	return *this;
}

void Cat::makeSound( void ) const
{
	std::cout << this->getType() << " MIAOUUUUU" << std::endl;
	return ;
}