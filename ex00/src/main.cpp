#include <iostream>

#include "Bureaucrat.hpp"

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
	std::cout << YELLOW "~ " x " ~" RESET << std::endl; \
} while (0)

#define PRINT_TEST(x) \
do { \
	std::cout << CYAN x RESET << std::endl; \
} while (0)

#define PRINT(x) do { std::cout << x << std::endl; } while (0)

int	main()
{
	{
		PRINT_SECTION("TESTING VALID");
		Bureaucrat	regis("Régis", 42);

		std::cout << regis;

		PRINT_SUBSECTION("Incrementing grade");
		regis.incrementGrade();
		std::cout << regis;

		PRINT_SUBSECTION("Decrementing grade");
		regis.decrementGrade();
		std::cout << regis;

	}

	std::cout << std::endl;

	{
		PRINT_SECTION("TESTING EXCEPTIONS");

		PRINT_SUBSECTION("Constructing with invalid grades");
		PRINT_TEST("Grade == 0 (Too high)");
		try {
			Bureaucrat	timeo("Timéo", 0);
		} catch (const Bureaucrat::GradeTooHighException& e) {
			std::cout << "Couldn't create Timéo: " << e.what() << std::endl;
		}

		PRINT_TEST("Grade == 151 (Too low)");
		try {
			Bureaucrat	cunegonde("Cunégonde", 151);
		} catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << "Couldn't create Cunégonde: " << e.what() << std::endl;
		}

		std::cout << std::endl;

		PRINT_SUBSECTION("Incrementing/Decrementing outside of acceptable range");
		Bureaucrat	melissandre("Mélissandre", 150);
		Bureaucrat	celestin("Célestin", 1);

		PRINT_TEST("Decrementing lowest grade: ");
		try {
			melissandre.decrementGrade();
		} catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << melissandre << e.what() << std::endl;
		}
		PRINT_TEST("Incrementing highest grade: ");
		try {
			celestin.incrementGrade();
		} catch (const Bureaucrat::GradeTooHighException& e) {
			std::cout << celestin << e.what() << std::endl;
		}
	}
	return (0);
}
