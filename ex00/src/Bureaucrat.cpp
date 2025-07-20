#include "Bureaucrat.hpp"

#include <iostream>

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(unsigned int grade) : _name("Scapegoat"), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &original)
{
	*this = original;
}

///DESTRUCTORS//////////////////////////////////////////////////////////////////
Bureaucrat::~Bureaucrat()
{

}

///OPERATOR OVERLOADS///////////////////////////////////////////////////////////
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &original)
{
	if (this != &original)
	{
		this->_grade = original.getGrade();
	}
	return (*this);
}

///GETTERS//////////////////////////////////////////////////////////////////////
unsigned int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

const std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

///SETTERS//////////////////////////////////////////////////////////////////////
void	Bureaucrat::setGrade(const int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}


///MEMBER FUNCTIONS/////////////////////////////////////////////////////////////
void	Bureaucrat::decrementGrade()
{
	if (this->getGrade() >= 150)
		throw GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::incrementGrade()
{
	if (this->getGrade() <= 1)
		throw GradeTooHighException();
	this->_grade--;
}

///EXCEPTIONS///////////////////////////////////////////////////////////////////
const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: Grade too high.");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: Grade too low.");
}



///FOREIGN OVERLOADS////////////////////////////////////////////////////////////
std::ostream	&operator<<(std::ostream &o, Bureaucrat &bureaucrat)
{
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << '.' << std::endl;
	return (o);
}
