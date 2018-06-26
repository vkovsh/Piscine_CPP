#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Form	*Intern::makeForm(std::string formName, std::string target) {
	if (formName == "robotomy request") {
		return new RobotomyRequestForm(target);
	}
	else if (formName == "shrubbery creation") {
		return new ShrubberyCreationForm(target);
	}
	else if (formName == "presidential pardon") {
		return new PresidentialPardonForm(target);
	}
	return NULL;
}