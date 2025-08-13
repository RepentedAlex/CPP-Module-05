#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define BLUE	"\033[1;95m"
#define CYAN	"\033[36m"
#define YELLOW	"\033[4;33m"
#define RESET	"\033[0m"

#define PRINT_SECTION(x) \
do { \
	std::cout << BLUE "=== " x " ===" RESET << std::endl; \
} while (0)


#define PRINT_SUBSECTION(x) \
do { \
	std::cout << CYAN "~ " x " ~" RESET << std::endl; \
} while (0)

#define PRINT_TEST(x) \
do { \
	std::cout << YELLOW x RESET << std::endl; \
} while (0)

#define PRINT(x) do { std::cout << x << std::endl; } while (0)

int	main()
{
	PRINT_SECTION("TESTING FORMS");
	PresidentialPardonForm	ppf("Lockne");
	RobotomyRequestForm	rrf("Malingen");
	ShrubberyCreationForm	scf("tree");
	Bureaucrat	ppf_gs_low("Larbino", 26);
	Bureaucrat	rrf_gs_low("Robotino", 73);
	Bureaucrat	scf_gs_low("Straw", 146);
	Bureaucrat	chief("Chief", 1);

	PRINT_SUBSECTION("Testing Presidential Pardon Form");
	{
		std::cout << ppf << std::endl;

		PRINT_TEST("Grade too low to sign Presidential Pardon Form: ");
		try {
			ppf_gs_low.signForm(ppf);
		} catch (const AForm::GradeTooLowException& e) {
			std::cout << ppf_gs_low << e.what() << std::endl;
		}

		std::cout << std::endl;

		PRINT_TEST("Can sign Presidential Pardon Form: ");
		try {
			chief.signForm(ppf);
		} catch (const AForm::GradeTooLowException& e) {
			std::cout << chief << e.what() << std::endl;
		}

		std::cout << std::endl;

		PRINT_TEST("Grade too low to execute Presidential Pardon Form: ");
		try {
			ppf.execute(ppf_gs_low);
		} catch (const AForm::GradeTooLowException& e) {
			std::cout << ppf_gs_low << e.what() << std::endl;
		}

		std::cout << std::endl;

		PRINT_TEST("Can execute Presidential Pardon Form: ");
		try {
			ppf.execute(chief);
		} catch (const AForm::GradeTooLowException& e) {
			std::cout << chief << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	PRINT_SUBSECTION("Testing Robotomy Request Form");
	{
		std::cout << rrf << std::endl;

		PRINT_TEST("Grade too low to sign Robotomy Request Form: ");
		try {
			rrf_gs_low.signForm(rrf);
		} catch (const AForm::GradeTooLowException& e) {
			std::cout << rrf_gs_low << e.what() << std::endl;
		}
		std::cout << std::endl;

		PRINT_TEST("Can sign Robotomy Request Form: ");
		try {
			chief.signForm(rrf);
		} catch (const AForm::GradeTooLowException& e) {
			std::cout << chief << e.what() << std::endl;
		}

		std::cout << std::endl;

		PRINT_TEST("Grade too low to execute Robotomy Request Form: ");
		try {
			rrf.execute(rrf_gs_low);
		} catch (const AForm::GradeTooLowException& e) {
			std::cout << rrf_gs_low << e.what() << std::endl;
		}

		std::cout << std::endl;

		PRINT_TEST("Can execute Robotomy Request Form: ");
		try {
			rrf.execute(chief);
		} catch (const AForm::GradeTooLowException& e) {
			std::cout << chief << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	PRINT_SUBSECTION("Testing Shrubbery Creation Form");
	{
		std::cout << scf << std::endl;

		PRINT_TEST("Grade too low to sign Shrubbery Creation Form: ");
		try {
			scf_gs_low.signForm(scf);
		} catch (const AForm::GradeTooLowException& e) {
			std::cout << scf_gs_low << e.what() << std::endl;
		}

		std::cout << std::endl;

		PRINT_TEST("Can sign Shrubbery Creation Form: ");
		try {
			chief.signForm(scf);
		} catch (const AForm::GradeTooLowException& e) {
			std::cout << chief << e.what() << std::endl;
		}
		std::cout << std::endl;

		PRINT_TEST("Grade too low to execute Shrubbery Creation Form: ");
		try {
			scf.execute(scf_gs_low);
		} catch (const AForm::GradeTooLowException& e) {
			std::cout << scf_gs_low << e.what() << std::endl;
		}

		std::cout << std::endl;

		PRINT_TEST("Can execute Shrubbery Creation Form: ");
		try {
			scf.execute(chief);
		} catch (const AForm::GradeTooLowException& e) {
			std::cout << chief << e.what() << std::endl;
		}
	}
	return (0);
}
