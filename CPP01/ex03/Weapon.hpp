#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
	private :
		std::string type;
	public :
		Weapon(std::string arme);
		~Weapon(void);
		void setType(std::string type);
		std::string getType(void) const;
};

#endif