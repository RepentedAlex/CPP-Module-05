#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
		: AForm("Unnamed Shrubbery Creation Form", SCF_GS, SCF_GE),
		  target_("Unnamed target") {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
		: AForm("Shrubbery Creation Form", SCF_GS, SCF_GE),
		  target_(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& original)
		: AForm(original.getName(), original.getGradeToSign(), original.getGradeToExec()) {
	*this = original;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void	drawTree(std::fstream& file) {
file	<< "	                                                         ." << std::endl
		<< "                                              .         ;" << std::endl
		<< "                 .              .              ;%     ;;" << std::endl
		<< "                   ,           ,                :;%  %;" << std::endl
		<< "                    :         ;                   :;%;'     .," << std::endl
		<< "           ,.        %;     %;            ;        %;'    ,;" << std::endl
		<< "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl
		<< "              %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl
		<< "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl
		<< "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl
		<< "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl
		<< "                    `:%;.  :;bd%;          %;@%;'" << std::endl
		<< "                      `@%:.  :;%.         ;@@%;'" << std::endl
		<< "                        `@%.  `;@%.      ;@@%;" << std::endl
		<< "                          `@%%. `@%%    ;@@%;" << std::endl
		<< "                            ;@%. :@%%  %@@%;" << std::endl
		<< "                              %@bd%%%bd%%:;" << std::endl
		<< "                                #@%%%%%:;;" << std::endl
		<< "                                %@@%%%::;" << std::endl
		<< "                                %@@@%(o);  . '" << std::endl
		<< "                                %@@@o%;:(.,'" << std::endl
		<< "                            `.. %@@@o%::;" << std::endl
		<< "                               `)@@@o%::;" << std::endl
		<< "                                %@@(o)::;" << std::endl
		<< "                               .%@@@@%::;" << std::endl
		<< "                               ;%@@@@%::;." << std::endl
		<< "                              ;%@@@@%%:;;;." << std::endl
		<< "                          ...;%@@@@@%%:;;;;,.." << std::endl
		<< std::endl;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) {
	std::fstream	file;
	if (this->getIsSigned() == false) {
		throw AForm::FormNotSignedException();
	} if (executor.getGrade() > this->getGradeToExec()) {
		throw AForm::GradeTooLowException();
	} else {
		file.open((this->target_ + "_shrubbery").c_str(), std::fstream::out);
		if (!file) {
			/// @todo Should this be an exception ?
			std::cerr << "Couldn't open file." << std::endl;
		} else {
			drawTree(file);
		}
	}
	file.close();
}

const std::string&	ShrubberyCreationForm::getTarget() const {
	return (this->target_);
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& original) {
	if (this != &original) {
		return (*this);
	}
	return (*this);
}
