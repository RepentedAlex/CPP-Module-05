/// @file RobotomyRequestForm.hpp

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

#define RRF_GS 72
#define RRF_GE 45

/// @class RobotomyRequestForm
class	RobotomyRequestForm : public AForm {
public:
	/// @brief
	RobotomyRequestForm();

	/// @brief
	/// @param target
	RobotomyRequestForm(std::string target);

	/// @brief
	/// @param original
	RobotomyRequestForm(const RobotomyRequestForm& original);

	/// @brief Destructor.
	~RobotomyRequestForm();

	/// @brief
	/// @param executor
	void					execute(Bureaucrat const& executor);

	/// @brief
	/// @return
	const std::string&		getTarget() const;

	/// @brief
	/// @param original
	/// @return
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& original);

private:
	const std::string	target_;		///<
	static int			counter_rrf_;	///<
};

#endif // !ROBOTOMYREQUESTFORM_HPP
