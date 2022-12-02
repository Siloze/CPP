#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat
{

	public :
	class GradeTooHighException : public std::exception
	{
		public :
			virtual const char *what () const throw()
			{
				return "Bureaucrat::GradeTooHighException";
			}
	};

	class GradeTooLowException : public std::exception
	{
		public :
			virtual const char *what () const throw()
			{
				return "Bureaucrat::GradeTooLowException";
			}	
	};

	public:

		Bureaucrat(std::string const &nom, short lvl);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		void	setGrade(short niveau);
		short 	getGrade( void ) const;
		void	incrementGrade(short nb);
		void	decrementGrade(short nb);
		std::string const & getName ( void ) const;

		void	signForm(Form &formulaire);
		void	executeForm(Form const & form);
	private:
		std::string const	_name;
		short				_grade;
};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif