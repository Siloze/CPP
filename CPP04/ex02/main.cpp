#include "Cat.hpp"
#include "Dog.hpp"

int main ( void )
{
    int i;
    AAnimal *zoo[10];
    i = -1;
    while (++i < 10)
    {
        if (i % 2)
            zoo[i] = new Cat;
        else
            zoo[i] = new Dog;
    }
    zoo[1]->getBrain()->ideas[1] = "A beautiful idea !";
    *(zoo[3]) = *(zoo[1]);
    std::cout << "COPY of zoo[1] type : " << zoo[1]->getType() << " idea[1]  : " << zoo[1]->getBrain()->ideas[1] << " is : " << zoo[3]->getBrain()->ideas[1] << std::endl;
    i = -1;
    while (++i < 10)
        delete zoo[i];
    return 0;
}
