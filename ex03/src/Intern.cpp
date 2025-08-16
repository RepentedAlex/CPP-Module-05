#include "../include/Intern.hpp"

#include <iostream>

static std::string	possibleForms[] = {"Presidential Pardon Form", "Robotomy Request Form", "Shrubbery Creation Form"};

AForm*	Intern::makeForm(const std::string name, const std::string target) {
	int	i = 0;
	AForm*	ret = NULL;

	while (i < 3 && possibleForms[i] != name) {
		i++;
	}
	switch (i) {
	case 0:
		std::cout << "Intern creates " << name << std::endl;
		ret = new PresidentialPardonForm();
		break;
	case 1:
		std::cout << "Intern creates " << name << std::endl;
		ret = new RobotomyRequestForm();
		break;
	case 2:
		std::cout << "Intern creates " << name << std::endl;
		ret = new ShrubberyCreationForm();
		break;
	default:
		break;
	}
}
