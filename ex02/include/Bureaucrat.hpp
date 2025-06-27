#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>

class AForm;

class Bureaucrat
{
	public:
		// Constructors
			Bureaucrat(std::string name = "Scapegoat", unsigned int grade = 150);
			Bureaucrat(unsigned int grade);
			Bureaucrat(const Bureaucrat &original);
		// Destructors
			~Bureaucrat();
		// Operator overloads
			Bureaucrat &operator=(const Bureaucrat &original);
		// Getters
			unsigned int		getGrade() const;
			const std::string	getName() const;
		// Setters
			void				setGrade(const int grade);
		// Member functions
			void				decrementGrade();
			void				executeForm(AForm const &form);
			void				incrementGrade();
			void				signForm(AForm &form);
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
	unsigned int		_grade;
};

// Foreign overloads
	// ostream
		std::ostream	&operator<<(std::ostream &o, Bureaucrat &bureaucrat);

#endif // !BUREAUCRAT_HPP
