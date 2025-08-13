#include "Form.hpp"

#include <iostream>

Form::Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExec)
		: name_(name),
		  isSigned_(false),
		  gradeToSign_(gradeToSign),
		  gradeToExec_(gradeToExec) {
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& original)
		: name_(original.name_),
		  gradeToSign_(original.gradeToSign_),
		  gradeToExec_(original.gradeToExec_) {
	*this = original;
}

Form::~Form() {
}

void	Form::beSigned(Bureaucrat bureaucrat) {
	if (this->isSigned_ == true)
		std::cout << "Form " << this->name_ << " is already signed!" << std::endl;
	else if (bureaucrat.getGrade() > this->gradeToSign_)
		throw Form::GradeTooLowException();
	else {
		this->isSigned_ = true;
		std::cout << "Form " << this->name_ << " has been signed by " << bureaucrat.getName() << std::endl;
	}
}

unsigned int	Form::getGradeToExec() const {
	return (this->gradeToExec_);
}

unsigned int	Form::getGradeToSign() const {
	return (this->gradeToSign_);
}

bool	Form::getIsSigned() const {
	return (this->isSigned_);
}

const std::string&	Form::getName() const {
	return (this->name_);
}

Form&	Form::operator=(const Form& original) {
	if (this != &original) {
		this->isSigned_ = original.isSigned_;
	}
	return (*this);
}

const char*	Form::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char*	Form::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

std::ostream&	operator<<(std::ostream& o, const Form& form) {
	o << "Form: " << form.getName() << ": Grade to sign = " << form.getGradeToSign()
		<< " ; Grade to Exec = " << form.getGradeToExec() << " ; Is it signed ? "
		<< form.getIsSigned() << '.' << std::endl;
	return (o);
}
