#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie {
	private :
		std::string name;
		
	public :
		Zombie(void);
		~Zombie(void);
		std::string getName(void);
		void		setName(std::string name);
		void		announce(void);

};

void randomChump( std::string name );
Zombie* newZombie( std::string name );
Zombie* zombieHorde( int N, std::string name );

#endif