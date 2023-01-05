#include "Zombie.hpp"

int main(void)
{
    Zombie *bob;

    bob = newZombie("Bobby");
    randomChump("Mat");
    delete bob;
}