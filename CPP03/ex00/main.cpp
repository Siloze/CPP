#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap kaa ("Kaaris");
    ClapTrap boo ("Booba");

    boo.attack(kaa.getName());
    kaa.takeDamage(boo.getAttackDamage());
    ClapTrap kaa2;
    kaa2 = kaa;
    kaa.beRepaired(5);
    kaa2.attack(boo.getName());
    boo.takeDamage(kaa2.getAttackDamage());
}