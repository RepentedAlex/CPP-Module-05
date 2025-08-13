/// @file Form.hpp

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

/// @class Form
class	Form {
public:
	/// @brief Default constructor.
	/// @param name (Default : Unnamed form).
	/// @param gradeToSign (Default : 150).
	/// @param gradeToExec (Default : 150).
	Form(std::string name = "Unnamed form", unsigned int gradeToSign = 150, unsigned int gradeToExec = 150);

	/// @brief Copy constructor.
	/// @param original The Form instance we want to copy from.
	Form(const Form& original);

	/// @brief Destructor.
	~Form();

	/// @brief Makes the `bureaucrat` sign the Form.
	/// @param bureaucrat The Bureaucrat instance that will be used to sign the
	/// Form.
	void				beSigned(Bureaucrat bureaucrat);

	/// @brief Accessor for the gradeToExec_ attribute.
	/// @return An unsigned int.
	unsigned int		getGradeToExec() const;

	/// @brief Accessor for the gradeToSign_ attribute.
	/// @return An unsigned int.
	unsigned int		getGradeToSign() const;

	/// @brief Accessor for the isSigned_ attribute.
	/// @return A boolean.
	bool				getIsSigned() const;

	/// @brief Accessor for the name_ attribute.
	const std::string&	getName() const;

	/// @brief Assignment operator overload.
	/// @param original The Form instance that will be assigned from.
	/// @return A reference to a Form instance.
	Form&				operator=(const Form& original);

	/// @class GradeTooHighException
	class GradeTooHighException : public std::exception {
	public:
		/// @brief Returns a descriptive message of the exception as a C-Style string.
		/// @return A opinter to a null-terminated string describing the exception.
		const char*	what() const throw();
	};

	/// @class GradeTooLowException
	class GradeTooLowException : public std::exception {
	public:
		/// @brief Returns a descriptive message of the exception as a C-Style string.
		/// @return A opinter to a null-terminated string describing the exception.
		const char*	what() const throw();
	};

private:
	const std::string	name_;			///< Constant name of the Form.
	bool				isSigned_;		///< States if the Form is signed.
	const unsigned int	gradeToSign_;	///< Constant grade to sign the Form.
	const unsigned int	gradeToExec_;	///< Constant grade to execute the Form.
};

std::ostream&	operator<<(std::ostream& o, const Form& form);

#endif // !FORM_HPP
