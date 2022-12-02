#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() :
Form("ShrubberyCreationForm", 145, 137),
_target("")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):
Form("ShrubberyCreationForm", 145, 137),
_target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) :
Form("ShrubberyCreationForm", 145, 137),
_target(src.getTarget())
{
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	o << "ShrubberyCreationForm " << i.getName() << ", target : " << i.getTarget() << " is signed : "  << i.isSigned() << ", Grade to sign : " << i.getGradeToSign() <<", Grade to exec : " << i.getGradeToExec();
	return o;
}

const std::string	&ShrubberyCreationForm::getTarget( void ) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->isSigned())
		throw ShrubberyCreationForm::FormToExecutNotSigned();
	if (executor.getGrade() > this->getGradeToExec())
		throw ShrubberyCreationForm::GradeTooLowToExecException();
	else
	{
		std::ofstream	myfile;
		std::string		fileName = this->_target + "_shrubbery";

		myfile.open(fileName.c_str(), std::ios::out);
			myfile << "      ,.," << std::endl;
		myfile << "      MMMM_    ,..," << std::endl;
		myfile << "        \"_ \"__\"MMMMM          ,...,," << std::endl;
		myfile << " ,..., __.\" --\"    ,.,     _-\"MMMMMMM" << std::endl;
		myfile << "MMMMMM\"___ \"_._   MMM\"_.\"\" _ \"\"\"\"\"\"" << std::endl;
		myfile << " \"\"\"\"\"    \"\" , \\_.   \"_. .\"" << std::endl;
		myfile << "        ,., _\"__ \\__./ .\"" << std::endl;
		myfile << "       MMMMM_\"  \"_    ./" << std::endl;
		myfile << "        ''''      (    )" << std::endl;
		myfile << " ._______________.-'____\"---._." << std::endl;
		myfile << "  \\                          /" << std::endl;
		myfile << "   \\________________________/" << std::endl;
		myfile << "   (_)                    (_)" << std::endl;
		myfile.close();
		std::cout << "Created a binary tree in " << this->getTarget() << "_shrubbery file" << std::endl;
	}
}