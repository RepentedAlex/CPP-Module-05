/// @file Bureaucrat.hpp

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

/// @class Bureaucrat
class	Bureaucrat {
public:
	/// @brief Default constructor
	/// @param name Name of the Bureaucrat (Default constructor will initialise
	/// attribute Bureaucrat's name_ with the value "Scapegoat").
	/// @param grade Grade of the Bureaucrat (Default constructor will
	/// initialise attribute Bureaucrat's grade_ with the value 150).
	Bureaucrat(std::string const& name = "Scapegoat", unsigned int grade = 150);

	/// @brief Constructor initialising the Bureaucrat's grade_ attribute with the
	/// value passed through the unsigned int `grade`.
	/// @param grade The grade that will be assigned to the Bureraucrat.
	Bureaucrat(unsigned int grade);

	/// @brief Copy constructor.
	/// @param original The original Bureaucrat instance we want to copy from.
	Bureaucrat(const Bureaucrat& original);

	/// @brief Destructor.
	~Bureaucrat();

	/// @brief Increase the grade_ value (Lowest grade: 150).
	void				decrementGrade();

	/// @brief Accessor for the grade_ attribute.
	/// @return An unsigned int.
	unsigned int		getGrade() const;

	/// @brief Accessor for the name_ attribute.
	/// @return A constant std::string.
	const std::string&	getName() const;

	/// @brief Decrease the grade_ value (Highest grade: 1).
	void				incrementGrade();

	/// @brief Assignment operator overload.
	/// @param original The original Bureaucrat instance we want to assign from.
	/// @return A reference to a Bureaucrat instance.
	Bureaucrat&			operator=(const Bureaucrat& original);

	/// @brief Setter for the grade_ attribute.
	/// @param grade The grade to be assigned to the grade_ attribute.
	void				setGrade(const int grade);

	/// @class GradeTooLowException
	class GradeTooLowException : public std::exception {
	public:
		/// @brief Returns a descriptive message of the exception as a C-Style string.
		/// @return A opinter to a null-terminated string describing the exception.
		const char*	what() const throw();
	};

	/// @class GradeTooHighException
	class GradeTooHighException : public std::exception {
	public:
		/// @brief Returns a descriptive message of the exception as a C-Style string.
		/// @return A opinter to a null-terminated string describing the exception.
		const char*	what() const throw();
	};

private:
	const std::string	name_;	///< Constant name of the Bureaucrat.
	unsigned int		grade_;	///< Grade of the Bureaucrat.
};

/// @brief std::ostream shift left operator overload.
/// @param o The output stream to write to.
/// @param bureaucrat The Bureaucrat object to display.
/// @return A reference to the modified output stream.
std::ostream&	operator<<(std::ostream& o, Bureaucrat& bureaucrat);

#endif // !BUREAUCRAT_HPP
