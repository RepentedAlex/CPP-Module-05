/// @file PresidentialPardonForm.hpp

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

#define PPF_GS 25
#define PPF_GE 5

/// @class PresidentialPardonForm
class	PresidentialPardonForm : public AForm {
public:
	/// @ brief
	PresidentialPardonForm();

	/// @brief
	/// @param target
	PresidentialPardonForm(std::string target);

	/// @brief
	/// @param original
	PresidentialPardonForm(const PresidentialPardonForm& original);

	/// @brief Destructor.
	~PresidentialPardonForm();

	/// @brief
	/// @param executor
	void					execute(Bureaucrat const& executor);

	/// @brief
	/// @return
	const std::string&		getTarget() const;

	/// @brief
	/// @param original
	/// @return
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& original);

private:
	const std::string	target_;	///<
};

#endif // !PRESIDENTIALPARDONFORM_HPP
