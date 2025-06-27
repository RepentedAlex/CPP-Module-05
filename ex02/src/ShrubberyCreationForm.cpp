#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Unnamed SCF", SCF_GS, SCF_GE), _target("Unnamed target")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("SCF", SCF_GS, SCF_GE), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &original)
{
	*this = original;
}

///DESTRUCTORS//////////////////////////////////////////////////////////////////
ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

///OPERATOR OVERLOADS///////////////////////////////////////////////////////////
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &original)
{
	if (this != &original)
	{
		return (*this);
	}
	return (*this);
}

///GETTERS//////////////////////////////////////////////////////////////////////
const std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

///SETTERS//////////////////////////////////////////////////////////////////////

///MEMBER FUNCTIONS/////////////////////////////////////////////////////////////
void	ShrubberyCreationForm::execute(const Bureaucrat &executor)
{

}
