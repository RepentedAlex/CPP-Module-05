#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

#define PPF_GS 25
#define PPF_GE 5

class PresidentialPardonForm : public AForm
{
	public:
		// Constructors
			PresidentialPardonForm();
			PresidentialPardonForm(std::string target);
			PresidentialPardonForm(const PresidentialPardonForm &original);
		// Destructors
			~PresidentialPardonForm();
		// Operator overloads
			PresidentialPardonForm &operator=(const PresidentialPardonForm &original);
		// Getters
			const std::string	getTarget() const;
		// Setters
		// Member functions
			void	beSigned(const Bureaucrat &bureaucrat);

	private:
		const std::string	_target;
};

#endif // !PRESIDENTIALPARDONFORM_HPP
