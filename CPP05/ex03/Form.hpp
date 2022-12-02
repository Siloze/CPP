#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public :
	class GradeTooHighException : public std::exception
	{
		public :
			virtual const char *what () const throw()
			{
				return "Form::GradeTooHighException";
			}
	};

	class GradeTooLowException : public std::exception
	{
		public :
			virtual const char *what () const throw()
			{
				return "Form::GradeTooLowException";
			}	
	};
	public:

		Form();
		Form( Form const & src );
		Form (std::string name, short to_sign, short to_exec);
		virtual ~Form();

		Form &		operator=( Form const & rhs );
		bool				isSigned( void ) const;
		std::string const & getName( void ) const;
		short			getGradeToSign( void ) const;
		short			getGradeToExec( void ) const;
		virtual const std::string &getTarget( void ) const = 0;
		void				beSigned(Bureaucrat &src);
		virtual void		execute(Bureaucrat const & executor) const = 0;

	private:
		std::string const	_name;
		bool				_signed;
		short const			_to_sign;
		short const			_to_exec;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif