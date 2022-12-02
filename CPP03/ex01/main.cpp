#include "ScavTrap.hpp"

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
    ScavTrap ultia ("Juwls");
    ultia.attack(boo.getName());
    ultia.beRepaired(10);
    ultia.guardGate();
}