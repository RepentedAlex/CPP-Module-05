#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

static std::string	possibleForms[] = {"presidential pardon", "robotomy request", "shrubbery creation"};

Intern::Intern() {
}

Intern::Intern(const Intern& original) {
	*this = original;
}

Intern::~Intern() {
}

AForm*	Intern::makeForm(const std::string name, const std::string target) {
	int	i = 0;
	AForm*	ret = NULL;

	while (i < 3 && possibleForms[i] != name) {
		i++;
	}
	switch (i) {
	case 0:
		std::cout << "Intern creates " << name << std::endl;
		ret = new PresidentialPardonForm(target);
		break;
	case 1:
		std::cout << "Intern creates " << name << std::endl;
		ret = new RobotomyRequestForm(target);
		break;
	case 2:
		std::cout << "Intern creates " << name << std::endl;
		ret = new ShrubberyCreationForm(target);
		break;
	default:
		std::cout << "Error: form " << name << " doesn't exist." << std::endl;
		break;
	}
	return (ret);
}

Intern&	Intern::operator=(const Intern& original) {
	if (this != &original) {

	}
	return (*this);
}
