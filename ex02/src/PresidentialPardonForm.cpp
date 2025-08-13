#include "PresidentialPardonForm.hpp"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
		: AForm("Unnamed Presidential Pardon Form", PPF_GS, PPF_GE),
		  target_("Unnamed target") {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
		: AForm("Presidential Pardon Form", PPF_GS, PPF_GE),
		  target_(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &original)
		: AForm(original.getName(), original.getGradeToSign(), original.getGradeToExec()) {
	*this = original;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) {
	if (executor.getGrade() > this->getGradeToExec()) {
		throw AForm::GradeTooLowException();
	} else {
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}

const std::string&	PresidentialPardonForm::getTarget() const {
	return (this->target_);
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &original) {
	if (this != &original) {
		return (*this);
	}
	return (*this);
}
