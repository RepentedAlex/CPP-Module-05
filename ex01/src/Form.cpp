#include <iostream>

#include "Form.hpp"

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
Form::Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExec) : \
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &original) : \
	_name(original.getName()), _gradeToSign(original.getGradeToSign()), _gradeToExec(original.getGradeToExec())
{
	*this = original;
}

///DESTRUCTORS//////////////////////////////////////////////////////////////////
Form::~Form()
{
}

///OPERATOR OVERLOADS///////////////////////////////////////////////////////////
Form	&Form::operator=(const Form &original)
{
	if (this != &original)
	{
		this->_isSigned = original.getIsSigned();
	}
	return (*this);
}

///GETTERS//////////////////////////////////////////////////////////////////////
unsigned int	Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}

unsigned int	Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

bool	Form::getIsSigned() const
{
	return (this->_isSigned);
}

const std::string	Form::getName() const
{
	return (this->_name);
}

///SETTERS//////////////////////////////////////////////////////////////////////
void	Form::setIsSigned(const bool state)
{
	this->_isSigned = state;
}

///MEMBER FUNCTIONS/////////////////////////////////////////////////////////////
void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_isSigned == true)
		std::cout << "Form " << this->getName() << " is already signed!" << std::endl;
	else if (bureaucrat.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	else
	{
		this->_isSigned = true;
		std::cout << "Form " << this->getName() << " has been signed by " << bureaucrat.getName() << std::endl;
	}
}


///EXCEPTIONS///////////////////////////////////////////////////////////////////
const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

///FOREING OVERLOADS
std::ostream	&operator<<(std::ostream &o, const Form &form)
{
	o << "Form: " << form.getName() << ": Grade to sign = " << form.getGradeToSign()
	<< " ; Grade to Exec = " << form.getGradeToExec() << " ; Is it signed ? " << form.getIsSigned() << '.';
	return (o);
}
