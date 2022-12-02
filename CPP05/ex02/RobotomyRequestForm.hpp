#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	public:

	class GradeTooLowToExecException : public std::exception
	{
		public :
			virtual const char *what () const throw()
			{
				return "RobotomyRequestForm::GradeTooLowToExecException";
			}	
	};
	class FormToExecutNotSigned : public std::exception
	{
		public :
			virtual const char *what () const throw()
			{
				return "RobotomyRequestForm::FormToExecutNotSigned";
			}	
	};
	public:

		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm( RobotomyRequestForm const & src );
		~RobotomyRequestForm();

		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );
		const std::string &getTarget( void ) const;
		virtual void		execute(Bureaucrat const & executor) const;

	private:
		std::string const _target;
};

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */