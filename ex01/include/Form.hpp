#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <ostream>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		// Constructors
			Form(std::string name = "Unnamed form", unsigned int gradeToSign = 150, unsigned int gradeToExec = 150);
			Form(const Form &original);
		// Destructors
			~Form();
		// Operator overloads
			Form &operator=(const Form &original);
		// Getters
			unsigned int	getGradeToExec() const;
			unsigned int	getGradeToSign() const;
			bool				getIsSigned() const;
			const std::string	getName() const;
		// Setters
			void	setIsSigned(const bool state);
		// Member functions
			void	beSigned(const Bureaucrat &bureaucrat);
		// Exceptions
			class GradeTooHighException : public std::exception
			{
				public:
					const char	*what() const throw();
			};
			class GradeTooLowException : public std::exception
			{
				public:
					const char	*what() const throw();
			};

	private:
		const std::string	_name;
		bool				_isSigned;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExec;
};

// Foreign overloads
	// ostream
		std::ostream &operator<<(std::ostream &o, const Form &form);

#endif // !FORM_HPP
