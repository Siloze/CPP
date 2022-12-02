#include "Bureaucrat.hpp"

int main ( void )
{
    Bureaucrat bob("Bobby", 2);

    std::cout << bob << std::endl;
    try
    {
        bob.setGrade(151);
    }
    catch(const std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << bob << std::endl;
    try
    {
       bob.setGrade(0);
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << bob << std::endl;

    return (0);
}