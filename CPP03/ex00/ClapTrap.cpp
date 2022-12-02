#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap( void ) :
_name("..."),
_hit_points(10),
_energy_points(10),
_attack_damage(0)
{
    std::cout << "New unamed ClapTrap just arrive !" << std::endl;
    return ;
}

ClapTrap::ClapTrap( std::string const & name ) :
_name(name),
_hit_points(10),
_energy_points(10),
_attack_damage(0)
{
    std::cout << "New ClapTrap named : '" << name << "' just arrive !" << std::endl;
    return ;
}

ClapTrap::~ClapTrap ( void )
{
    return ;
}

ClapTrap::ClapTrap( ClapTrap const &src) :
_name(src._name),
_hit_points(src._hit_points),
_energy_points(src._energy_points),
_attack_damage(src._attack_damage)
{
    std::cout << "A clone of ClapTrap named : '" << src._name << "' just arrive !" << std::endl;
    return ;
}

int ClapTrap::getHitPoints ( void ) const
{
    return (this->_hit_points);
}

int ClapTrap::getAttackDamage ( void ) const
{
    return (this->_attack_damage);
}

int ClapTrap::getEnergyPoints ( void ) const
{
    return (this->_energy_points);
}

std::string ClapTrap::getName ( void ) const
{
    return (this->_name);
}

ClapTrap &ClapTrap::operator=(ClapTrap const &src)
{
    this->_name = src._name;
    this->_attack_damage = src._attack_damage;
    this->_energy_points = src._energy_points;
    this->_hit_points = src._hit_points;
    std::cout << "A ClapTrap just copie the one named : '" << src._name << "'" << std::endl;
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    std::cout << "ClapTrap named : '" << this->_name << "' attacks '"
    << target << "', causing '" << this->_attack_damage << "' damage to it !" << std::endl;
    return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hit_points - amount > 0)
        this->_hit_points -= amount;
    else
        this->_hit_points = 0;
    std::cout << "ClapTrap named : '" << this->_name << "' was hurt and lose '"
    << amount << "' hit points !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap named : '" << this->_name << " just be repaire of '"
    << amount << "' hit points !" << std::endl;
    this->_hit_points += amount;
}