#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	public:

	class GradeTooLowToExecException : public std::exception
	{
		public :
			virtual const char *what () const throw()
			{
				return "ShrubberyCreationForm::GradeTooLowToExecException";
			}	
	};
	class FormToExecutNotSigned : public std::exception
	{
		public :
			virtual const char *what () const throw()
			{
				return "ShrubberyCreationForm::FormToExecutNotSigned";
			}	
	};
	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		~ShrubberyCreationForm();

		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );
		const std::string &getTarget( void ) const;
		virtual void		execute(Bureaucrat const & executor) const;

	private:
		std::string const _target;
};

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i );

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */