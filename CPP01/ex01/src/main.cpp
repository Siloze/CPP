#include "Zombie.hpp"

int main(void)
{
    Zombie *bob;

    bob = zombieHorde(5, "Boo");
    for (int i = 0; i < 5; i++)
        bob[i].announce();
    delete [] bob;
    return (0);
}