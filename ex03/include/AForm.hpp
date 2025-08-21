/// @file AForm.hpp

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

/// @class AForm
class	AForm {
public:
	/// @brief Default constructor.
	/// @param name Name of the form (default: "Unnamed form").
	/// @param gradeToSign Minimum grade required to sign the form (default: 150).
	/// @param gradeToExec Minimum grade required to execute the form (default: 150).
	/// @throws AForm::GradeTooHighException if any grade is too high (below 1).
	/// @throws AForm::GradeTooLowException if any grade is too low (above 150).
	AForm(std::string name = "Unnamed form", unsigned int gradeToSign = 150, unsigned int gradeToExec = 150);

	/// @brief Copy constructor.
	/// @param original The Form instance to copy from.
	AForm(const AForm& original);

	/// @brief Destructor.
	virtual ~AForm();

	/// @brief Allows a bureaucrat to sign the form if their grade is sufficient.
	/// @param bureaucrat The bureaucrat attempting to sign the form.
	/// @throws Form::GradeTooLowException if the bureaucrat's grade is too low.
	void				beSigned(Bureaucrat bureaucrat);

	/// @brief
	virtual void	execute(Bureaucrat const& executor) = 0;

	/// @brief Accessor for the execution grade requirement.
	/// @return The minimum grade required to execute the form.
	unsigned int		getGradeToExec() const;

	/// @brief Accessor for the signing grade requirement.
	/// @return The minimum grade required to sign the form.
	unsigned int		getGradeToSign() const;

	/// @brief Accessor for the signed status.
	/// @return True if the form is signed, false otherwise.
	bool				getIsSigned() const;

	/// @brief Accessor for the form's name.
	/// @return A constant reference to the form's name.
	const std::string&	getName() const;

	/// @brief Assignment operator overload.
	/// @param original The Form instance to assign from.
	/// @return A reference to the assigned Form instance.
	AForm&				operator=(const AForm& original);

	/// @class GradeTooHighException
	/// @brief Exception thrown when a grade is too high (below 1).
	class	GradeTooHighException : public std::exception {
	public:
		/// @brief Returns a descriptive message of the exception.
		/// @return A pointer to a null-terminated string describing the exception.
		const char*	what() const throw();
	};

	/// @class GradeTooLowException
	/// @brief Exception thrown when a grade is too low (above 150).
	class	GradeTooLowException : public std::exception {
	public:
		/// @brief Returns a descriptive message of the exception.
		/// @return A pointer to a null-terminated string describing the exception.
		const char*	what() const throw();
	};

	/// @class FormNotSignedException
	/// @brief
	class	FormNotSignedException : public std::exception {
	public:
		/// @brief Returns a descriptive message of the exception.
		/// @return A pointer to a null-terminated string describing the exception.
		const char*	what() const throw();
	};

private:
	const std::string	name_;			///< Constant name of the Form.
	bool				isSigned_;		///< Indicates if the Form is signed.
	const unsigned int	gradeToSign_;	///< Minimum grade to sign the Form.
	const unsigned int	gradeToExec_;	///< Minimum grade to execute the Form.
};

std::ostream&	operator<<(std::ostream& o, const AForm& form);

#endif // !AFORM_HPP
