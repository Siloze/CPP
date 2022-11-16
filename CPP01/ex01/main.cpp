#include "Zombie.hpp"

int main(void)
{
    Zombie *bob;

    bob = zombieHorde(5, "Boo");
    delete [] bob;
}