#include "Zombie.hpp"

 Zombie* newZombie( std::string name )
 {
    Zombie *obj = new Zombie();

    obj->setName(name);
    return (obj);
 }
