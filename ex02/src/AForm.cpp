#include <iostream>

#include "AForm.hpp"

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
AForm::AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExec) : \
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &original) : \
	_name(original.getName()), _gradeToSign(original.getGradeToSign()), _gradeToExec(original.getGradeToExec())
{
	*this = original;
}

///DESTRUCTORS//////////////////////////////////////////////////////////////////
AForm::~AForm()
{
}

///OPERATOR OVERLOADS///////////////////////////////////////////////////////////
AForm	&AForm::operator=(const AForm &original)
{
	if (this != &original)
	{
		this->_isSigned = original.getIsSigned();
	}
	return (*this);
}

///GETTERS//////////////////////////////////////////////////////////////////////
unsigned int	AForm::getGradeToExec() const
{
	return (this->_gradeToExec);
}

unsigned int	AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

bool	AForm::getIsSigned() const
{
	return (this->_isSigned);
}

const std::string	AForm::getName() const
{
	return (this->_name);
}

///SETTERS//////////////////////////////////////////////////////////////////////
void	AForm::setIsSigned(const bool state)
{
	this->_isSigned = state;
}

///MEMBER FUNCTIONS/////////////////////////////////////////////////////////////
void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->getIsSigned() == true)
		std::cout << this->getName() << " is already signed!" << std::endl;
	else if (bureaucrat.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	else
	{
		this->setIsSigned(true);
		std::cout << this->getName() << " has been signed by " << bureaucrat.getName() << '!' << std::endl;
	}
}

///EXCEPTIONS///////////////////////////////////////////////////////////////////
const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

///FOREING OVERLOADS
std::ostream	&operator<<(std::ostream &o, const AForm &form)
{
	o << "AForm: " << form.getName() << ": Grade to sign = " << form.getGradeToSign()
	<< " ; Grade to Exec = " << form.getGradeToExec() << " ; Is it signed ? " << form.getIsSigned() << '.';
	return (o);
}
