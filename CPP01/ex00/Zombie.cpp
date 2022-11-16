#include "Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << this->getName() << " zombie is destroy" << std::endl;
	return ;
}

std::string Zombie::getName(void) const
{
	return (this->name);
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::announce(void) const
{
	std::cout << this->getName() << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}