#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

#define SCF_GS 145
#define SCF_GE 137

class ShrubberyCreationForm : public AForm
{
	public:
		// Constructors
			ShrubberyCreationForm();
			ShrubberyCreationForm(std::string target);
			ShrubberyCreationForm(const ShrubberyCreationForm &original);
		// Destructors
			~ShrubberyCreationForm();
		// Operator overloads
			ShrubberyCreationForm &operator=(const ShrubberyCreationForm &original);
		// Getters
			const std::string	getTarget() const;
		// Setters
		// Member functions
			void	execute(Bureaucrat const &executor);

	private:
		const std::string	_target;
};

#endif // !SHRUBBERYCREATIONFORM_HPP
