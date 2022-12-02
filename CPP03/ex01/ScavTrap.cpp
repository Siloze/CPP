#include "ScavTrap.hpp"


ScavTrap::ScavTrap( void )
{
    this->_name = ("...");
    this->_attack_damage = 20;
    this->_hit_points = 100;
    this->_energy_points = 50;
    std::cout << "New unamed ScavTrap just arrive !" << std::endl;
    return ;
}

ScavTrap::ScavTrap( std::string const & name )
{
    this->_attack_damage = 20;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_name = name;
    std::cout << "New ScavTrap named : '" << name << "' just arrive !" << std::endl;
    return ;
}

ScavTrap::~ScavTrap ( void )
{
    std::cout << "ScavTrap named : '" << this->getName() << "' just beeing destroyed !" << std::endl;
    return ;
}

ScavTrap::ScavTrap( ScavTrap const &src)
{
    this->_attack_damage = src.getAttackDamage();
    this->_hit_points = src.getHitPoints();
    this->_energy_points = src.getEnergyPoints();
    this->_name = src.getName();
    std::cout << "A clone of ScavTrap named : '" << src._name << "' just arrive !" << std::endl;
    return ;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &src)
{
    this->_name = src._name;
    this->_attack_damage = src._attack_damage;
    this->_energy_points = src._energy_points;
    this->_hit_points = src._hit_points;
    std::cout << "A ScavTrap just copie the one named : '" << src._name << "'" << std::endl;
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    std::cout << "Monster ScavTrap named : '" << this->_name << "' attacks '"
    << target << "', causing '" << this->_attack_damage << "' damage to it !" << std::endl;
    return ;
}

void ScavTrap::guardGate( void )
{
    std::cout << "Little shy ScavTrap named : '" << this->getName() << "' just go to Gate keeper mode ." << std::endl;
    return ;
}