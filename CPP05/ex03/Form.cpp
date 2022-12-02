#include "Form.hpp"

void check_grade(short grade)
{
	if (grade > 150)
		throw Form::GradeTooLowException();
	else if (grade < 1)
		throw Form::GradeTooHighException();
	return ;
}

Form::Form(void) :
_name(""),
_signed(false),
_to_sign(150),
_to_exec(150)
{
	return ;
}

Form::Form( const Form & src ) :
_name(src.getName()),
_to_sign(src.getGradeToSign()),
_to_exec(src.getGradeToExec())
{
	check_grade(this->getGradeToSign());
	check_grade(this->getGradeToExec());
	return ;
}

Form::Form (std::string name, short to_sign, short to_exec) :
_name(name),
_to_sign(to_sign),
_to_exec(to_exec)
{
	check_grade(this->getGradeToSign());
	check_grade(this->getGradeToExec());
	return ;
}

Form::~Form()
{
}

Form &				Form::operator=( Form const & rhs )
{
	*this = rhs;
	check_grade(this->getGradeToSign());
	check_grade(this->getGradeToExec());
	return *this;
}

std::string const &Form::getName( void ) const
{
	return (this->_name);
}

short Form::getGradeToExec ( void ) const
{
	return (this->_to_exec);
}

short Form::getGradeToSign ( void ) const
{
	return (this->_to_sign);
}

bool Form::isSigned ( void ) const
{
	return (this->_signed);
}

void	Form::beSigned(Bureaucrat &src)
{
	if (this->getGradeToSign() < src.getGrade())
		throw Form::GradeTooLowException();
	else
		this->_signed = true;

}
std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << i.getName() << ", is signed : " << i.isSigned() << ", Grade to sign : " << i.getGradeToSign() <<", Grade to exec : " << i.getGradeToExec();
	return o;
}
