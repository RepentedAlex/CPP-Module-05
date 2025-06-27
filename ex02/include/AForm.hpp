#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <ostream>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		// Constructors
			AForm(std::string name = "Unnamed form", unsigned int gradeToSign = 150, unsigned int gradeToExec = 150);
			AForm(const AForm &original);
		// Destructors
			virtual ~AForm();
		// Operator overloads
			AForm &operator=(const AForm &original);
		// Getters
			unsigned int	getGradeToExec() const;
			unsigned int	getGradeToSign() const;
			bool				getIsSigned() const;
			const std::string	getName() const;
		// Setters
			virtual void	setIsSigned(const bool state);
		// Member functions
			void	beSigned(const Bureaucrat &bureaucrat);
			virtual void	execute(Bureaucrat const &executor) = 0;
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
		std::ostream &operator<<(std::ostream &o, const AForm &form);

#endif // !FORM_HPP
