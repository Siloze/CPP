#include "FragTrap.hpp"


FragTrap::FragTrap( void )
{
    this->_name = ("...");
    this->_attack_damage = 20;
    this->_hit_points = 100;
    this->_energy_points = 50;
    std::cout << "New unamed FragTrap just arrive !" << std::endl;
    return ;
}

FragTrap::FragTrap( std::string const & name )
{
    this->_attack_damage = 20;
    this->_hit_points = 100;
    this->_energy_points = 50;
    this->_name = name;
    std::cout << "New FragTrap named : '" << name << "' just arrive !" << std::endl;
    return ;
}

FragTrap::~FragTrap ( void )
{
    std::cout << "FragTrap named : '" << this->getName() << "' just beeing destroyed !" << std::endl;
    return ;
}

FragTrap::FragTrap( FragTrap const &src)
{
    this->_attack_damage = src.getAttackDamage();
    this->_hit_points = src.getHitPoints();
    this->_energy_points = src.getEnergyPoints();
    this->_name = src.getName();
    std::cout << "A clone of FragTrap named : '" << src._name << "' just arrive !" << std::endl;
    return ;
}

FragTrap &FragTrap::operator=(FragTrap const &src)
{
    this->_name = src._name;
    this->_attack_damage = src._attack_damage;
    this->_energy_points = src._energy_points;
    this->_hit_points = src._hit_points;
    std::cout << "A FragTrap just copie the one named : '" << src._name << "'" << std::endl;
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap named : " << this->getName() << " want a High Five !" << std::endl;
}