#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() :
Form("RobotomyRequestForm", 72, 45),
_target("")
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target):
Form("RobotomyRequestForm", 72, 45),
_target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) :
Form("RobotomyRequestForm", 72, 45),
_target(src.getTarget())
{
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	o << "RobotomyRequestForm " << i.getName() << ", target : " << i.getTarget() << " is signed : "  << i.isSigned() << ", Grade to sign : " << i.getGradeToSign() <<", Grade to exec : " << i.getGradeToExec();
	return o;
}

const std::string	&RobotomyRequestForm::getTarget( void ) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->isSigned())
		throw RobotomyRequestForm::FormToExecutNotSigned();
	if (executor.getGrade() > this->getGradeToExec())
		throw RobotomyRequestForm::GradeTooLowToExecException();
	else
	{
		srand(time(NULL));
		if (rand() % 2)
			std::cout << "The target '" << this->getTarget() <<"' as been robotomise !" << std::endl;
		else
			std::cout << "Sorry ! I couldn't robotomise the target '" << this->getTarget() <<"' !" << std::endl;;
	}
}