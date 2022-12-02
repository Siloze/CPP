#include "Bureaucrat.hpp"

int main ( void )
{
    Bureaucrat  bob("Bobby", 2);
    Form        formulaire("Secret form", 3, 10);
    
    std::cout << bob << std::endl;
    std::cout << formulaire << std::endl;
    bob.signForm(formulaire);
    std::cout << formulaire << std::endl;
    try
    {
        Form formulaire ("form", 1, 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
     try
    {
        Form formulaire ("form", 0, 150);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}