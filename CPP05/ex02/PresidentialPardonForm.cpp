#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() :
Form("PresidentialPardonForm", 25, 5),
_target("")
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target):
Form("PresidentialPardonForm", 25, 5),
_target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) :
Form("PresidentialPardonForm", 25, 5),
_target(src.getTarget())
{
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i )
{
	o << "PresidentialPardonForm " << i.getName() << ", target : " << i.getTarget() << " is signed : "  << i.isSigned() << ", Grade to sign : " << i.getGradeToSign() <<", Grade to exec : " << i.getGradeToExec();
	return o;
}

const std::string	&PresidentialPardonForm::getTarget( void ) const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->isSigned())
		throw PresidentialPardonForm::FormToExecutNotSigned();
	if (executor.getGrade() > this->getGradeToExec())
		throw PresidentialPardonForm::GradeTooLowToExecException();
	else
		std::cout << this->getTarget() << " a été pardonnée par Zaphod Beeblebrox." << std::endl;
}