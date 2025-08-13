#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

int	main() {
	{
		PRINT_SECTION("BUREAUCRAT TESTING VALID");
		try {
		Bureaucrat	regis("Régis", 42);

		std::cout << regis << std::endl;

		PRINT_SUBSECTION("Incrementing grade");
		regis.incrementGrade();
		std::cout << regis << std::endl;

		PRINT_SUBSECTION("Decrementing grade");
		regis.decrementGrade();
		std::cout << regis << std::endl;

		} catch (const Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << std::endl;
		} catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		PRINT_SECTION("BUREAUCRAT TESTING EXCEPTIONS");

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
			std::cout << melissandre << "Error: " << e.what() << std::endl;
		}
		PRINT_TEST("Incrementing highest grade: ");
		try {
			celestin.incrementGrade();
		} catch (const Bureaucrat::GradeTooHighException& e) {
			std::cout << celestin << "Error: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		{
			PRINT_SECTION("FORM TESTING VALID");
			Form		test("Test form", 42, 42);
			Bureaucrat	highrank("High rank bureau", 1);

			PRINT_TEST("Can sign: ");
			try {
				highrank.signForm(test);
			} catch (const Form::GradeTooLowException& e) {
				std::cout << test << e.what() << std::endl;
			}
			std::cout << test << std::endl;
		}

		std::cout << std::endl;

		{
			PRINT_SECTION("FORM TESTING EXCEPTIONS");

			PRINT_SUBSECTION("Form creation");
			PRINT_TEST("Grade to sign too low: ");
			try {
				Form	signTooLow("Form 1", 151, 42);
			} catch (const Form::GradeTooLowException& e) {
				std::cout << "Couldn't create form: " << e.what() << std::endl;
			}
			PRINT_TEST("Grade to sign too high: ");
			try {
				Form	signTooHigh("Form 2", 0, 42);
			} catch (const Form::GradeTooHighException& e) {
				std::cout << "Couldn't create form: " << e.what() << std::endl;
			}
			PRINT_TEST("Grade to exec too low: ");
			try {
				Form	execTooLow("Form 3", 42, 151);
			} catch (const Form::GradeTooLowException& e) {
				std::cout << "Couldn't create form: " << e.what() << std::endl;
			}
			PRINT_TEST("Grade to exec too high: ");
			try {
				Form	signTooHigh("Form 4", 42, 0);
			} catch (const Form::GradeTooHighException& e) {
				std::cout << "Couldn't create form: " << e.what() << std::endl;
			}

			std::cout << std::endl;

			PRINT_SUBSECTION("Signatures");
			Form	test("Test form", 42, 42);
			Bureaucrat	lowrank("Low rank bureau", 150);

			PRINT_TEST("Grade too low to sign");
			try {
				lowrank.signForm(test);
			} catch (const Form::GradeTooLowException& e) {
				std::cout << test << e.what() << std::endl;
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
