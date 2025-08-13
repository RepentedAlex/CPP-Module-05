#include "Bureaucrat.hpp"

#include <iostream>

Bureaucrat::Bureaucrat(std::string const& name, unsigned int grade)
		: name_(name), grade_(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(unsigned int grade)
		: name_("Scapegoat"), grade_(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& original) {
	*this = original;
}

Bureaucrat::~Bureaucrat() {

}

void	Bureaucrat::decrementGrade() {
	if (this->grade_ >= 150)
		throw GradeTooLowException();
	this->grade_++;
}

unsigned int	Bureaucrat::getGrade() const {
	return (this->grade_);
}

const std::string&	Bureaucrat::getName() const {
	return (this->name_);
}

void	Bureaucrat::incrementGrade() {
	if (this->grade_ <= 1)
		throw GradeTooHighException();
	this->grade_--;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& original) {
	if (this != &original)
		this->grade_ = original.grade_;
	return (*this);
}

void	Bureaucrat::setGrade(const int grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	else
		this->grade_ = grade;
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Error: Grade too low.");
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Error: Grade too high.");
}

std::ostream&	operator<<(std::ostream& o, Bureaucrat& bureaucrat) {
	o << bureaucrat.getName() << "'s grade: " << bureaucrat.getGrade() << '.' << std::endl;
	return (o);
}
