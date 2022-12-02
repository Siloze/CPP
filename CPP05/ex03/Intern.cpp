#include "Intern.hpp"

Intern::Intern()
{
	return ;
}

Intern::Intern( const Intern & src )
{
	(void)src;
	return ;
}

Intern::~Intern()
{
	return ;
}

Intern &				Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return *this;
}

Form *	Intern::makeForm(std::string name, std::string target)
{
	Form *ptr = NULL;
	t_formlist list[3] = {
		{"shrubbery creation", new ShrubberyCreationForm(target)},
		{"presidential pardon", new PresidentialPardonForm(target)},
		{"robotomy request", new RobotomyRequestForm(target)}
	};

	for (int i = 0; i < 3; i++)
	{

		if (name == list[i].form_name)
			ptr = list[i].form_type;
		else
			delete list[i].form_type;
	}
	if (ptr)
		std::cout << "Intern creates" << name << std::endl;
	else
		std::cout << "Intern couldn't find any " << name << " Form." << std::endl;
	return (ptr);
	
}