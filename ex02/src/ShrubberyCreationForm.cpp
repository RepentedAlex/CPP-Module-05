#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
		: AForm("Unnamed SCF", SCF_GS, SCF_GE),
		  target_("Unnamed target") {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
		: AForm("SCF", SCF_GS, SCF_GE),
		  target_(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &original) {
	*this = original;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &original) {
	if (this != &original) {
		return (*this);
	}
	return (*this);
}

const std::string&	ShrubberyCreationForm::getTarget() const {
	return (this->target_);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) {

}
