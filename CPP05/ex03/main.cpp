#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

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
    Intern dumb;
    Bureaucrat  bob("Bobby", 45);
    Form        *formulaire;
    
    formulaire = dumb.makeForm("shrubbery creation", "tree"); 
    std::cout << bob << std::endl;
    std::cout << *formulaire << std::endl;
    bob.signForm(*formulaire);
    std::cout << *formulaire << std::endl;
    bob.executeForm(*formulaire);
    formulaire = dumb.makeForm("roboegfregvre", "tree"); 
    std::cout << bob << std::endl;
    formulaire = dumb.makeForm("robotomy request", "tree"); 
    std::cout << *formulaire << std::endl;
    bob.signForm(*formulaire);
    std::cout << *formulaire << std::endl;
    bob.executeForm(*formulaire); 
    return (0);
}