#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

#define BLUE	"\033[1;95m"
#define CYAN	"\033[36m"
#define YELLOW	"\033[4;33m"
#define RESET	"\033[0m"

#define PRINT_SECTION(x) \
do { \
	std::cout << std::endl << BLUE "=== " x " ===" RESET << std::endl << std::endl; \
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
	PRINT_SECTION("TESTING INTERNS");
	{
		Intern					titouan;
		AForm*	pres_pardon = NULL;
		AForm*	robo_reques = NULL;
		AForm*	shru_creati = NULL;
		AForm*	unknown_form = NULL;

		PRINT_SUBSECTION("Making forms");
		{
			PRINT_TEST("Making Presidential Pardon Form");
			{
				pres_pardon = titouan.makeForm("presidential pardon", "Lockne");
				std::cout << *pres_pardon << std::endl;
			}
			PRINT_TEST("Making Robotomy Request Form");
			{
				robo_reques = titouan.makeForm("robotomy request", "Bender");
				std::cout << *robo_reques << std::endl;
			}
			PRINT_TEST("Making Shrubbery Creation Form");
			{
				shru_creati = titouan.makeForm("shrubbery creation", "garden");
				std::cout << *shru_creati << std::endl;
			}
			PRINT_TEST("Trying to make form that doesn't exist");
			{
				unknown_form = titouan.makeForm("cerfa 2b", "M. Dubois");
				if (unknown_form != NULL) {
					std::cout << unknown_form << std::endl;
				}
			}
		}
		if (pres_pardon != NULL) {
			delete pres_pardon;
		}
		if (robo_reques != NULL) {
			delete robo_reques;
		}
		if (shru_creati != NULL) {
			delete shru_creati;
		}
		if (unknown_form != NULL) {
			delete unknown_form;
		}
	}
	return (0);
}
