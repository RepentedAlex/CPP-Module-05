#include "PresidentialPardonForm.hpp"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
		: AForm("Unnamed PPF", PPF_GS, PPF_GE),
		  target_("Unnamed target") {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
		: AForm("PPF", PPF_GS, PPF_GE),
		  target_(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &original) {
	*this = original;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) {
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
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
