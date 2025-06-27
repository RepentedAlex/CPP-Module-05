#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

#include <cstdlib>
#include <iostream>

int	RobotomyRequestForm::_counter_rrf = 0;

///CONSTRUCTORS/////////////////////////////////////////////////////////////////
RobotomyRequestForm::RobotomyRequestForm() : AForm("Unnamed RRF", RRF_GS, RRF_GE), _target("Unnamed target")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("PPF", RRF_GS, RRF_GE), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &original)
{
	*this = original;
}

///DESTRUCTORS//////////////////////////////////////////////////////////////////
RobotomyRequestForm::~RobotomyRequestForm()
{

}

///OPERATOR OVERLOADS///////////////////////////////////////////////////////////
RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &original)
{
	if (this != &original)
	{
		return (*this);
	}
	return (*this);
}

///GETTERS//////////////////////////////////////////////////////////////////////
const std::string	RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

///SETTERS//////////////////////////////////////////////////////////////////////

///MEMBER FUNCTIONS/////////////////////////////////////////////////////////////
void	RobotomyRequestForm::execute(const Bureaucrat &executor)
{
	std::cout << "* Drilling noises *" << std::endl;
	if (_counter_rrf % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy on " << this->getTarget() << " has failed..." << std::endl;
	_counter_rrf++;
}
