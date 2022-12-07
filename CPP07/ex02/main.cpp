#include <iostream>
#include "Array.hpp"

int main(void)
{
    Array<int> list(3);
    Array<std::string> volant(5);
    Array<std::string> cpy(10);
    Array<int> list_empty;
    list[0] = 10;
    list[1] = 3;
    list[2] = 394;
    volant[0] = "SALUT A TOUS";
    volant[1] = "ET A TOUTESS";
    volant[2] = "JE SUIS AHH";
    std::cout << cpy << std::endl;
    std::cout << list << std::endl;
    std::cout << list_empty << std::endl;
    cpy = volant;
    cpy[3] = "OEEEEE";
    std::cout << volant << std::endl;
    std::cout << cpy << std::endl;
}