#include "RobotomyRequestForm.hpp"

#include <iostream>

int	RobotomyRequestForm::counter_rrf_ = 0;

RobotomyRequestForm::RobotomyRequestForm()
		: AForm("Unnamed RRF", RRF_GS, RRF_GE),
		  target_("Unnamed target") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
		: AForm("PPF", RRF_GS, RRF_GE),
		  target_(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &original) {
	*this = original;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) {
	std::cout << "* Drilling noises *" << std::endl;
	if (counter_rrf_ % 2 == 0) {
		std::cout << this->target_ << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomy on " << this->target_ << " has failed..." << std::endl;
	}
	counter_rrf_++;
}

const std::string&	RobotomyRequestForm::getTarget() const {
	return (this->target_);
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &original) {
	if (this != &original) {
		return (*this);
	}
	return (*this);
}
