#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
PresidentialPardonForm::PresidentialPardonForm() : AForm("Unnamed PPF", PPF_GS, PPF_GE), _target("Unnamed target")
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PPF", PPF_GS, PPF_GE), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &original)
{
	*this = original;
}

///DESTRUCTORS//////////////////////////////////////////////////////////////////
PresidentialPardonForm::~PresidentialPardonForm()
{

}

///OPERATOR OVERLOADS///////////////////////////////////////////////////////////
PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &original)
{
	if (this != &original)
	{
		return (*this);
	}
	return (*this);
}

///GETTERS//////////////////////////////////////////////////////////////////////
const std::string	PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

///SETTERS//////////////////////////////////////////////////////////////////////

///MEMBER FUNCTIONS/////////////////////////////////////////////////////////////
void	PresidentialPardonForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->getIsSigned() == true)
		std::cout << "PresidentialPardonForm " << this->getName() << " is already signed!" << std::endl;
	else if (bureaucrat.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	else
	{
		this->setIsSigned(true);
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}

