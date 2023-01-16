#include "Brain.hpp"

Brain::Brain()
{
	return ;
}

Brain::Brain( const Brain & src )
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	return ;
}

Brain::~Brain()
{
	return ;
}

Brain &				Brain::operator=( Brain const & rhs )
{
	std::cout << "Brain cpy" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = rhs.ideas[i];
	return *this;
}
