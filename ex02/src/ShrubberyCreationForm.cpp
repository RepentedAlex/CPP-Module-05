#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
		: AForm("Unnamed Shrubbery Creation Form", SCF_GS, SCF_GE),
		  target_("Unnamed target") {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
		: AForm("Shrubbery Creation Form", SCF_GS, SCF_GE),
		  target_(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& original)
		: AForm(original.getName(), original.getGradeToSign(), original.getGradeToExec()) {
	*this = original;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

/// @todo Implement effect of Form
void	ShrubberyCreationForm::execute(const Bureaucrat& executor) {
	if (executor.getGrade() > this->getGradeToExec()) {
		throw AForm::GradeTooLowException();
	} else {
	}
}

const std::string&	ShrubberyCreationForm::getTarget() const {
	return (this->target_);
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& original) {
	if (this != &original) {
		return (*this);
	}
	return (*this);
}
