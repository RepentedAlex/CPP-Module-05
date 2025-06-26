#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

#define RRF_GS 72
#define RRF_GE 45

class RobotomyRequestForm : public AForm
{
	public:
		// Constructors
			RobotomyRequestForm();
			RobotomyRequestForm(std::string target);
			RobotomyRequestForm(const RobotomyRequestForm &original);
		// Destructors
			~RobotomyRequestForm();
		// Operator overloads
			RobotomyRequestForm &operator=(const RobotomyRequestForm &original);
		// Getters
			const std::string	getTarget() const;
		// Setters
		// Member functions
			void	beSigned(const Bureaucrat &bureaucrat);

	private:
		const std::string	_target;
		static int			_counter_rrf;
};

#endif // !ROBOTOMYREQUESTFORM_HPP
