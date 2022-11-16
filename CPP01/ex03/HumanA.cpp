#include "HumanA.hpp"

HumanA::HumanA(std::string nom, Weapon &arme) : name(nom), weapon(arme)
{
    return ;
}

HumanA::~HumanA(void)
{
    return ;
}

void HumanA::setName(std::string name)
{
    this->name = name;
}

std::string HumanA::getName(void) const
{
    return (this->name);
}

void HumanA::setWeapon(Weapon &weapon)
{
    this->weapon = weapon;
}

Weapon HumanA::getWeapon(void) const
{
    return (this->weapon);
}


void HumanA::attack(void) const
{
    std::cout << this->getName() << " attacks with their " << this->getWeapon().getType() << std::endl;
}