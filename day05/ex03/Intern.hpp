#ifndef INTERN_HPP
# define INTERN_HPP
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern	{
	public:
		Intern();
		~Intern();
		Form	*makeForm(std::string formName, std::string target);
};

#endif