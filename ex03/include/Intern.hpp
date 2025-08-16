/// @file Intern.hpp
/// @brief

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class	AForm;

/// @class Intern
class	Intern {
public:
	Intern();
	Intern(const Intern& original);
	~Intern();

	/// @brief
	/// @param name
	/// @param target
	/// @return
	AForm*	makeForm(const std::string name, const std::string target);

	/// @brief Assignment operator overload.
	/// @param original
	/// @return
	Intern&	operator=(const Intern& original);

private:
};

#endif // !INTERN_HPP
