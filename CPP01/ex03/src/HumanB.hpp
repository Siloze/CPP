#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB {
	private:
		Weapon		*weapon;
		std::string	name;

	public :
		HumanB(std::string nom);
		~HumanB(void);

		void		setName(std::string name);
		void		setWeapon(Weapon &weapon);

		std::string	getName(void) const;
		Weapon		getWeapon(void) const;

        void		attack(void) const;
};

#endif