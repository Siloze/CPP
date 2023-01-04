#include "Fixed.hpp"

int main(void)
{
    Fixed a(10.420f);
    Fixed b(10);
    Fixed c(42.42f);
    Fixed d(b);

    std::cout << "a is " << a.getRawBits() << std::endl;
    std::cout << "b is " << b.getRawBits() << std::endl;
    std::cout << "c is " << c.getRawBits() << std::endl;
    std::cout << "d is " << d.getRawBits() << std::endl;
    return (0);
}
