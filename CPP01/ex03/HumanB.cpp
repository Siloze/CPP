#include "HumanB.hpp"

HumanB::HumanB(std::string nom) : name(nom), weapon(NULL)
{
    return ;
}

HumanB::~HumanB(void)
{
    return ;
}

void HumanB::setName(std::string name)
{
    this->name = name;
}

std::string HumanB::getName(void) const
{
    return (this->name);
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

Weapon HumanB::getWeapon(void) const
{
    return (*this->weapon);
}


void HumanB::attack(void) const
{
    std::cout << this->getName() << " attacks with their " << this->getWeapon().getType() << std::endl;
}