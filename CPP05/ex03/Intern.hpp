#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator=( Intern const & rhs );
		Form *			makeForm( std::string, std::string );
	private:
		typedef struct s_formlist
		{
			public :
				std::string form_name;
				Form*		form_type;
		}	t_formlist;

};

#endif