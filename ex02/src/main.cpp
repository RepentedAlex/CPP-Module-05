#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

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
	Bureaucrat	ppf_gs_low("Larbino", 26);
	Bureaucrat	rrf_gs_low("Robotino", 73);
	Bureaucrat	chief("Chief", 1);

	PRINT_TEST("Grade too low to sign Presidential Pardon Form: ");
	try
	{
		ppf_gs_low.signForm(ppf);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << ppf_gs_low << e.what() << std::endl;
	}

	std::cout << std::endl;

	PRINT_TEST("Can sign Presidential Pardon Form: ");
	try
	{
		chief.signForm(ppf);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << chief << e.what() << std::endl;
	}

	std::cout << std::endl;

	PRINT_TEST("Grade too low to sign Robotomy Request Form: ");
	try
	{
		rrf_gs_low.signForm(rrf);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << rrf_gs_low << e.what() << std::endl;
	}

	std::cout << std::endl;

	PRINT_TEST("Can sign Robotomy Request Form: ");
	try
	{
		chief.signForm(rrf);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << chief << e.what() << std::endl;
	}

	return (0);
}
