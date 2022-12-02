#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &nom, short lvl) :
_name(nom)
{
	setGrade(lvl);
	return ;
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) :
_name(src.getName())
{
	this->setGrade(src.getGrade());
	return ;
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	this->setGrade(rhs.getGrade());
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";  
	return o;
}

std::string const & Bureaucrat::getName ( void ) const
{
	return (this->_name);
}
short Bureaucrat::getGrade ( void ) const
{
	return this->_grade;
}
void Bureaucrat::setGrade( short niveau)
{
	this->_grade = niveau;
	if (niveau > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (niveau < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::incrementGrade( short nb)
{
	this->setGrade(this->getGrade() - nb);
	return ;
}

void Bureaucrat::decrementGrade( short nb)
{
	this->setGrade(this->getGrade() + nb);
	return ;
}

void Bureaucrat::signForm(Form &formulaire)
{
	try
	{
		formulaire.beSigned(*this);
		std::cout << this->getName() << " signed " << formulaire.getName() << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cout << this->getName() << " couldn't sign " << formulaire.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}	
}