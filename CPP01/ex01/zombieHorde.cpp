#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int		i;
	Zombie	*stack;

	i = -1;
	stack = new Zombie[N];
	while (++i < N)
	{
		stack[i].setName(name);
		stack[i].announce();
	}
	return (&stack[0]);
}