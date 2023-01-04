#include "Fixed.hpp"

//main function with incrementation and decrementation
int main(void)
{
    Fixed a(10.420f);
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    std::cout << "a++ is " << a++ << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "++a is " << ++a << std::endl;
    std::cout << "a is " << a << std::endl;

    std::cout << "b-- is " << b-- << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "--b is " << --b << std::endl;
    std::cout << "b is " << b << std::endl;

    return (0);
}