/// @file ShrubberyCreationForm.hpp

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

#define SCF_GS 145
#define SCF_GE 137

/// @class ShrubberyCreationForm
class	ShrubberyCreationForm : public AForm {
public:
	/// @brief
	ShrubberyCreationForm();

	/// @brief
	/// @param target
	ShrubberyCreationForm(std::string target);

	/// @brief
	/// @param original
	ShrubberyCreationForm(const ShrubberyCreationForm& original);

	/// @brief Destructor.
	~ShrubberyCreationForm();

	/// @brief
	/// @param executor
	void					execute(Bureaucrat const& executor);

	/// @brief
	/// @return
	const std::string&		getTarget() const;

	/// @brief
	/// @param original
	/// @return
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& original);

private:
	const std::string	target_;	///<
};

#endif // !SHRUBBERYCREATIONFORM_HPP
