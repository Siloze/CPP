#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
	private :
		std::string _name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;
	public :
		ClapTrap (void);
		ClapTrap (ClapTrap const &src);
		ClapTrap (std::string const & name);
		~ClapTrap(void);

		ClapTrap & operator=(ClapTrap const &src);	

		int getHitPoints ( void ) const;
		int getEnergyPoints ( void ) const;
		int getAttackDamage ( void ) const;

		std::string getName ( void ) const;
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif