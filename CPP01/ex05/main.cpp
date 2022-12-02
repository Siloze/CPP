#include "Harl.hpp"

int main (void)
{
    Harl bonhomme;
    
    std::cout << "Complain debug : " << std::endl;
    bonhomme.complain("d");
    std::cout << "Complain error : " << std::endl;
    bonhomme.complain("e");
    std::cout << "Complain info : " << std::endl;
    bonhomme.complain("i");
    std::cout << "Complain warning : " << std::endl;
    bonhomme.complain("w");

    return (0);
}