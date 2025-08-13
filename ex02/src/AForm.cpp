#include "AForm.hpp"

#include <iostream>

AForm::AForm(std::string name, unsigned int gradeToSign, unsigned int gradeToExec)
		: name_(name),
		  isSigned_(false),
		  gradeToSign_(gradeToSign),
		  gradeToExec_(gradeToExec) {
	if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& original)
		: name_(original.name_),
		  gradeToSign_(original.gradeToSign_),
		  gradeToExec_(original.gradeToExec_) {
	*this = original;
}

AForm::~AForm() {}

void	AForm::beSigned(Bureaucrat bureaucrat) {
	if (this->isSigned_ == true) {
		std::cout << "AForm " << this->name_ << " is already signed!" << std::endl;
	} else if (bureaucrat.getGrade() > this->gradeToSign_) {
		throw AForm::GradeTooLowException();
	} else {
		this->isSigned_ = true;
		std::cout << "AForm " << this->name_ << " has been signed by " << bureaucrat.getName() << std::endl;
	}
}

unsigned int	AForm::getGradeToExec() const {
	return (this->gradeToExec_);
}

unsigned int	AForm::getGradeToSign() const {
	return (this->gradeToSign_);
}

bool	AForm::getIsSigned() const {
	return (this->isSigned_);
}

const std::string&	AForm::getName() const {
	return (this->name_);
}

AForm&	AForm::operator=(const AForm& original) {
	if (this != &original) {
		this->isSigned_ = original.isSigned_;
	}
	return (*this);
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

std::ostream&	operator<<(std::ostream& o, const AForm& form) {
	o	<< "AForm " << form.getName()
		<< ": Grade to sign = " << form.getGradeToSign()
		<< " ; Grade to Exec = " << form.getGradeToExec()
		<< " ; Is it signed ? " << (form.getIsSigned() ? "Yes" : "No")
		<< '.' << std::endl;
	return (o);
}
