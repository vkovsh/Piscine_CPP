#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Form	*Intern::makeRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
}

Form	*Intern::makeShrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

Form	*Intern::makePresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}

Form	*Intern::makeForm(std::string formName, std::string target) {
	typedef Form * (Intern::*form_func)(std::string);
	form_func prototypes[3] = {&Intern::makeRobotomyRequestForm, &Intern::makeShrubberyCreationForm, &Intern::makePresidentialPardonForm};
	std::string	names[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	for (int i = 0; i < 3; ++i) {
		if (names[i] == formName){
			form_func f = prototypes[i]; 
			return (this->*f)(target);
		}
	}
	return NULL;
}