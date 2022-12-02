#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main ( void )
{
    try
    {
     Bureaucrat  bob("wrong", 160);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    Bureaucrat  bob("Bobby", 45);
    Form        *formulaire;
    formulaire = new ShrubberyCreationForm("salut");    
    std::cout << bob << std::endl;
    std::cout << *formulaire << std::endl;
    bob.signForm(*formulaire);
    std::cout << *formulaire << std::endl;
    bob.executeForm(*formulaire);
    formulaire = new RobotomyRequestForm("Roboottt");
    std::cout << bob << std::endl;
    std::cout << *formulaire << std::endl;
    bob.signForm(*formulaire);
    std::cout << *formulaire << std::endl;
    bob.executeForm(*formulaire); 
    return (0);
}