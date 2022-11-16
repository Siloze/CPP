#include "Weapon.hpp"

Weapon::Weapon(std::string arme) : type(arme)
{
    return ;
}

Weapon::~Weapon(void)
{
    return ;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}

std::string Weapon::getType(void) const
{
    std::string const &ref = this->type;
    return (ref);
}