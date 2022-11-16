#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA {
	private:
		Weapon		&weapon;
		std::string	name;

	public :
		HumanA(std::string nom, Weapon &arme);
		~HumanA(void);

		void		setName(std::string name);
		void		setWeapon(Weapon &weapon);

		std::string	getName(void) const;
		Weapon		getWeapon(void) const;

        void		attack(void) const;
};

#endif